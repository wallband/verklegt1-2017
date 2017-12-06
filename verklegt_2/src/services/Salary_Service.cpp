#include "Salary_Service.h"
#include <string.h>
#include <stdio.h>

Salary_Service::Salary_Service()
{}

void Salary_Service::add_salary(Salary& salary) {
    salary_repo.add_salary(salary);

}

void Salary_Service::read_salary(){
    salary_repo.read_salaryfile_into_vector();

}

void Salary_Service::is_salary_duplicate(vector<Salary>& sal_vector, Salary& salary) {
    for(unsigned int i = 0; i < sal_vector.size(); i++) {
        if(strcmp(sal_vector[i].get_month(),salary.get_month()) = 0) {
                cout << "Inni i if()";
            sal_vector.erase(sal_vector.begin() + i );
            sal_vector.push_back(salary);
            salary_repo.add_fixed_salary(sal_vector,salary);
        }
        cout << "Comparing vector at index " << i << " " << sal_vector[i].get_month() << " with salary " << salary.get_month();
    }
}

bool Salary_Service::isValidNameStr(string name) {
    string name1 = name;
    for(unsigned int i = 0; i < name1.length(); i++) {
        if(!isalpha(name[i]) && name1[i] != ' ') {
            throw InvalidNameException();
        }
    }
    return true;


}
bool Salary_Service::isValidKennitalaStr(string kennitala) {
    string kennitala1 = kennitala;
        for(unsigned int i = 0; i < kennitala1.length(); i++) {
            if(!isdigit(kennitala1[i]) || kennitala1.length() != 10) {
                throw InvalidKennitalaException();
            }
        }
        return true;
}
bool Salary_Service::isValidYearInt(string year_in){
    string year1 = year_in;
        if(year1 != "2017") {
            throw InvalidYearException();
        }

    return true;
}
bool Salary_Service::isValidMonthInt(string month){
    string month1 = month;
    int month_int = stoi(month1);
    if (month_int > 0 && month_int < 13){
        return true;
    }
    throw InvalidMonthException();
}
bool Salary_Service::isValidSalaryAmountInt(string amount){
    string amount1 = amount;
    int amount_int = stoi(amount);

    if(amount_int >1500000) {
            throw InvalidSalaryAmountException();

    }
    else if (amount_int < 0) {
        throw InvalidSalaryAmountMinusException();
    }
    return true;
}

