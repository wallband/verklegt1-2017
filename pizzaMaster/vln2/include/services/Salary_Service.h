#ifndef SALARY_SERVICE_H
#define SALARY_SERVICE_H

#include "Salary_Repository.h"
#include "Salary.h"


class Salary_Service
{
    public:
        Salary_Service();
        void get_salary_list();
        void add_salary_record(Salary salary);

    private:
        Salary_Repository salary_repo;
};

#endif // SALARY_SERVICE_H
