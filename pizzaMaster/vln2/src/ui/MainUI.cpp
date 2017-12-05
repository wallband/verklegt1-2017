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
        salary_service.get_salary_list();
    }
    else if(input == '2') {
        system("CLS");
        salary_service.add_salary_record(make_new_salary());
    }
    else if(input == '3') {
        system("CLS");
        cout << input << endl;
    }
    else if(input == '4') {
        system("CLS");
        cout << input << endl;
    }
    else if(input == '5') {
        system("CLS");
        cout << input << endl;
    }
    else {
        system("CLS");
        cout << input << endl;
        cout << "Invalid input, please select again." << endl;

    }



}

Salary MainUI::make_new_salary() {

    Salary salary;
    string name,kt;
    int year,month;
    double salary1;
    cout << "Name: ->"; cin >> name;
    cout << "Kennitala; ->"; cin >> kt;
    cout << "Year: ->"; cin >> year;
    cout << "Month: ->"; cin >> month;
    cout << "Salary; ->"; cin >> salary1;

    salary.set_name(name);
    salary.set_kt(kt);
    salary.set_year(year);
    salary.set_month(month);
    salary.set_salary(salary1);
    return salary;

}

