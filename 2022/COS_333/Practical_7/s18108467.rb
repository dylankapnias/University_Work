class StockItem
  attr_accessor :name
  def initialize()
    @price = 0.0
  end

  def setPrice(p)
    @price = p
  end

  def getPrice()
    raise StandardError.new "To be overridden"
  end
end

class NormalPriceStockItem < StockItem
  def getPrice()
    return @price
  end

end

class DiscountedStockItem < StockItem
  def getPrice()
    return @price * 0.9
  end
end

class Shop
  def initialize()
    @items = Array.new
  end

  def addStockItem(newStockItem, aName)
    newStockItem.name = aName
    @items.push(newStockItem)
  end

  def setPrice(aName, aPrice)
    @items.each do |i|
      if i.name === aName
        i.setPrice(aPrice)
        return
      end
    end
  end

  def getAveragePrice()
    avg = 0
    @items.each do |i|
      avg += i.getPrice()
    end

    avg = avg / @items.size
    return avg.round(2)
  end
  
  def print()
    puts "Items:"
    @items.each do |i|
      puts "#{i.name}: #{i.getPrice()}"
    end
  end
end

shop = Shop.new

for i in 1..3 do
  print "Enter name for item #{i}: "
  STDOUT.flush
  name = gets.chomp

  print "Enter price for item #{i}: "
  STDOUT.flush
  price = gets.to_f

  print "Enter type of item #{i}: "
  STDOUT.flush
  type = gets.chomp

  if type == "n"
    temp = NormalPriceStockItem.new
  elsif type == "d"
    temp = DiscountedStockItem.new
  else
    raise StandardError.new "Unacceptable type chosen"
  end

  shop.addStockItem(temp, name)
  shop.setPrice(name, price)

  puts ""
end

shop.print()
puts "\nAverage Price: #{shop.getAveragePrice}"
