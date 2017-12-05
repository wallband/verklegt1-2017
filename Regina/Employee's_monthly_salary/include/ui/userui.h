#ifndef USERUI_H
#define USERUI_H
#include "employee.h"
#include"salary.h"
#include "salaryservice.h"
#include "employeeservice.h"

class UserUI
{
    public:
        UserUI();
        void main_menu();

    private:
        void validate_user_input(char input);
        Salary create_salary();
        SalaryService salary_service;

        Employee create_employee();
        EmployeeService employee_service;
};

#endif // USERUI_H
