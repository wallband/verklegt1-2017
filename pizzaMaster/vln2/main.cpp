#include "MainUI.h"
#include "Employee.h"
#include "Salary.h"



using namespace std;

int main()
{

    /*MainUI mainUI;
    mainUI.start_ui();*/

    Employee Einar("Einar", 2908815289);
    Salary salary_einar(Einar, 2017, 12, 450.000);
    cout << salary_einar;
    return 0;
}
