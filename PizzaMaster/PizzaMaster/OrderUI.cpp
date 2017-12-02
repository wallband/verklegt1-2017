#include "OrderUI.h"
#include "PizzaUI.h"
#include "DrinkUI.h"
#include "Order.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

OrderUI::OrderUI()
{
    //ctor
}

OrderUI::~OrderUI()
{
    //dtor
}

void OrderUI::start_orderUI(){

     int input;
     Order order;

    while(input != 6) {

        cout << "1: Add pizza " << endl;
        cout << "2: Add drink" << endl;
        cout << "3: Add side-dish" << endl;
        cout << "4: Back to previous menu" << endl;
        cout << "5: Confirm order" << endl;
        cout << "6: Quit" << endl << endl;
        cout << "Please select" << endl;

        cout << "-> "; cin >> input;
        cout << endl;

        if(input == 1 ) {
            PizzaUI pizzaUI;
            pizzaUI.start_pizzaUI();
        }
        else if(input == 2) {
            DrinkUI drinkUI;
            drinkUI.start_drinkUI();

        }
        else if(input == 3) {


        }
        else if(input == 4) {


        }
        else if(input == 5) {


        }
        else{
            cout <<  "Invalid input, please try again " << endl << endl;
           system("CLS");
        }

    }
}
