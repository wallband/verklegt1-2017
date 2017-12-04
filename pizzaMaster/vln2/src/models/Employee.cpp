#include "Employee.h"

Employee::Employee(){
}
Employee::Employee(string name, unsigned long int kt) {
    this->name = name;
    this->kt = kt;

}

string Employee::get_name() {

    return this->name;

}
unsigned long int Employee::get_kt() {

    return this->kt;
}
