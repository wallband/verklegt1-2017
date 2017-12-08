#ifndef ORDER_H
#define ORDER_H
#include <OrderUI.h>
#include <Pizza.h>
#include <Drink.h>
#include <On_the_side.h>

using namespace std;


class Order
{
    public:
        Order();

        vector<Pizza> pizza_vector;
        vector<Drink> drink_vector;
        vector<On_the_side> ots_vector;


    private:


};

#endif // ORDER_H
