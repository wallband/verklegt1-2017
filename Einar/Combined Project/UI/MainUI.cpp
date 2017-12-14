#include "../UI/MainUI.h"

MainUI::MainUI() {}
void MainUI::startUI()
{
    //pizzaui.initVector();
    //string passWd = "12345";
    //string input;
    char selection = '\0';



    while(selection != '6')
    {
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
        cout << "3: Admin" << endl;
        cout << "4: Baker" << endl;
        cout << "5: Sales" << endl;


        cout << "\n6: Quit" << endl;

        cin >> selection;

        if(selection == '1')
        {

            pizzaui.startUI();
        }
        if(selection == '2')
        {

            pizzaui.view_Orders();
        }
        if(selection == '3')
        {
            AdminUI adminui;
            adminui.startUI();
        }
        if(selection == '4')
        {
            BakerUI bakerui;
            bakerui.startUI();
        }
        /*if(selection == '3'){
            pizzaui.admin_Header();
            cout << "Enter password... ";
            cin >> input;

            if(input == passWd){
                cout << "\n  Access granted" << endl;
                system("pause");
            }
            else{
                cout << "\n  !DENIED!" << endl;
                system("pause");
            }
        }
        **/
    }
}


