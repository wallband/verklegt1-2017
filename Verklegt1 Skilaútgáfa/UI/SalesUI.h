#ifndef SALESUI_H
#define SALESUI_H
#include <iostream>
#include "PizzaUI.h"
using namespace std;
class SalesUI
{
public:
    SalesUI();
    void startUI();         ///Starts sales user interface.
    void salesui_header()   ///Decorational header for sales interface.
    ;
private:
    PizzaUI pizzaui;
};

#endif // SALESUI_H
