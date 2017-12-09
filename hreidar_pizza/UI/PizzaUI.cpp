#include "PizzaUI.h"

PizzaUI::PizzaUI()
{
    //ctor
}

void PizzaUI::startUI(){

    char selection;
    while(selection != '5'){
        ui_Header();
        cout << "1: Add Pizza" << endl;
        cout << "2: Add Drink"<< endl;
        cout << "3: Add Side-dish" << endl;
        ///cout << "4: Delete item" << endl;
        cout << "\n5: Finish Order" << endl;
        cin >> selection;

        if(selection == '1'){

            pizza_Service.makePizza();
            cout << endl;
        }

        if(selection == '2'){

            pizza_Service.addDrink();
            cout <<endl;
        }

        if(selection == '3'){

            pizza_Service.addSide();
        }/*
        if(selection == '4'){

            pizza_Service.deleteItem();
        }*/

    }
    pizza_Service.finish_Order();
}

void PizzaUI::view_Orders(){
    order_Service.viewOrderList();
}


void PizzaUI::ui_Header(){

    system("CLS");
    cout << "-----------------------" << endl;
    cout << "          Order " << endl;
    cout << "-----------------------" << endl;
}
