#include "MainUI.h"


MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}


void MainUI::start_mainUI(){

    cout << "o: Orders UI " << endl;
    cout << "s: Sales UI" << endl
    cout << "b: Baking UI" << endl
    cout << "a: Administration UI" << endl
    cout << "q: Quit" << endl;
    cout << "Please select" << endl;

    char input;
    cout << "-> "; cin >> input;

    if(input == 'o' || input == 'O') {
            OrderUI orderUI;
            orderUI.start_orderUI();

    }

}
