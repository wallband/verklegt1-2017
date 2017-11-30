#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include <iostream>

class Pizza
{
    public:
        Pizza();
        Pizza(int numberOfToppings);
        virtual ~Pizza();

        void addTopping(Topping topping);

        friend ostream& operator <<(ostream& out, Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);

    protected:

    private:
        Topping *toppings;
        int toppingCount;
        int currentToppingNum;
};

#endif // PIZZA_H
