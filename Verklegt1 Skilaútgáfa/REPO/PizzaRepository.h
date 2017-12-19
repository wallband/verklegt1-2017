#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "../main.h"
#include "OrderRepository.h"


class PizzaRepository
{
private:
    OrderRepository OrderRepo;
    int total;
    int totalPizza;
    int totalDrink;
    int totalSides;
    string phoneNr;
    char stateOfPizza;
    vector<string> listOfToppings;  ///Vectors that include various data
    vector<string> listOfDrinks;
    vector<string> listOfSides;
    vector<string> listOfCombo;
    vector<string> comboToppings;
    vector<int> listOfToppingPrice;
    vector<int> listOfDrinkPrice;
    vector<int> listOfSidesPrice;
    vector<int> listOfComboPrice;
    vector<string> OrderList;       ///This vector contains chosen items in a order

public:
    PizzaRepository();
    void init();                    ///Initializer for the data vectors
    int numOfItems();               ///Function to check how many items we have in the Orderlist
    void input_Drinks();            ///Function to choose a specific drink and add it to the Orderlist
    void input_Sides();             ///Function to choose side-dishes and add it to Orderlist
    void input_Toppings(string str);///Function to add various toppings to a pizza
    string select_Combo(string str);///Function to choose a specific pizza combo from menu
    void orderTotal(int money);     ///Function to receive amount from chosen item and add it to the total price
    int get_Total();                ///Get the total amount for a order
    int getTotalPizza();            ///Get the total amount of pizzas
    int getTotalDrink();            ///Get the total amount of drinks
    int getTotalSides();            ///Get the total amount of side-dishes
    string getPhoneNr();            ///Get the phone number
    char getPizzaStatus();          ///Get state that the pizza is in
    string whatPizzaState(char s);  ///Check the state of the pizza and return the co-responding string
    void clearMem();                ///function that clears the vector containing ordered items
    void newTotal(int total);           ///New total that is loaded from file
    void newTotalPizza(int totalPizza); ///New total amount of pizzas loaded from file
    void newTotalDrink(int totalDrink); ///New total amount of drinks loaded from file
    void newTotalSides(int totalSides); ///New total amount of side-dishes loaded from file
    void newPhoneNr(string phoneNr);    ///New phoneNr loaded from file
    void newPizzaStatus(char pizzaState);///Pizza status that is loaded from file
    void storePizza(string pizza, int items);///Checks if we have a pizza with no additional toppings, if it is, then it's a margarita pizza
    void saveOrder(int file, string phone); ///Like the name says, we take a completed order and save it to a file
    void loadOrder(int file);               ///Here we load a chosen file and input the data it contains
    void printOrder();                      ///This function prints out the order and all of its contents
    void addVectorString(string str);       ///A chosen item gets added to the vector containing our items
    void toppingHeader();               ///Header functions for decoration
    void comboHeader();
    void drinksHeader();
    void sidesHeader();



};

#endif // PIZZAREPOSITORY_H
