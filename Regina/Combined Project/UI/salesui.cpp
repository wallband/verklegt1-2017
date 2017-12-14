#include "salesui.h"

SalesUI::SalesUI()
{
    //ctor
}

void SalesUI::startUI()
{
    char input;
    salesui_header();
    cout << " 1: View orders/edit state of orders" << endl;
    cin >> input;
    if(input == '1')
    {
        pizzaui.view_OrdersSales();
    }
}
void SalesUI::salesui_header()
{
    system("CLS");
    cout << "-----------------------" << endl;
    cout << "        Sales          " << endl;
    cout << "-----------------------\n" << endl;
}
