///////////////////////////////////////////////////////////////////////////////
///////////////////////////////// TASK 1 //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
prompt = function() {
    return db + "> ";
}

createDB = function(dbName, colName) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    col.createIndex(
        {
            x: 1,
            y: 1
        }
    );
}

insertPoints = function(dbName, colName, xcount, ycount) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    for (let i = 2; i <= xcount, i <= ycount; i += 2) {
        try {
            col.insertOne(
                {
                    x: i,
                    y: i
                }
            );
        } catch (e) {
            print(e)
        }
    }
}

findNearest = function(dbName, colName, xval, yval) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    cur = col.find();
    min_dist = Number.MAX_SAFE_INTEGER;
    min_doc = null;

    while(cur.hasNext()) {
        doc = cur.next();
        dist = Math.sqrt(Math.pow((doc.x - xval), 2) + Math.pow((doc.y - yval), 2));

        if (dist < min_dist) {
            min_dist = dist;
            min_doc = doc;
        }
    }

    printjson(doc);
}

updateYVals = function(dbName, colName, threshold, incr) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    try {
        col.updateOne(
            {"y" : {$gt: threshold}},
            {$inc : {"y": incr}}
        );
    } catch (e) {
        print(e);
    }
}

removeIfYless = function(dbName, colName, threshold) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    try {
        col.remove(
            {"y" : {$lt: threshold}}
        );
    } catch (e) {
        print(e);
    }
}

// start = function() {
//     createDB("prac8db", "Cartesian");
//     insertPoints("prac8db", "Cartesian", 5, 5);
//     findNearest("prac8db", "Cartesian", 5, 7)
//     updateYVals("prac8db", "Cartesian", 2, 10);
//     removeIfYless("prac8db", "Cartesian", 4);
//     db.dropDatabase();
// }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////// TASK 2 //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// mongoimport -d=prac8db -c=zipcodes --file=zips.json

allStatesPopulation = function(dbName, colName) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    cur = col.aggregate(
        {
            $group: {
                _id: "$state",
                population: {
                    $sum: "$pop"
                }
            }
        },
        {
            $project: {
                _id: 0,
                state: "$_id",
                population: 1
            }
        },
        {
            $sort: {
                state: 1
            }
        }
    );

    while(cur.hasNext()) {
        doc = cur.next();

        printjson(doc);
    }
}

oneStatePopulation = function(dbName, colName, stateName) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    cur = col.aggregate(
        {
            $match: {
                state: stateName
            }
        },
        {
            $group: {
                _id: "$state",
                population: {
                    $sum: "$pop"
                }
            }
        },
        {
            $project: {
                _id: 0,
                state: "$_id",
                population: 1
            }
        },
        {
            $sort: {
                state: 1
            }
        }
    );

    while(cur.hasNext()) {
        doc = cur.next();

        printjson(doc);
    }
}

mapFunc = function() {
    emit(this.state, this.pop);
}

redFunc = function(stateK, popK) {
    return Array.sum(popK);
}

allStatesPopulationMR = function(dbName, colName) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    col.mapReduce(
        mapFunc,
        redFunc,
        {
            out: "states_population"
        }
    );

    col2 = db.getCollection("states_population");
    
    cur = col2.aggregate(
        {
            $project: {
                _id: 0,
                state: "$_id",
                value: 1
            }
        },
        {
            $sort: {
                state: 1
            }
        }
    );

    while(cur.hasNext()) {
        doc = cur.next();

        printjson(doc);
    }
}

placesInGrid = function(dbName, colName, lat1, lat2, lon1, lon2) {
    db = db.getMongo().getDB(dbName);
    col = db.getCollection(colName);

    cur = col.aggregate(
        {
            $project: {
                _id: 0,
                zip: "_id",
                city: 1,
                latitude: {
                    $slice: [
                        "$loc",
                        1,
                        1
                    ]
                },
                longitude: {
                    $slice: [
                        "$loc",
                        1
                    ]
                }
            }
        },
        {
            $match: {
                latitude: {
                    $elemMatch: {
                        $gt: lat1,
                        $lt: lat2
                    }
                },
                longitude: {
                    $elemMatch: {
                        $gt: lon1,
                        $lt: lon2
                    }
                }
            }
        },
        {
            $sort: {
                zip: 1
            }
        }
    );

    while(cur.hasNext()) {
        doc = cur.next();

        printjson(doc);
    }
}

// start = function() {
//     allStatesPopulation("prac8db", "zipcodes");
//     oneStatePopulation("prac8db", "zipcodes", "NY");
//     allStatesPopulationMR("prac8db", "zipcodes");
//     placesInGrid("prac8db", "zipcodes", 30, 45, -105, -75);
// }