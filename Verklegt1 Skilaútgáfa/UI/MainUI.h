#ifndef MAINUI_H
#define MAINUI_H
#include "../main.h"
#include "PizzaUI.h"
#include "AdminUI.h"
#include "BakerUI.h"
#include "SalesUI.h"


using namespace std;

class MainUI
{
public:
    MainUI();

    void startUI();     ///The user interface that contains choices for various other UI's

private:
    PizzaUI pizzaui;    ///The interface used for creating a order
    BakerUI bakerui;    ///A interface specified for the baker, with limited choices of states
    SalesUI salesui;    ///Similar interface as the baker gets, only this is intended to flag sales
    AdminUI adminui;    ///The interface for the admin to add and remove various items
};

#endif // MAINUI_H
