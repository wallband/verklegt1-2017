#ifndef SALARY_H
#define SALARY_H
#include <iostream>

using namespace std;

class Salary
{
    public:
        Salary(double salary, int month, int year);
        double get_salary();
        int get_month();
        int get_year();

        friend ostream& operator << (ostream& out, const Salary& salary);

    private:
        double salary;
        int month;
        int year;
};

#endif // SALARY_H
