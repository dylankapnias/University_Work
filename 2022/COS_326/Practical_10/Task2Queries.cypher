//Task2Queries
//1.a
// MATCH
//     p = shortestPath((Neo:Person {name:'@Neo'})-[*..10]->(n:Tweet))
// WITH
//     p,
//     length(p) AS dist
// WHERE
//     dist = 2 OR dist = 3
// RETURN
//     p
// ;

//1.b
// MATCH
//     p = shortestPath((Melanie:Person {name:'@Melanie'})-[:FOLLOWS*..10]->(Neo:Person {name:'@Neo'}))
// WITH
//     p
// RETURN
//     p
// ;

//1.c
// MATCH
//     (t)
// WHERE
//     EXISTS(()-[:TWEETED]->(t))
// RETURN
//     t.hashtag,
//     EXISTS((t)-[:RETWEETED]-()) AS isRetweeted
// ;

//1.d
// MATCH
//     p = shortestPath((Melanie:Person {name:'@Melanie'})-[:FOLLOWS*..10]->(Neo:Person {name:'@Neo'}))
// WITH
//     p
// RETURN
//     p
// ;

//2.a
// MATCH
//     (n)
// RETURN
//     count(n)
// ;

//2.b
// MATCH
//     (n:Person)-[:FOLLOWS]->(x)
// RETURN
//     n.name,
//     count(x)
// ;

//2.c
// MATCH
//     (n:Person)<-[r:FOLLOWS]-(x)
// WITH
//     n,
//     x,
//     r
// WHERE
//     r.since <= date({year: 2014})
// RETURN
//     n.name,
//     count(x)
// ;

//2.d
MATCH
    (n:Person)<-[r:FOLLOWS]-(x)
WITH
    n,
    count(r) as cnt
RETURN
    n.name,
    cnt
ORDER BY
    cnt
DESC LIMIT
    1
;