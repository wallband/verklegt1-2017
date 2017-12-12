#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "Drink.h"

#include <iostream>

using namespace std;


class OrderRepository
{
    public:
        OrderRepository();
        virtual ~OrderRepository();

        void write_drink(Drink drink);
    protected:

    private:
};

#endif // ORDERREPOSITORY_H
