#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "../main.h"

class OrderRepository
{
public:
    void saveOrder(int file, vector<string> listOfItems, string phone, int pizza, int drink, int side, int total, char pizzaState);
    ///This function helps us decide if we're either making a new file or editing a old one
    string overwriteIndex(int nr, string phone, int pizza, int drink, int side, int total, char pizzaState);
    ///This function is for searching what line in the index file we should edit
    void writeToFile(int fileNr, vector<string> listOfItems, string phone, int pizza, int drink, int side, int total, char pizzaState);
    ///This function writes out to file
    int addTotalItems();
    ///We check what the total number of orders we have and adds 1 to it
    string addToIndex(string phone, int pizza, int drink, int side, int total, char pizzaState);
    ///If we have a new order than we add it to our index
    string numToString (int number);    ///A simple function to convert a integer to a string
    string whatPizzaState(char s);      ///Function to check the state of a chosen order
    /// We have a similar function in pizza-repository but for some reason it does not want to communicate with this file
    int getTotalItems();            ///Return the total number of orders
    bool readItemList(int obj);     ///Bool function the checks if we're going to read a file or not
    int readOrderList();            ///This function reads the index file and gives us general info from each order
    int orderSelect(int totalObj);  ///This function receives a chosen file and inputs the data from it
    void orderHeader();             ///Header for decoration



private:
    vector<string> readList;

};

#endif // ORDERREPOSITORY_H
