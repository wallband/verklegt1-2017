#ifndef BAKERUI_H
#define BAKERUI_H
#include "../main.h"
#include "PizzaUI.h"


class BakerUI
{
public:
    BakerUI();
    void startUI();             ///Starts baker user interface
    void bakerui_header();      ///Decorational header for Admin interface

private:
    PizzaUI pizzaui;
};

#endif // BAKERUI_H
