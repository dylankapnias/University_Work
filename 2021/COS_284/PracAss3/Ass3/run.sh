#TASK 1
echo "
Testing task 1
" >output.txt

declare -a sentence=("hello world" "the quick brown fox jumps over the lazy dog" "" "this is just a thing that i am testing")

for curr in "${sentence[@]}"
do
#echo "sentence being tested $curr">>output.txt
for i in $(seq -f "%02g" 0 25)
do
#echo "shift of $i">>output.txt
echo "$i
$curr" | ./task1 | tee -a output.txt
echo "" >>output.txt
done

done

#TASK 2
echo "
Testing task 2 does not matter strings dont make sense
" >>output.txt

for curr in "${sentence[@]}"
do

#echo "sentence being tested $curr">>output.txt

for i in $(seq -f "%02g" 0 25)
do
#echo "shift of $i">>output.txt

echo "$i
$curr" | ./task2 | tee -a output.txt
echo "" >>output.txt
done

done

#TASK 3

echo "Testing task 3" >>output.txt

declare -a sentence=("Hello World!" "the quick brown fox jumps over the lazy dog" "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG!" "" "Message for you SIR.!")
for curr in "${sentence[@]}"
do
#echo "sentence being tested $curr">>output.txt
for i in $(seq -f "%02g" 0 25)
do
#echo "shift of $i">>output.txt
echo "$i
$curr" | ./task3 | tee -a output.txt
echo "" >>output.txt
done

done

