#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "../main.h"

class OrderRepository
{
    public:
        OrderRepository();
        void saveOrder();
        int readOrderList();
        int orderSelect(int totalObj);
        void orderHeader();



    private:

};

#endif // ORDERREPOSITORY_H
