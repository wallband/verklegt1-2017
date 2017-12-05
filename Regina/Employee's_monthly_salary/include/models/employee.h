#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include <iostream>
using namespace std;

class Employee
{
    public:
        Employee(string name, double SSN);
        string get_name();
        double get_SSN();

        friend ostream& operator << (ostream& out, const Employee& employ);

    private:
        string name;
        double SSN;
};

#endif // EMPLOYEE_H
