#ifndef SALARY_REPOSITORY_H
#define SALARY_REPOSITORY_H
#include <string>
#include <iostream>
#include <fstream>
#include "Salary.h"
#include <vector>

using namespace std;


class Salary_Repository
{
    public:
        Salary_Repository();
        vector<Salary> get_salary_list();
        void add_salary_record(Salary& salary);


    private:
        Salary salary_repo;
};

#endif // SALARY_REPOSITORY_H
