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
        Salary(string name, string kt, int year, int month, double salary);
        Salary();
        int get_year();
        int get_month();
        double get_salary();
        string get_name();
        string get_kt();
        void set_name(string name);
        void set_kt(string kt);
        void set_year(int year);
        void set_month(int month);
        void set_salary(double salary);


        friend ostream& operator << (ostream& out, const Salary& salary);


    protected:

    private:
        int year;
        int month;
        double salary;
        string name;
        string kt;
        Employee employee;
};

#endif // SALARY_H
