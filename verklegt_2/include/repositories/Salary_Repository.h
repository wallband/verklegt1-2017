#ifndef SALARY_REPOSITORY_H
#define SALARY_REPOSITORY_H
#include "Salary.h"


class Salary_Repository
{
    public:
        Salary_Repository();
        void add_salary(Salary& salary);
        vector<Salary> read_salaryfile_into_vector();
        vector<Salary> read_salaryfile_into_vector2(Salary salary);
        void add_fixed_salary(vector<Salary> sal_vector,Salary salary);
        void total_salary(string year, string kennitala);


    private:
};

#endif // SALARY_REPOSITORY_H
