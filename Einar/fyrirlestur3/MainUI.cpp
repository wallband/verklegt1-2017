#include "MainUI.h"
#include "PizzaUI.h"

#include <iostream>
using namespace std;

MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}


void MainUI::startUI() {
    char selection = '\0';

    while((selection != 'q') || (selection != 'Q')) {

        cout << "m: Make Pizza" << endl;
        cout << "w: Write" << endl;
        cout << "r: Read" << endl;
        cout << "q: Quit" << endl;
        cin >> selection;

        if(selection == 'p') {
            PizzaUI pizzaui;
            pizzaui.startUI();
        }
        if(selection == 'w') {

        }
        else if (selection == 'r') {

        }

    }
}
