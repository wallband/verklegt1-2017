#include "PizzaUI.h"
#include <iostream>
#include "Pizza.h"
#include "Topping.h"
#include "include/PizzaRepository.h"

using namespace std;

PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}

void PizzaUI::startUI() {
        char selection = '\0';

        cout << "p: Make Pizza" << endl;
        cout << "r: Read pizza" << endl;
        cin >> selection;

        if(selection == 'p') {

            int topCount;

            cout << "How many toppings?" << endl;
            cin >> topCount;

            Pizza pizza(topCount);

            for(int i = 0; i < topCount; i++) {

                Topping topping;
                cin >> topping;
                pizza.addTopping(topping);
            }
            PizzaRepository repo;
            repo.storePizza(pizza);
            cout << pizza << endl;
        }


        if(selection == 'r') {

        PizzaRepository repo;
        Pizza pizza = repo.retrivePizza();
        cout << pizza;
        cout << endl;

        }





    int topCount;

    cout << "How many toppings?" << endl;
    cin >> topCount;

    Pizza pizza(topCount);

    for(int i = 0; i < topCount; i++) {

        Topping topping;
        cin >> topping;
        pizza.addTopping(topping);
    }

    cout << pizza << endl;
}
