#include "OrderUI.h"
#include "PizzaUI.h"
#include "DrinkUI.h"
#include "Order.h"
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

OrderUI::OrderUI(){
}



void OrderUI::start_orderUI(){

     char input;
     Order order;

    while(input != '6') {

        cout << "1: Add pizza " << endl;
        cout << "2: Add drink" << endl;
        cout << "3: Add side-dish" << endl;
        cout << "4: Back to previous menu" << endl;
        cout << "5: Confirm order" << endl;
        cout << "6: Quit" << endl << endl;
        cout << "Please select" << endl;

        cout << "-> "; cin >> input;
        cout << endl;

        if(input == '1') {
            PizzaUI pizzaUI;
            pizzaUI.start_pizzaUI(order);
        }
        else if(input == '2') {
            DrinkUI drinkUI;
            drinkUI.start_drinkUI();

        }
        else if(input == 3) {


        }
        else if(input == 4) {


        }
        else if(input == 5) {


        }
        else if(input == 6) {
                cout << "Thank you, goodbyeee";
            exit (EXIT_SUCCESS);

        }
        else{
            system("CLS");
            cout <<  "Invalid input, please try again " << endl << endl;
        }

    }
}
