#include "userui.h"

UserUI::UserUI()
{
    //ctor
}

void UserUI::main_menu()
{
    cout << "Welcome!" << endl;

    while(true)
    {
        cout << endl;
        cout << "Please choose a number: " << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Add salary record" << endl;
        cout << "2. All salary records for given SSN" << endl;
        cout << "3. Get total salary for given year and SSN" << endl;
        cout << "4. Employee with highest salary for given year" << endl;
        cout << endl;

        char input;
        cin >> input;

        validate_user_input(input);

    }
}
void UserUI::validate_user_input(char input)
{
        if(input == '1')
        {
            cout << "Adding salary record:" << endl;
            employee_service.add_employee(create_employee());
            salary_service.add_salary(create_salary());

        }
        else if (input == '2')
        {
            cout << "Show salary records for given SSN:" << endl;
        }
        else if (input == '3')
        {
            cout << "Total salary:" << endl;
        }
        else if (input == '4')
        {
            cout << "Highest salary:" << endl;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
}
Employee UserUI::create_employee()
{
    string name;
    cout << "Name: ";
    cin >> name;
    double SSN;
    cout << "SSN: ";
    cin >> SSN;

    Employee employ(name, SSN);
    return employ;
}

Salary UserUI::create_salary()
{
    double salary;
    cout << "Salary: ";
    cin >> salary;
    int month;
    cout << "Month: ";
    cin >> month;
    int year;
    cout << "Year: ";
    cin >> year;

    Salary salary1(salary, month, year);
    return salary1;
}
