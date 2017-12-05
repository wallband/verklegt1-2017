#include "StaffUI.h"
#include <cstdlib>

StaffUI::StaffUI()
{
    //ctor
}

void StaffUI::main_menu()
{
    cout << "Hi staff person" << endl;

    while(true)
    {
    cout << "Pick the number for the corresponding option" << endl;
    cout << "********************************************" << endl;
    cout << "1. Add a car" << endl;
    cout << "2. View cars" << endl;
    cout << "3. Exit" << endl;
    cout << endl;

    char input;
    cin >> input;
    validate_user_input(input);
    }
}
void StaffUI::validate_user_input(char input)
{
    if(input == '1')
    {
        try
        {
            car_service.add_car(create_car());
        }
        catch(InvalidManifacturerExeption)
        {
            system("CLS");  // clear screen!
            cout << "Zup bro, invalid manufacturer!" << endl << endl;
        }
        catch(InvalidAgeOfCarException e)
        {
            system("CLS");  // clear screen!
            cout << e.getMessage() << endl << endl;
        }

     //   cout << "Adding a car";
    }
    else if(input == '2')
    {
        cout << "Viewing a car" << endl;
    }
    else if (input == '3')
    {
        exit(1);
 //       cout << "Invalid input!" << endl;
//        isdigit(input);
//        isalpha();
    }
}
Car StaffUI::create_car()
{
    string manufacturer, type;
    int age;
    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Type: ";
    cin >> type;
    cout << "Age of car: ";
    cin >> age;
    Car car(manufacturer, type, age);
    return car;
}
