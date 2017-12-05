#include "Salary_Repository.h"
#include <fstream>
#include <vector>

Salary_Repository::Salary_Repository()
{}

void Salary_Repository::add_salary(Salary& salary) {
        ofstream fout;
    fout.open("salary.txt", ios::app);

            fout << salary;




    fout.close();
}

vector<Salary> Salary_Repository::read_salaryfile_into_vector() {
    vector<Salary> salary_vector;
    Salary salary;

    ifstream fin;
    string str;
    fin.open("salary.txt");
    while(fin.eof()) {
        getline(fin,str,',');
        salary.set_name(str);

        getline(fin,str,',');
        salary.set_kennitala(str);

        getline(fin,str,',');
        salary.set_year(str);

        getline(fin,str,',');
        salary.set_month(str);

        getline(fin,str,',');
        salary.set_salary_amount(str);

        salary_vector.push_back(salary);
    }

    fin.close();


    return salary_vector;
}

