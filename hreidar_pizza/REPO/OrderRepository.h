#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "../main.h"

class OrderRepository
{
    public:
        void saveOrder(int file, vector<string> listOfItems, string phone, int pizza, int drink, int side, int total);
        string overwriteIndex(int nr, string phone, int pizza, int drink, int side, int total);
        void writeToFile(int fileNr, vector<string> listOfItems, string phone, int pizza, int drink, int side, int total);
        int addTotalItems();
        string addToIndex(string phone, int pizza, int drink, int side, int total);
        string numToString (int number);
        bool readItemList(int obj);
        int getTotalItems();
        int readOrderList();
        //vector loadItemList(int nr);
        int orderSelect(int totalObj);
        void orderHeader();



    private:
        vector<string> readList;

};

#endif // ORDERREPOSITORY_H
