#! /bin/bash

# redirect all the compile output to stderr and stop if the compile step fails
make task1 1>&2 > /dev/null
compiled=$?

if [[ $compiled -ne 0 ]]; then
    echo "Task 1 COMPILE FAILED"
    exit $compiled
fi

make task2 1>&2 > /dev/null
compiled=$?

if [[ $compiled -ne 0 ]]; then
    echo "Task 2 COMPILE FAILED"
    exit $compiled
fi

make task3 1>&2 > /dev/null
compiled=$?

if [[ $compiled -ne 0 ]]; then
    echo "Task 3 COMPILE FAILED"
    exit $compiled
fi
# execute the compiled binary and redirect all output to stdout

echo "54321" | ./task1 2>&1
echo "15345" | ./task1 2>&1
echo "11111" | ./task1 2>&1
echo "23232" | ./task1 2>&1
echo "98765" | ./task1 2>&1
echo "v" | ./task2 2>&1
echo "w" | ./task2 2>&1
echo "q" | ./task2 2>&1
echo "t" | ./task2 2>&1
echo "i" | ./task2 2>&1
echo "1
1" | ./task3 2>&1
echo "4
5" | ./task3 2>&1
echo "3
4" | ./task3 2>&1
echo "1
2" | ./task3 2>&1
echo "9
0" | ./task3 2>&1

# Expected output below
# ============================
# Please input a 5 digit number: This is the number you are looking for: 54321
# Please input a 5 digit number: This is the number you are looking for: 15345
# Please input a 5 digit number: This is the number you are looking for: 11111
# Please input a 5 digit number: This is the number you are looking for: 23232
# Please input a 5 digit number: This is the number you are looking for: 98765
# Please input a lowercase character: In uppercase: V
# Please input a lowercase character: In uppercase: W
# Please input a lowercase character: In uppercase: Q
# Please input a lowercase character: In uppercase: T
# Please input a lowercase character: In uppercase: I
# Please input the first number: Please input the second number: 2
# Please input the first number: Please input the second number: 9
# Please input the first number: Please input the second number: 7
# Please input the first number: Please input the second number: 3
# Please input the first number: Please input the second number: 9