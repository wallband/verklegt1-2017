#include "PizzaUI.h"

void PizzaUI::initVector(){
    pizza_Service.initVector();
}

void PizzaUI::startUI(){

    selectItems();

    if(pizza_Service.finish_Order(0) == 1){
        startUI();
    }
    else{
        pizza_Service.clearMem();
    }

}

void PizzaUI::contUI(int fileNr){

    //int file = fileNr;

    pizza_Service.loadPizza(fileNr);

    //startUI();
    selectItems();
    if(pizza_Service.finish_Order(fileNr) == 1){
        startUI();
    }
    else{
        pizza_Service.clearMem();
    }
}

void PizzaUI::selectItems(){

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
        }
    }
}

void PizzaUI::view_Orders(){
    int selection = order_Service.viewOrderList();
    if(selection > 0){
        //cout << "selected item: " << selection << endl;
        //system("pause");
        //contUI(selection);
        order_Operations(selection);
    }/*
    else{
        cout << "no selection" <<endl;
        system("pause");
    }*/
}
void PizzaUI::order_Operations(int selection){
    int s = selection;
    char select;
    system("cls");
    pizza_Service.orderHeader();
    cout << "1: Add item to order" << endl;
    cout << "2: Change state of order" << endl;
    cout << "3: Cancel" << endl;
    cin >> select;
    if(select == '1'){
        contUI(selection);
    }
    else if(select == '2'){
        pizza_Service.loadPizza(selection);
        pizza_Service.changePizzaState();
        pizza_Service.finish_Order(s);
    }
    else if(select == '3'){
        view_Orders();
    }
    else{
        order_Operations(s);
    }

}


void PizzaUI::ui_Header(){

    system("CLS");
    cout << "-----------------------" << endl;
    cout << "          Order " << endl;
    cout << "-----------------------" << endl;
}

void PizzaUI::admin_Header(){

    system("cls");
    cout << "---------------------------" << endl;
    cout << "       Admin settings " << endl;
    cout << "---------------------------\n" << endl;
}
