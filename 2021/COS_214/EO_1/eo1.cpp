#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
string name;
int age;
public:
Employee( string n, int a )
{
name = n;
age = a;
}
int salary ()
{
cout <<"Employee salary :" <<endl;
return 0;
}
};
class Permanent : public Employee
{
public:
Permanent( string n = "Perm", int a = 23) : Employee(n, a) { }
int salary ()
{
cout <<"Permanent employee salary :" <<endl;
return 450;
}
};
class Temporary : public Employee
{
public:
Temporary( string n = "Temp", int a = 18) : Employee(n, a) { }
int salary ()
{
cout <<"Temporary employee salary :" <<endl;
return 275;
}
};
// Main function for the program
int main() {
Employee *emp;
Permanent *perm = new Permanent("James", 31);
Temporary *temp = new Temporary("Larry", 18);
// store the address of Permanent
emp = perm;
// call Permanent salary.
emp->salary();
// store the address of Temporary
emp = temp;
// call Temporary salary.
emp->salary();
return 0;
}