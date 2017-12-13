#include "AdminUI.h"
using namespace std;

AdminUI::AdminUI()
{}

void AdminUI::startUI()
{
    system ("CLS");
    char input;
    while(input != '3')
    {
        cout << "1: Add drink to drinks list" << endl;
        cout << "2: Remove drink from drinks list" << endl;
        cout << "3: Back to main" << endl;

        cin >> input;

        if(input == '1')
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
        if(input == '2')
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
    }
}
