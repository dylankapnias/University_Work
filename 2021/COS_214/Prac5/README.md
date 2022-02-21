# COS 214 Practical Assignment 5
- Author: Dylan Kapnias (u1810846)

## Use
- make:- The provided makefile will create the dependency files as well as compile and link the whole project. 
- make run:- This will run the binary file created in the above mentioned command.

In the Main.cpp I have created two auxillary functions that hold the code that was to be implemented in Task 5 and Task 8.

### Task 5
In the Task 5 implementation, I decided to partially emulate an actual RC remote (i.e. The user must select the RC vehicle to control, as well as the "buttons" to be pressed), thus the user will be propmted to select the correct choice based on their needs.

### Task 8
In the Task 8 implementation, I showed the use of the chain of responsibility, the only only working options that can be passed into the handleRequest() function are:- "speed" and "fly" (including the quotaion marks as they are strings).
