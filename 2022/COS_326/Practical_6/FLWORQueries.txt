(:Question 1 -->
for $S in //student
return $S/name/text():)
(:Question 2 --> 
let $count := count(//student)
return $count:)
(:Question 3 --> 
let $ans := 
<ans>
  {
    for $S in //student
    where starts-with(substring($S/@module, 4), "7")
    return $S
  }
</ans>
return count($ans/student):)
(:Question 4 --> 
for $S in //student
let $name := $S/name/text()
let $age := $S/age/text()
return concat($name, ":", $age):)
(:Question 5 --> 
for $S in //student
let $name := $S/name/text()
let $age := $S/age/text()
where $age > 23
return $name:)
(:Question 6 --> 
for $S in //student
let $name := $S/name/text()
let $age := $S/age/text()
where $age < 30
order by $age descending
return $name:)
(:Question 7 --> 
for $S in //student
let $name := $S/name/text()
let $mod := $S/@module
where starts-with(substring($S/@module, 4), "3")
return concat($name, ": ", $mod):)
(:Question 8 --> 
let $avg := avg(//age)
return $avg:)
(:Question 9 --> 
for $S in //student
let $name := $S/name/text()
let $mod := $S/@module
let $age := $S/age/text()
where starts-with(substring($S/@module, 4), "3") and $age < 22
return $name:)