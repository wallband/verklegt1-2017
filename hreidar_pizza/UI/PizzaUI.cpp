#include "PizzaUI.h"

PizzaUI::PizzaUI()
{
    //ctor
}

void PizzaUI::startUI(){

    char selection = '\0';
    while(selection != 'f'){
        ui_Header();
        cout << "p: Add Pizza" << endl;
        cout << "d: Add Drink"<< endl;
        //cout << "m: make pizza" << endl;
        cout << "f: Finish Order" << endl;
        cin >> selection;

        if(selection == 'd'){

            pizza_Service.addDrink();
            cout <<endl;
        }


        if(selection == 'p'){

            pizza_Service.makePizza();
            cout << endl;
        }

    }
    pizza_Service.finish_Order();
    //finishOrder();
}
/*
void PizzaUI::finishOrder(){

    system("CLS");
    cout << "----------------------------" << endl;
    cout << "     Order is finished." << endl;
    cout << "  - - - - You have - - - -" << endl;
    cout << "  n Pizza/s" << endl;
    cout << "  n Drink/s" << endl;
    cout << "" << endl;
    cout << "  The total is " << pizzaRepo.get_Total() << endl;
    cout << "----------------------------" << endl;
    system("pause");
}
*/

void PizzaUI::ui_Header(){

    system("CLS");
    cout << "-----------------------" << endl;
    cout << "          Order " << endl;
    cout << "-----------------------" << endl;
}
