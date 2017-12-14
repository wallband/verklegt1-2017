#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "../main.h"

class OrderRepository
{
public:
    void saveOrder(int file, vector<string> listOfItems, string phone, int pizza, int drink, int side, int total, char pizzaState);
    string overwriteIndex(int nr, string phone, int pizza, int drink, int side, int total, char pizzaState);
    void writeToFile(int fileNr, vector<string> listOfItems, string phone, int pizza, int drink, int side, int total, char pizzaState);
    int addTotalItems();
    string addToIndex(string phone, int pizza, int drink, int side, int total, char pizzaState);
    string numToString (int number);
    string whatPizzaState(char s);
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
