#include "Topping.h"


Topping::Topping(){
}

string Topping::get_name() {
    return this->name;
}
int Topping::get_price(){
    return this->price;
}

void Topping::set_name(string new_name){
    this->name = new_name;
}
void Topping::set_price(int new_price){
    this->price = new_price;
}
                                      ///are currently working on ordering.
