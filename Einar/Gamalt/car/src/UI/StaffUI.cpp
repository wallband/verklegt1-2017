#include "StaffUI.h"
#include "CarService.h"


StaffUI::StaffUI()
{
    //ctor
}

void StaffUI::main_menu(){

    while(true) {
    cout << "Hi staff person" << endl;
    cout << "Pick the number for the corresponding option" << endl;
    cout << "***********************************" << endl;
    cout << "1. Add a car" << endl;
    cout << "2. View cars" << endl;
    cout << endl;

    char input;
    cin >> input;
    validate_user_input(input);


    }
}

void StaffUI::validate_user_input(char input) {

        if(input == '1') {

            car_service.add_car(create_car());

        }
        else if(input == '2') {

            cout << "Viewing a car" << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }


}

Car StaffUI::create_car() {

    string manufacturer, type;
    int age;

    cout << "Manufacturer: ";
    cin >> manufacturer;

    cout << "Type: ";
    cin >> type;
    cout << "Age: ";
    cin >> age;

    return Car(manufacturer,type,age);

}

