#include "MainUI.h"
#include "OrderUI.h"
#include <iostream>

using namespace std;


MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}


void MainUI::start_mainUI(){

    cout << "1: Orders UI " << endl;
    cout << "2: Sales UI" << endl;
    cout << "3: Baking UI" << endl;
    cout << "4: Administration UI" << endl;
    cout << "5: Quit" << endl << endl;
    cout << "Please select" << endl;

    char input;
    cout << "-> "; cin >> input;
    cout << endl;

    if(input == '1' || input == 'O') {
            OrderUI orderUI;
            orderUI.start_orderUI();

    }

}
