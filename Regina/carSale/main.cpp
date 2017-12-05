#include <iostream>
#include "StaffUI.h"
#include "UserUI.h"
#include "car.h"

using namespace std;

int main()
{
    cout << "Are you a user of staff" << endl;
    cout << "Press 1 for user" << endl;
    cout << "Press 2 for staff" << endl;

    char input;
    cin >> input;

    if(input == '1')
    {
        UserUI uUI;
        uUI.main_menu();
    }
    else
    {
        StaffUI ui;
        ui.main_menu();
    }



    return 0;
}
