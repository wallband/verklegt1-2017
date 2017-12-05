#include "salary.h"

Salary::Salary(double salary, int month, int year)
{
    this->salary = salary;
    this->year = year;
}
double Salary::get_salary()
{
    return this->salary;
}
int Salary::get_month()
{
    return this->month;
}
int Salary::get_year()
{
    return this->year;
}

ostream& operator << (ostream& out, const Salary& salary)
{
    out << "Salary: " << salary.salary << ", " <<
    "Month: " << salary.month << ", " <<
    "Year: " << salary.year << endl;
    return out;
}
