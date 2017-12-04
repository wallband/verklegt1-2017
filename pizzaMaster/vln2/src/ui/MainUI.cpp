#include "MainUI.h"

MainUI::MainUI(){}

void MainUI::start_ui() {

    while(true) {

    cout << "1. View list of employees: " << endl;
    cout << "2. Add salary record: " << endl;
    cout << "3. Get all salary records for a given KT: " << endl;
    cout << "4. Total salay for certain year and KT; " << endl;
    cout << "5. Show employee with highest salary for selected year" << endl;

    char input;
    cin >> input;
    validate_input(input);

    }


}
void MainUI::validate_input(char input) {

    if(input == '1') {
        system("CLS");



    }
    else if(input == '1') {
        system("CLS");
    }
    else if(input == '2') {
        system("CLS");
        cout << input;

    }
    else if(input == '3') {
        system("CLS");
        cout << input;
    }
    else if(input == '4') {
        system("CLS");
        cout << input;
    }
    else {
        system("CLS");
        cout << "Invalid input, please select again." << endl;

    }



}

