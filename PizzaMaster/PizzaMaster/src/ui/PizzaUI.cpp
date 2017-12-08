#include "PizzaUI.h"
#include "Pizza.h"


using namespace std;

PizzaUI::PizzaUI()
{

}

void PizzaUI::start_pizzaUI(Order& order) {

    //Pizza pizza;

    char input;

    while(true) {
        cout << "1: Make new pizza" << endl;
        cout << "2: Choose pizza from menu" << endl;
        cout << "3: Back to previous menu" << endl;

        cout << "-> "; cin >> input;
        cout << endl;

        if(input == '1') {
            make_pizza(order);
        }
        else if(input == '2') {

        }
        else if(input == '3') {

        }
        else{
            cout << "Invalid input, please try again" << endl;
        }


        }
}
void PizzaUI::make_pizza(Order& order){
    pizza_service.make_pizza(order);
}
