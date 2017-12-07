#ifndef SALARY_SERVICE_H
#define SALARY_SERVICE_H
#include "Salary_Repository.h"
#include "Salary.h"
#include "InvalidNameException.h"
#include "InvalidKennitalaException.h"
#include "InvalidYearException.h"
#include "InvalidMonthException.h"
#include "InvalidSalaryAmountException.h"
#include "InvalidSalaryAmountMinusException.h"
#include <algorithm>


class Salary_Service
{
    public:
        Salary_Service();
        void add_salary(Salary& salary);
        void read_salary();
        void is_salary_duplicate(vector<Salary> sal_vector, Salary salary);
        void total_salary(string year, string kennitala);

        /// Validate salary input ///
        bool isValidName(Salary& salary);
        bool isValidNameStr(string name);
        bool isValidKennitalaStr(string kennitala);
        bool isValidYearInt(string year_in);
        bool isValidMonthInt(string month);
        bool isValidSalaryAmountInt(string amount);


    private:
        Salary_Repository salary_repo;

};

#endif // SALARY_SERVICE_H
