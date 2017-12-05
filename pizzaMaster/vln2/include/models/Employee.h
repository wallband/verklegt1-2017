#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Employee_Service.h"
#include <iostream>
#include <string>

using namespace std;


class Employee
{
    public:
        Employee();
        Employee(string name, unsigned long int kt);
        string get_name();
        unsigned long int get_kt();


    private:
        string name;
        unsigned long int kt;
};

#endif // EMPLOYEE_H
