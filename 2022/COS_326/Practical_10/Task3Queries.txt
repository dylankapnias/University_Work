//Task3Queries
//3.4
LOAD CSV WITH HEADERS FROM "file:///persons.csv" AS csvLine
CREATE (p:Person {id: toInteger(csvLine.ID), name: csvLine.name})
;

//3.5
MATCH (n) RETURN n;

//3.6
:auto LOAD CSV WITH HEADERS FROM 'file:///follows.csv' AS csvLine
CALL {
    WITH
        csvLine
    MERGE
        (p:Person {name: csvLine.person})
    MERGE
        (f:Person {name: csvLine.follows})
    CREATE
        (p) - [:FOLLOWS] -> (f)
} IN TRANSACTIONS
;
//3.7
MATCH (n) RETURN n;