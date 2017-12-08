#include "DrinkUI.h"
#include "Drink.h"


DrinkUI::DrinkUI()
{
    //ctor
}

DrinkUI::~DrinkUI()
{
    //dtor
}

void DrinkUI::start_drinkUI() {

    char input;
    Drink drinks;

    while(input != '\0') {
        cout << "1: Add Coka Cola" << endl;
        cout << "2: Add Sprite" << endl;
        cout << "3: Add Fanta" << endl;
        cout << "4: Add Toppur" << endl;
        cout << "5: Back to previous menu" << endl;

        cout << "-> "; cin >> input;
        cout << endl;

        if(input == '1') {

            Drink Coke;
            int number_of_bottles;
            double price = 150;
            cout << "How many? " << "-> "; cin >> number_of_bottles;
            cout << endl;
            string  name = "Coke";
            Coke.set_name(name);
            Coke.set_price(price);
            Coke.set_number_of_bottles(number_of_bottles);


            drinks.add_drink(Coke);

            drinks.display_drinks();


        }
        else if(input == '2') {
            Drink Sprite;
            int number_of_bottles;
            double price = 150;
            cout << "How many? " << "-> "; cin >> number_of_bottles;
            cout << endl;
            string  name = "Sprite";
            Sprite.set_name(name);
            Sprite.set_price(price);
            Sprite.set_number_of_bottles(number_of_bottles);


            drinks.add_drink(Sprite);

            drinks.display_drinks();

        }
        else if(input == '3') {


        }
        else if(input == '4') {


        }
        else if(input == '5') {
            break;


        }
        else{
            cout <<  "Invalid input, please try again " << endl << endl;
           system("CLS");
        }


        }
}
