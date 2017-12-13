#ifndef PIZZA_H
#define PIZZA_H

#include "../main.h"
#include "Topping.h"
#include "../UI/PizzaUI.h"


//using namespace std;
class Pizza
{
public:
    Pizza();

    void addTopping();

    friend istream& operator >> (istream& in, Pizza& pizza);
    friend ostream& operator << (ostream& out,const Pizza& pizza);

private:
    //vector<Topping> toppings;

};

#endif // PIZZA_H
