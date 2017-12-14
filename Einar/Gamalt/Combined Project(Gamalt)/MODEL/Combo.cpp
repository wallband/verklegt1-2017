#include "Combo.h"


Combo::Combo()
{}
void Combo::set_name(string name)
{
    this->name = name;
}
void Combo::set_price(int price)
{
    this->price = price;
}

string Combo::get_name()
{
    return this->name;
}

int Combo::get_topping_vector_size()
{
    return list_of_toppings.size();
}
