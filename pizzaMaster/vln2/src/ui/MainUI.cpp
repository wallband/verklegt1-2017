#include "MainUI.h"
#include "Employee_Service.h"

MainUI::MainUI(){}

void MainUI::start_ui() {

    while(true) {

    cout << "1. View list of employees: " << endl;
    cout << "2. Add salary record: " << endl;
    cout << "3. Get all salary records for a given KT: " << endl;
    cout << "4. Total salay for certain year and KT; " << endl;
    cout << "5. Show employee with highest salary for selected year" << endl;

    char input;
    cout << "->" ;cin >> input;
    validate_input(input);

    }


}
void MainUI::validate_input(char input) {

    if(input == '1') {
        system("CLS");
        Employee_Service service;
        service.get_employee_list();
    }
    else if(input == '1') {
        system("CLS");
        cout << input << endl;
    }
    else if(input == '2') {
        system("CLS");
        cout << input << endl;
    }
    else if(input == '3') {
        system("CLS");
        cout << input << endl;
    }
    else if(input == '4') {
        system("CLS");
        cout << input << endl;
    }
    else {
        system("CLS");
        cout << input << endl;
        cout << "Invalid input, please select again." << endl;

    }



}

