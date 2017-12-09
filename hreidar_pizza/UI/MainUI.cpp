#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::startUI(){

    char selection = '\0';



    while(selection != '3'){
    system("CLS");

    cout << "            ...WELCOME TO..."                  << endl;
    cout << "-------------------------------------------"   << endl;
    cout << "  ____    _   ______   ______     __ "         << endl;
    cout << " |  _ \\  | | |__    | |__    |   /  \\ "      << endl;
    cout << " | |_| | | |    /  /     /  /   / /\\ \\ "     << endl;
    cout << " |  __/  | |   /  /     /  /   | /__\\ \\ "    << endl;
    cout << " | |     | |  /  /__   /  /__  |  __  | "      << endl;
    cout << " |_|     |_| |______| |______| |_|  |_| "      << endl;
    cout << "    _         __     __    _   ____"           << endl;
    cout << "   | |       /  \\   |  \\  | | |  _ \\ "      << endl;
    cout << "   | |      / /\\ \\  | \\ \\ | | | | \\ \\ "  << endl;
    cout << "   | |     | /__\\ \\ | |\\ \\| | | | | | "    << endl;
    cout << "   | |___  |  __  | | | \\ | | | |_/ / "       << endl;
    cout << "   |_____| |_|  |_| |_|  \\__| |___ /   tm."   << endl;
    cout << "-------------------------------------------"   << endl;
    cout << endl;


        cout << "1: Order" << endl;
        cout << "2: View orders" << endl;
        cout << "3: Quit" << endl;

        cin >> selection;

        if(selection == '1'){

            //PizzaUI pizzaui;
            pizzaui.startUI();
        }
        if(selection == '2'){

            //PizzaUI pizzaui;
            pizzaui.view_Orders();
        }
    }
}


