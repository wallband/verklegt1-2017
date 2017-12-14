#ifndef BAKERUI_H
#define BAKERUI_H
#include "../main.h"
#include "PizzaUI.h"


class BakerUI
{
public:
    BakerUI();
    void startUI();
    void bakerui_header();

private:
    PizzaUI pizzaui;
};

#endif // BAKERUI_H
