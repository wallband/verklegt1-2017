#include "Salary.h"

Salary::Salary(Employee& employee, int year, int month, double salary) {
    this->name = employee.get_name();
    this->kt = employee.get_kt();
    this->year = year;
    this->month = month;
    this->salary = salary;

}
Salary::Salary(string name, string kt, int year, int month, double salary) {
    this->name = name;
    this->kt = kt;
    this->year = year;
    this->month = month;
    this->salary = salary;

}
Salary::Salary(){
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
    return this->name;
}

string Salary::get_kt() {
    return this->kt;
}

ostream& operator << (ostream& out, const Salary& salary) {
    out << "Name: " << salary.name << endl
        << "Kennitala: " << salary.kt << endl
        << "Year; " << salary.year << endl
        << "Month: " << salary.month << endl
        << "Salary: " << fixed << setprecision(3) << salary.salary << "kr" << endl;
    return out;
}

void Salary::set_name(string name) {
    this->name = name;

}
void Salary::set_kt(string kt) {
    this->kt = kt;
}
void Salary::set_year(int year) {
    this->year = year;
}
void Salary::set_month(int month) {
    this->month = month;
}
void Salary::set_salary(double salary) {
    this->salary = salary;
}
