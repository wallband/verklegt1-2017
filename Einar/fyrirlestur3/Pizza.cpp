#include "Pizza.h"
using namespace std;
Pizza::Pizza()
{
    toppingCount = 0;
    toppings = 0;
    currentToppingNum = 0;
}

Pizza::Pizza(int numberOfToppings) {
    toppingCount = numberOfToppings;
    toppings = new Topping[toppingCount];
    currentToppingNum = 0;

}

Pizza::~Pizza()
{
    if(toppings != 0) {
        delete[] toppings;
    }
}
void Pizza::addTopping(Topping topping) {

    if(currentToppingNum < toppingCount) {
    toppings[currentToppingNum] = topping;
    currentToppingNum ++;
    }

}

ostream& operator <<(ostream& out, Pizza& pizza) {

    out << "Pizza with toppings" << endl;

    for(int i = 0; i < pizza.toppingCount; i++) {
        out << pizza.toppings[i] << endl;
    }

    return out;
}

istream& operator >>(istream& in, Pizza& pizza){



    return in;
}
