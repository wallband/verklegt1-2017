#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include <stdlib.h>
#include "Employee_Service.h"
#include "Salary_Service.h"

using namespace std;


class MainUI
{
    public:
        MainUI();
        void start_ui();
        void validate_input(char input);
        Salary make_new_salary();


    private:
        Employee_Service employee_service;
        Salary_Service salary_service;

};

#endif // MAINUI_H
