#include "car.h"

Car::Car(string manufacturer, string type, int age)
{
    this-> manufacturer = manufacturer;
    this->type = type;
    this-> age = age;
}

string Car::get_manufacturer() const
{
    return this->manufacturer;
}
string Car::get_type() const
{
    return this->type;
}
int Car::get_age() const
{
    return this->age;
}
ostream& operator << (ostream& out, const Car& car)
{
    out << car.manufacturer << ", " << car.type << ", " << car.age << endl;
    return out;
}
