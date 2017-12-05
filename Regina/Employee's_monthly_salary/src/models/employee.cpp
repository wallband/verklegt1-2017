#include "employee.h"

Employee::Employee(string name, double SSN)
{
    this->name = name;
    this->SSN = SSN;
}
string Employee::get_name()
{
    return this->name;
}
double Employee::get_SSN()
{
    return this->SSN;
}
ostream& operator << (ostream& out, const Employee& employ)
{
    out << employ.name << ", " << employ.SSN << endl;
    return out;
}
