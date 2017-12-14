#include "BakerUI.h"

BakerUI::BakerUI()
{}

void BakerUI::startUI()
{
    char input;
    bakerui_header();
    cout << " 1: View orders/edit state of orders" << endl;
    cin >> input;
    if(input == '1')
    {
        pizzaui.view_Orders();
    }
}
void BakerUI::bakerui_header()
{
    system("CLS");
    cout << "-----------------------" << endl;
    cout << "        Baker          " << endl;
    cout << "-----------------------\n" << endl;
}
