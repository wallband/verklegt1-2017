#ifndef MAINUI_H
#define MAINUI_H
#include "../main.h"
#include "PizzaUI.h"
#include "AdminUI.h"

//#include <iostream>
//#include <vector>

using namespace std;

class MainUI
{
public:
    MainUI();

    void startUI();

private:
    PizzaUI pizzaui;
};

#endif // MAINUI_H
