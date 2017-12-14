#ifndef SALESUI_H
#define SALESUI_H
#include "../main.h"
#include "../UI/PizzaUI.h"

class SalesUI
{
    public:
        SalesUI();
       void startUI();
       void salesui_header();

    private:
        PizzaUI pizzaui;
};

#endif // SALESUI_H
