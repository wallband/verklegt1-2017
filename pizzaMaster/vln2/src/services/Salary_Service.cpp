#include "Salary_Service.h"
#include "Salary.h"

using namespace std;
Salary_Service::Salary_Service()
{

}

void Salary_Service::get_salary_list() {
    vector<Salary> salary_list = salary_repo.get_salary_list();

    for(unsigned int i = 0; i < salary_list.size(); i++) {

        cout << salary_list[i];
    }

}

void Salary_Service::add_salary_record(Salary salary) {

    salary_repo.add_salary_record(salary);
}
