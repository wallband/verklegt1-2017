#ifndef SALESUI_H
#define SALESUI_H
#include <iostream>
#include "PizzaUI.h"
using namespace std;
class SalesUI
{
public:
    SalesUI();
    void startUI();
    void salesui_header()
    ;
private:
    PizzaUI pizzaui;
};

#endif // SALESUI_H
