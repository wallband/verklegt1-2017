#include "AdminUI.h"
using namespace std;

AdminUI::AdminUI()
{}

void AdminUI::startUI()
{
    system ("CLS");
    char input;
    while(input != '9')
    {
        ui_Header();
        cout << "1: Add drink to drinks list" << endl;
        cout << "2: Remove drink from drinks list" << endl << endl;

        cout << "3: Add dish to side-dish list" << endl;
        cout << "4: Remove dish from side-dish list" << endl << endl;

        cout << "5: Add topping to toppings list" << endl;
        cout << "6: Remove topping from toppings list" << endl << endl;

        cout << "7: Add pizza to pizza combo-menu" << endl;
        cout << "8: Remove pizza from pizza combo-menu" << endl << endl;

        cout << "9: Back to main" << endl;

        cin >> input;

        if(input == '1')        ///Add drink to drink list
        {
            try
            {
                adminservice.add_drink_to_drinklist();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to add drinks, please try again or contact your system administrator" <<
                     endl << endl;
            }
        }
        if(input == '2')           ///Remove drink from drink list
        {
            try
            {
                adminservice.remove_drink_from_drinklist();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to remove drinks, please try again or contact your system administrator" <<
                     endl << endl;
            }
            catch(invalid_argument)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::invalid_argument' what():  stoi" << endl << endl;
            }
            catch(std::bad_cast)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::bad_cast' what():  std::bad_cast" << endl << endl;
            }
            catch(InvalidInput e)
            {
                system("CLS");
                cout << "Input invalid, try again" << endl << endl;
            }
        }
        if(input == '3')        ///Add side-dish to list
        {
            try
            {
                adminservice.add_dish_to_side_dish_list();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to add side-dish, please try again or contact your system administrator" <<
                     endl << endl;
            }
        }
        if(input == '4')        ///Remove side-dish from list.
        {
            try
            {
                adminservice.remove_dish_from_side_dish_list();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to remove side-dish, please try again or contact your system administrator" <<
                     endl << endl;
            }
            catch(invalid_argument)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::invalid_argument' what():  stoi" << endl << endl;
            }
            catch(std::bad_cast)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::bad_cast' what():  std::bad_cast" << endl << endl;
            }
            catch(InvalidInput e)
            {
                system("CLS");
                cout << "Input invalid, try again" << endl << endl;
            }
        }
        if(input == '5')        ///Add topping to topping list.
        {
            try
            {
                adminservice.add_topping_to_topping_list();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to add side-dish, please try again or contact your system administrator" <<
                     endl << endl;
            }
        }
        if(input == '6')        ///Remove topping from list.
        {
            try
            {
                adminservice.remove_topping_from_topping_list();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to remove side-dish, please try again or contact your system administrator" <<
                     endl << endl;
            }
            catch(invalid_argument)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::invalid_argument' what():  stoi" << endl << endl;
            }
            catch(std::bad_cast)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::bad_cast' what():  std::bad_cast" << endl << endl;
            }
            catch(InvalidInput e)
            {
                system("CLS");
                cout << "Input invalid, try again" << endl << endl;
            }
        }
        if(input == '7')        ///Add new pizza combination to menu.
        {
            try
            {
                adminservice.add_combo_to_list();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to add side-dish, please try again or contact your system administrator" <<
                     endl << endl;
            }
        }
        if(input == '8')        ///Remove pizza combination from menu.
        {
            try
            {
                adminservice.remove_combo_from_list();
            }
            catch(FileNotFound e)
            {
                system("CLS");
                cout << "There was an error when trying to remove side-dish, please try again or contact your system administrator" <<
                     endl << endl;
            }
            catch(invalid_argument)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::invalid_argument' what():  stoi" << endl << endl;
            }
            catch(std::bad_cast)
            {
                system("CLS");
                cout << "terminate called after throwing an instance of 'std::bad_cast' what():  std::bad_cast" << endl << endl;
            }
            catch(InvalidInput e)
            {
                system("CLS");
                cout << "Input invalid, try again" << endl << endl;
            }
        }
    }
}
void AdminUI::ui_Header()
{

    system("CLS");
    cout << "-----------------------" << endl;
    cout << "    Administration     " << endl;
    cout << "-----------------------" << endl;
}
