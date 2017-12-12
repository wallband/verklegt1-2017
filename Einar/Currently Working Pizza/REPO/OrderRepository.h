#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "../main.h"

class OrderRepository
{
    public:
        OrderRepository();
        void saveOrder(vector<string> listOfItems, int pizza, int drink, int side, int total);
        int addTotalItems();
        string addToIndex(string phone, int pizza, int drink, int side, int total);
        string numToString (int number);
        bool readItemList(int obj);
        int getTotalItems();
        int readOrderList();
        int orderSelect(int totalObj);
        void orderHeader();



    private:

};

#endif // ORDERREPOSITORY_H
