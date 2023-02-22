(:Question 1  --> //musicians/musician/name/text():)
(:Question 2  --> //musicians/musician[name='Tool']/albums/album:)
(:Question 3  --> //musicians/musician/albums[album='Lateralus']/parent::*/name/text():)
(:Question 4  --> //musicians/musician/genre[contains(text(), 'Pop')]/parent::*/name/text():)
(:Question 5  --> //musicians/musician[@type = 'solo']/name/text():)
(:Question 6  --> //musicians/musician[@type = 'solo'][position() = 2]/name | //musicians/musician[@type = 'solo'][position() = 2]/genre:)
(:Question 7  --> //musicians/musician[name = 'Ben Folds']/albums/album[position() = 4]:)
(:Question 8  --> //musicians/musician/albums/album[@year > 2008]:)
(:Question 9  --> 
for $M in //musician
let $rate := ($M/albums/album[last()]/data(@year)  - $M/albums/album[1]/data(@year) + 1) div count($M/albums/album)
order by $rate descending
return 
<RATECALC>
  <NAME>{$M/name/text()}</NAME>
  <RATE>{$rate}</RATE>
</RATECALC>:)
(:Question 10 --> Find the names of musicians with more than the average amount of words in their names
let $tot := 0
let $mult := 
<MULTI>
  {
    for $M in //musician
    let $before := string-length($M/name/text())
    let $after := string-length(translate($M/name/text(), ' ', ''))
    let $amount := $before - $after + 1
    let $tot := $tot + $amount
    return
    <RET>
      {$M/name}
      <AMOUNT>{$amount}</AMOUNT>
    </RET>
  }
</MULTI>
let $avg := fn:floor(avg($mult/RET/AMOUNT))
for $M in //$mult/RET
where $M[AMOUNT > $avg]
return $M:)

//musicians