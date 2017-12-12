#ifndef TOPPING_H
#define TOPPING_H
#include "../main.h"
#include "../UI/PizzaUI.h"


class Topping
{
    public:
        Topping();
        Topping(string name, double price);

        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out, const Topping& topping);


    private:
        string name;
        double price;
        int quantity;
};

#endif // TOPPING_H
