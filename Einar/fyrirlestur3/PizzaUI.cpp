#include "PizzaUI.h"
#include <iostream>
#include "Pizza.h"

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

    int topCount;

    cout << "How many toppings?" << endl;
    cin >> topCount;

    Pizza pizza(topCount);

    for(int i = 0; i < topCount; i++) {


    }

}
