#include "Employee_Service.h"

Employee_Service::Employee_Service()
{
    //ctor
}

void Employee_Service::get_employee_list() {
employee_repo.read_employee_list();

}
