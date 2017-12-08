#ifndef PIZZA_SERVICE_H
#define PIZZA_SERVICE_H
#include "Order.h"



class Pizza_service
{
    public:
        Pizza_service();
        void make_pizza(Order& order);
        void validate_size(char input, string& size);
        void validate_bottom(char input, string& bottom);
        void add_topping(Pizza& pizza);


    private:
};

#endif // PIZZA_SERVICE_H
