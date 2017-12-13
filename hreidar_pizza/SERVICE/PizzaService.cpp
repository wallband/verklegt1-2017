#include "PizzaService.h"


PizzaService::PizzaService()
{
    pizzaRepo.init();
}

void PizzaService::makePizza(){

    addPizza(pizzaStart());

}
void PizzaService::loadPizza(int fileNr){

    pizzaRepo.loadOrder(fileNr);
}

string PizzaService::pizzaStart(){

    char input;
    string pizzaSize = "";
    system("CLS");
    while(input != '1' || input != '2' || input != '3'){

        orderHeader();
        cout <<"What size of Pizza?" << endl;
        cout <<"-------------------" << endl;
        cout <<"1: Small Pizza" << endl;
        cout <<"2: Medium Pizza" << endl;
        cout <<"3: Large Pizza" << endl;
        cin >> input;

        switch(input){
        case '1':
            pizzaSize = "Small Pizza, ";
            pizzaRepo.orderTotal(150);
            break;
        case '2':
            pizzaSize = "Medium Pizza, ";
            pizzaRepo.orderTotal(200);
            break;
        case '3':
            pizzaSize = "Large Pizza, ";
            pizzaRepo.orderTotal(250);
            break;
        }

        if(input == '1' || input == '2' || input == '3') break;

    }
    return pizzaType(pizzaSize);
}

string PizzaService::pizzaType(string str){

    char input;
    string pizzaType = str;
    system("CLS");
    while(input != '1' || input != '2' || input != '3'){

        orderHeader();
        cout <<"What type of Pizza-crust?" << endl;
        cout <<"-------------------------" << endl;
        cout <<"1: Thin Italian" << endl;
        cout <<"2: Normal" << endl;
        cout <<"3: Deep-dish" << endl;
        cin >> input;

        switch(input){
        case '1':
            pizzaType += "Thin Italian: ";
            pizzaRepo.orderTotal(125);
            break;
        case '2':
            pizzaType += "Normal: ";
            pizzaRepo.orderTotal(150);
            break;
        case '3':
            pizzaType += "Deep-dish: ";
            pizzaRepo.orderTotal(250);
            break;
        }

        if(input == '1' || input == '2' || input == '3') break;

    }
    return pizzaType;

}
void PizzaService::addPizza(string str){

    char selection;
    system("cls");
    orderHeader();
    cout << "What kind of pizza do you want?\n" << endl;
    cout << "1: Custom pizza" << endl;
    cout << "2: Pizza from menu" << endl;
    cin >> selection;
    if(selection == '1'){
        pizzaRepo.input_Toppings(str);
    }

    else if(selection == '2'){
        //system("pause");
        string combo = pizzaRepo.select_Combo(str);
        if(combo != ""){
            pizzaRepo.addVectorString(combo);
        }
        else{
            addPizza(str);
        }
        //cout << "Menu is broken :(" << endl;
        //system("pause");
    }

    else{
        addPizza(str);
    }

}

void PizzaService::addDrink(){

    pizzaRepo.input_Drinks();
}

void PizzaService::addSide(){

    pizzaRepo.input_Sides();
}


int PizzaService::finish_Order(int file){

    string phoneNr = "";
    char selection;
    int confirm;
    bool done = false;
    system("CLS");
    if(pizzaRepo.numOfItems() == 0){
        cout << "--------------------------------" << endl;
        cout << "     Order is finished." << endl;
        cout << "  - - - - - You have - - - - -" << endl;
        cout << "\n\t   NOTHING!!!\n" << endl;
        cout << "--------------------------------" << endl;
        system("pause");
        return 0;
    }
    else{
        string state = pizzaRepo.whatPizzaState(pizzaRepo.getPizzaStatus());
        cout << "--------------------------------" << endl;
        cout << "     Order is finished." << endl;
        cout << "  - - - - - You have - - - - -" << endl;
        cout << "   " << pizzaRepo.getTotalPizza() << " Pizza/s" << endl;
        cout << "   " << pizzaRepo.getTotalDrink() << " Drink/s" << endl;
        cout << "   " << pizzaRepo.getTotalSides() << " Side-dish/es" << endl;
        cout << endl;
        pizzaRepo.printOrder();
        cout << endl;
        cout << endl;
        cout << "  The total is " << pizzaRepo.get_Total() << endl;
        cout << "--------------------------------" << endl;
        cout << "  Pizza is "<< state << endl;
        do{
            cout << "Confirm order?" << endl;
            cout << "1: Yes" << endl;
            cout << "2: No" << endl;
            cin >> selection;
            if(selection == '1'){
                cout << "\tEnter phone-number:";
                cin >> phoneNr;

                //cout << "Save incoming" << endl;
                //system("pause");
                confirm = 0;
                pizzaRepo.saveOrder(file, phoneNr);
                done = true;
            }
            if(selection == '2'){
                confirm = 1;
                done = true;
            }

        }while(!done);

        return confirm;
    }
}
void PizzaService::clearMem(){
    pizzaRepo.clearMem();
}
void PizzaService::initVector(){
    pizzaRepo.init();
}
void PizzaService::changePizzaState(){
    char selection;
    orderService.state_header();
    cout << " - Please choose a state for this order" << endl;
    cout << "                   owner: " << pizzaRepo.getPhoneNr() <<endl;
    cout << "1: In preperation" << endl;
    cout << "2: In Oven" << endl;
    cout << "3: Ready" << endl;
    cout << "4: Paid" << endl;
    cin >> selection;
    if(selection == '1'){
        pizzaRepo.newPizzaStatus('1');
    }
    else if(selection == '2'){
        pizzaRepo.newPizzaStatus('2');
    }
    else if(selection == '3'){
        pizzaRepo.newPizzaStatus('3');
    }
    else if(selection == '4'){
        pizzaRepo.newPizzaStatus('4');
    }
    else{
        changePizzaState();
    }
}

void PizzaService::orderHeader(){

    cout << "-----------------------" << endl;
    cout << "      Order Pizza" << endl;
    cout << "-----------------------" << endl;
}
