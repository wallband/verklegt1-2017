#include "Topping.h"

Topping::Topping()
{
    //ctor
}
Topping::Topping(string name, double price)
{

    this -> name = name;
    this -> price = price;
}


istream& operator >> (istream& in, Topping& topping)
{

    cout << "Name:  ";
    in >> topping.name;

    cout << "Price: ";
    in >> topping.price;
    return in;
}
ostream& operator << (ostream& out, const Topping& topping)
{

    out << topping.name << " " <<topping.price;

    return out;
}
