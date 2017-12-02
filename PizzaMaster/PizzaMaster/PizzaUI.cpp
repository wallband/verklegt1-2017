#include "PizzaUI.h"
#include "Pizza.h"
#include <iostream>

using namespace std;

PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}

void PizzaUI::start_pizzaUI() {

    Pizza pizza;

    char input;

    while(input != '\0') {
        cout << "m: Make new pizza" << endl;
        cout << "c: Choose pizza from menu" << endl;
        cout << "b: Back to previous menu" << endl;

        cout << "-> "; cin >> input;
        cout << endl;


        }
}
