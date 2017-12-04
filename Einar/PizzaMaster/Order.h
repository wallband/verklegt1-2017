#ifndef ORDER_H
#define ORDER_H
#include "Drink.h"

#include <iostream>

using namespace std;

class Order
{
    public:
        Order();
        virtual ~Order();


        friend istream& operator >>(istream& in, Drink drink);
        friend ostream& operator <<(ostream& out, Drink drink);

    protected:

    private:
};

#endif // ORDER_H
