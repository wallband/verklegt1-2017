#include "Order.h"
#include "Drink.h"

#include <iostream>
#include <fstream>

using namespace std;

Order::Order()
{
    //ctor
}

Order::~Order()
{
    //dtor
}


istream& operator >>(istream& in, Order order) {


    return in;
}

ostream& operator <<(ostream& out, Order order){


    return out;
}
