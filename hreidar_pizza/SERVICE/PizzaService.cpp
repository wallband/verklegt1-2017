#include "PizzaService.h"


PizzaService::PizzaService()
{
    totalPizza = 0;
    totalDrink = 0;
    pizzaRepo.init();
}

void PizzaService::makePizza(){
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
            pizzaSize = "Small Pizza: ";
            pizzaRepo.orderTotal(150);
            break;
        case '2':
            pizzaSize = "Medium Pizza: ";
            pizzaRepo.orderTotal(200);
            break;
        case '3':
            pizzaSize = "Large Pizza: ";
            pizzaRepo.orderTotal(250);
            break;
        }

        if(input == '1' || input == '2' || input == '3') break;

    }
    //pizzaRepo.addVectorString(pizzaSize);
    addPizza(pizzaSize);




}
void PizzaService::addPizza(string str){

    totalPizza++;
    pizzaRepo.input_Toppings(str);
    //system("pause");
    //pizzaRepo.storePizza();
    //system("pause");

}

void PizzaService::addDrink(){

    //totalDrink++;
    totalDrink = pizzaRepo.readDrinks();
}

void PizzaService::readPizza(){

}
void PizzaService::getPizza(){

}
void PizzaService::getListOfPizza(){

}
int PizzaService::getTotalPizza(){
    return this -> totalPizza;
}

int PizzaService::getTotalDrink(){
    return this -> totalDrink;
}

void PizzaService::finish_Order(){

    system("CLS");
    cout << "--------------------------------" << endl;
    cout << "     Order is finished." << endl;
    cout << "  - - - - - You have - - - - -" << endl;
    cout << "   " << getTotalPizza() << " Pizza/s" << endl;
    cout << "   " << getTotalDrink() << " Drink/s" << endl;
    cout << endl;
    pizzaRepo.saveOrder(); cout << endl;
    cout << endl;
    cout << "  The total is " << pizzaRepo.get_Total() << endl;
    cout << "--------------------------------" << endl;
    system("pause");
}

void PizzaService::orderHeader(){

    cout << "-----------------------" << endl;
    cout << "      Order Pizza" << endl;
    cout << "-----------------------" << endl;
    //cout << "" << endl;
    //cout << "" << endl;
    //cout << "" << endl;
}
