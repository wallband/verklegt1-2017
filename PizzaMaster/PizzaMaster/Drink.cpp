#include "Drink.h"
#include <vector>
#include <iostream>

using namespace std;

Drink::Drink()
{
    //ctor
}

Drink::~Drink()
{
    //dtor
}

Drink::Drink(string name, double price, int number_of_bottles) {

    this->name = name;
    this->price = price;
    this->number_of_bottles = number_of_bottles;

}

ostream& operator <<(ostream& out, Drink drink){
    out << drink.number_of_bottles << " x " << drink.name
        << " " << drink.price * drink.number_of_bottles << " kr." << endl;

    return out;
}
istream& operator <<(istream& in, Drink drink){


    return in;
}


void Drink::add_drink(Drink drink) {

    list_of_drinks.push_back(drink);
}

void Drink::display_drinks() {

    for(unsigned int i = 0; i < list_of_drinks.size(); i++) {

        cout << list_of_drinks[i] << endl;

    }

}

void Drink::set_name(string name) {
    this->name = name;

}
void Drink::set_price(double price) {
    this->price = price;

}
void Drink::set_number_of_bottles(int number_of_bottles) {
    this->number_of_bottles = number_of_bottles;

}
