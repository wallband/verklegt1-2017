#include "Salary.h"

Salary::Salary(Employee& employee, int year, int month, double salary) {
    this->name = employee.get_name();
    this->kt = employee.get_kt();
    this->year = year;
    this->month = month;
    this->salary = salary;

}

int Salary::get_year() {
    return this->year;
}

int Salary::get_month() {
    return this->month;
}

double Salary::get_salary() {
    return this->salary;
}

string Salary::get_name() {
    return this->employee.get_name();
}

unsigned long int Salary::get_kt() {
    return this->employee.get_kt();
}

ostream& operator << (ostream& out, const Salary& salary) {
    out << "Name: " << salary.name << endl
        << "Kennitala: " << salary.kt << endl
        << "Year; " << salary.year << endl
        << "Month: " << salary.month << endl
        << "Salary: " << fixed << setprecision(3) << salary.salary << "kr" << endl;
    return out;
}
