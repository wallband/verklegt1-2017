#include "DrinkUI.h"
#include "Drink.h"
#include "OrderUI.h"
#include <iostream>

using namespace std;

DrinkUI::DrinkUI()
{
    //ctor
}

DrinkUI::~DrinkUI()
{
    //dtor
}

void DrinkUI::start_drinkUI() {

    int input;
    Drink drinks;

    while(input != '\0') {

        cout << "\t" " -- Drink UI --  " << endl;
        cout << "1: Add Coka Cola" << endl;
        cout << "2: Add Sprite" << endl;
        cout << "3: Add Fanta" << endl;
        cout << "4: Add Toppur" << endl;
        cout << "5: Back to previous menu" << endl;

        cout << "-> "; cin >> input;
        cout << endl;

        if(input == 1) {

            Drink Coke;

            drinks.add_drink(Coke);

            drinks.display_drinks();
            drinks.show_vector_size(drinks);
            cout << endl;


        }
        else if(input == 2) {
            Drink Sprite;

            drinks.add_drink(Sprite);

            drinks.display_drinks();

        }
        else if(input == 3) {

            Drink Fanta;

            drinks.add_drink(Fanta);

            drinks.display_drinks();
        }
        else if(input == 4) {
            Drink Toppur;

            drinks.add_drink(Toppur);

            drinks.display_drinks();

        }
        else if(input == 5) {
            OrderUI orderUI;
            orderUI.start_orderUI();


        }
        else{
            cout <<  "Invalid input, please try again " << endl << endl;
           system("CLS");
        }


        }
}
