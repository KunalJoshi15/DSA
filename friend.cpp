#include<bits/stdc++.h>
using namespace std;

class Printer{
    public:
        void printEmp(const Employee &e);
};
// Here inside the Printer class that function is also defined and inside the Employee class it is written that the function itself is a friend
class Employee{
    private:
        int is;
        string name;
    public:
        friend void Printer::printEmp(const Employee &e);
        Employee(int i,string n):is(i),name(n){}
};

void Printer::printEmp(const Employee &e)
{
    cout<<e.is<<e.name;    
}

// The particular function is said to be the friend of one member
// Therefore the printer class can access most of the private variables which are required.
// friend class Printer; this is used to define the friend class it is defined inside the public access 
// specifier.