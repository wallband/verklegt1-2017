#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H
#include "Employee_Repository.h"


class Employee_Service
{
    public:
        Employee_Service();
        void get_employee_list();

    private:
        Employee_Repository employee_repo;
};

#endif // EMPLOYEE_SERVICE_H
