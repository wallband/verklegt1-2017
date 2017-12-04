#ifndef SALARY_H
#define SALARY_H
#include "Employee.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


class Salary
{
    public:
        Salary(Employee& employee, int year, int month, double salary);
        int get_year();
        int get_month();
        double get_salary();
        string get_name();
        unsigned long int get_kt();

        friend ostream& operator << (ostream& out, const Salary& salary);


    protected:

    private:
        int year;
        int month;
        double salary;
        string name;
        unsigned long int kt;
        Employee employee;
};

#endif // SALARY_H
