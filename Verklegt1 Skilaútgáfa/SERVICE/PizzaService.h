#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "../main.h"
#include "../REPO/PizzaRepository.h"
#include "DrinkService.h"
#include "OrderService.h"

class PizzaService
{
public:
    PizzaService();
    void makePizza();           ///This function receives a string for pizza-size and type and sends it to a function that inputs the toppings
    void loadPizza(int fileNr); ///Function to load a specific fileNr
    string pizzaStart();            ///These functions construct the beginning of the pizza
    string pizzaType(string str);
    void addPizza(string str);      ///This function is the receiver for the previous two functions
    void addDrink();            ///Functions for adding drinks and side-dishes
    void addSide();
    void changePizzaState();        ///This function is to change the state of any order
    void changePizzaStateBaker();   ///Similar to the previous function but these two have limited number of states
    void changePizzaStateSales();
    int finish_Order(int file);
    void inputPhone();          ///This function receives a phone-number from user and validates it
    void clearMem();            ///This function deletes the contents of the vector containing ordered items
    void initVector();          ///Initializer for data vectors
    void orderHeader();         ///Order header for decoration


private:

    PizzaRepository pizzaRepo;
    OrderService orderService;
};

#endif // PIZZASERVICE_H
