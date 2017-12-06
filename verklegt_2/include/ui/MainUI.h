#ifndef MAINUI_H
#define MAINUI_H
#include "Salary.h"
#include "Salary_Service.h"
#include "Salary_Repository.h"


class MainUI
{
    public:
        MainUI();
        void startui();
        void validate_input(char input);
        void add_salary(Salary salary);
        void read_salary_list();
        Salary create_salary();

    private:
        Salary_Service salary_service;
        Salary_Repository salary_repo;
};

#endif // MAINUI_H
