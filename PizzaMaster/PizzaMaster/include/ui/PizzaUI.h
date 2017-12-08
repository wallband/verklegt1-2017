#ifndef PIZZAUI_H
#define PIZZAUI_H
#include "Order.h"
#include "Pizza_service.h"


class PizzaUI
{
    public:
        PizzaUI();
        void start_pizzaUI(Order& order);
        void make_pizza(Order& order);

    private:
        Pizza_service pizza_service;



};

#endif // PIZZAUI_H
