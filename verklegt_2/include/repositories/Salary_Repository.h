#ifndef SALARY_REPOSITORY_H
#define SALARY_REPOSITORY_H
#include "Salary.h"


class Salary_Repository
{
    public:
        Salary_Repository();
        void add_salary(Salary& salary);
        vector<Salary> read_salaryfile_into_vector();
        void add_fixed_salary(vector<Salary>& sal_vector,Salary& salary);


    private:
};

#endif // SALARY_REPOSITORY_H
