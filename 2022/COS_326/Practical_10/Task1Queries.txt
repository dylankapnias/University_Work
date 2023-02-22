//Task1Queries
//i.
//Person nodes
CREATE
    (Thandi:Person {name:'@Thandi', from:'Durban', age:20}),
    (Johan:Person {name:'@Johan', from:'Pretoria', age:19}),
    (Neo:Person {name:'@Neo', from:'Tshwane', age:22}),
    (Melanie:Person {name:'@Melanie', from:'Joburg', age:21})

//FOLLOWS relationships
CREATE
    (Thandi) - [:FOLLOWS {since:2014}] -> (Johan),
    (Thandi) - [:FOLLOWS {since:2011}] -> (Neo),
    (Johan) - [:FOLLOWS {since:2012}] -> (Thandi),
    (Neo) - [:FOLLOWS {since:2016}] -> (Thandi),
    (Neo) - [:FOLLOWS {since:2016}] -> (Melanie),
    (Melanie) - [:FOLLOWS {since:2012}] -> (Johan),
    (Melanie) - [:FOLLOWS {since:2012}] -> (Thandi)
;

//ii.
MATCH (n) RETURN n;

//iii.
//Tweet nodes
CREATE
    (Trees:Tweet {hashtag:'#Trees', message:'provide oxygen'}),
    (Rhinos:Tweet {hashtag:'#Rhinos', message:'are innocent'})
;

//TWEETED relationships
MATCH
    (Thandi:Person {name:'@Thandi', from:'Durban', age:20}),
    (Johan:Person {name:'@Johan', from:'Pretoria', age:19}),
    (Neo:Person {name:'@Neo', from:'Tshwane', age:22}),
    (Melanie:Person {name:'@Melanie', from:'Joburg', age:21}),
    (Trees:Tweet {hashtag:'#Trees', message:'provide oxygen'}),
    (Rhinos:Tweet {hashtag:'#Rhinos', message:'are innocent'})
CREATE
    (Thandi) - [:TWEETED {date:'20-08-2018'}] -> (Trees),
    (Neo) - [:TWEETED {date:'05-09-2018'}] -> (Rhinos)

//RETWEETED relationships
CREATE
    (Johan) - [:RETWEETED {date:'20-08-2018'}] -> (Trees)

//FAVORITED relationships
CREATE
    (Melanie) - [:FAVORITED {date:'05-09-2018'}] -> (Rhinos)
;

//iv.
MATCH (n) RETURN n;