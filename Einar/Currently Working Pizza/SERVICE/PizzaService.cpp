#include "PizzaService.h"


PizzaService::PizzaService()
{
    pizzaRepo.init();
}

void PizzaService::makePizza()
{

    addPizza(pizzaStart());

}

string PizzaService::pizzaStart()
{

    char input;
    string pizzaSize = "";
    system("CLS");
    while(input != '1' || input != '2' || input != '3')
    {

        orderHeader();
        cout <<"What size of Pizza?" << endl;
        cout <<"-------------------" << endl;
        cout <<"1: Small Pizza" << endl;
        cout <<"2: Medium Pizza" << endl;
        cout <<"3: Large Pizza" << endl;
        cin >> input;

        switch(input)
        {
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

string PizzaService::pizzaType(string str)
{

    char input;
    string pizzaType = str;
    system("CLS");
    while(input != '1' || input != '2' || input != '3')
    {

        orderHeader();
        cout <<"What type of Pizza-crust?" << endl;
        cout <<"-------------------------" << endl;
        cout <<"1: Thin Italian" << endl;
        cout <<"2: Normal" << endl;
        cout <<"3: Deep-dish" << endl;
        cin >> input;

        switch(input)
        {
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
void PizzaService::addPizza(string str)
{

    pizzaRepo.input_Toppings(str);

}

void PizzaService::addDrink()
{

    pizzaRepo.input_Drinks();
}

void PizzaService::addSide()
{

    pizzaRepo.input_Sides();
}


/*
void PizzaService::deleteItem(){

    pizzaRepo.removeItem();
}
*/

void PizzaService::finish_Order()
{

    system("CLS");
    if(pizzaRepo.numOfItems() == 0)
    {
        cout << "--------------------------------" << endl;
        cout << "     Order is finished." << endl;
        cout << "  - - - - - You have - - - - -" << endl;
        cout << "\n\t   NOTHING!!!\n" << endl;
        cout << "--------------------------------" << endl;
    }
    else
    {
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
        system("pause");
        pizzaRepo.saveOrder();
        cout << "Save incoming" << endl;
    }

    system("pause");
}

void PizzaService::orderHeader()
{

    cout << "-----------------------" << endl;
    cout << "      Order Pizza" << endl;
    cout << "-----------------------" << endl;
}
