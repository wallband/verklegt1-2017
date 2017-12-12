#include "Pizza.h"

Pizza::Pizza()
{

}

void Pizza::addTopping(){

    //toppings.push_back(topping);
}

istream& operator >> (istream& in, Pizza& pizza){

    return in;
}

ostream& operator << (ostream& out,const Pizza& pizza){



    return out;
}
