#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "../main.h"
#include "../SERVICE/PizzaService.h"
#include "../REPO/PizzaRepository.h"
#include "../SERVICE/OrderService.h"



class PizzaUI
{
public:
    void initVector();          ///Initializer for the various data vectors
    void startUI();             ///This function is for when we make a new order
    void contUI(int fileNr);    ///This function works similar to the previous one only it uses a specific fileNr that the user chooses
    void selectItems();         ///Both previous two functions use this to select various items for a order
    void view_Orders();         ///Function that checks if a user wants to edit a specific order
    void view_OrdersBaker();    ///The next two do the same but are intended for a baker and salesperson, respectively
    void view_OrdersSales();
    void order_Operations(int selection);       ///For a chosen order we have various available options
    void order_OperationsBaker(int selection);  ///The next two functions work similarly but with limited number of states to choose
    void order_OperationsSales(int selection);
    void ui_Header();           ///Header functions for a little decoration
    void admin_Header();

private:
    PizzaService pizza_Service;
    OrderService order_Service;
    //PizzaRepository pizzaRepo;
};

#endif // PIZZAUI_H
