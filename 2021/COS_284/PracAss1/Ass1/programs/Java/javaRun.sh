#!/bin/bash

for i in {1..50}; do
    startTime=$(date +%s.%N)

    for j in {1..500}; do
    java hello.java
    done   

    endTime=$(date +%s.%N)

    totalTime=$(python -c "print(${endTime} - ${startTime})")
    echo "$totalTime" >> javaTime.txt
done