#include "Topping.h"
#include <string.h>
#include <iostream>


using namespace std;


Topping::Topping()
{
    //ctor
}

Topping::Topping(char *name, double price){
    strcpy(this->name, name);
    this->price = price;

}


Topping::~Topping()
{
    //dtor
}

istream& operator >>(istream& in, Topping& topping) {

    //cout << "Name: ";
    in >> topping.name;

    //cout << "Price: ";
    in >> topping.price;

    return in;
}

ostream& operator <<(ostream& out, Topping& topping) {

   out << topping.name << " " << topping.price;

    return out;
}
