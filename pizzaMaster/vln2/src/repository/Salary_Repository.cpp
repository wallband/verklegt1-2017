#include "Salary_Repository.h"
#include <fstream>
#include "Salary.h"
#include <iostream>
using namespace std;
Salary_Repository::Salary_Repository()
{

}

vector<Salary> Salary_Repository::get_salary_list() {
    ifstream fin;
    fin.open("salary.txt");


        string name1;
        string str;
        string kt;
        int year, month;
        double salary;
        vector<Salary> salary_vector;

        if(fin.is_open()) {
            while(!fin.eof()) {
            getline(fin, name1, ',');

            fin >> name1>> kt >> year >> month >>salary;
           /* cout << "Name: " << name1 << endl
                 << "Kt: " << kt << endl
                 << "Year: " << year << endl
                 << "Month " << month << endl
                 << "Salary: " << salary << endl << endl;*/
                 salary_repo.set_name(name1);
                 salary_repo.set_kt(kt);
                 salary_repo.set_year(year);
                 salary_repo.set_month(month);
                 salary_repo.set_salary(salary);


            salary_vector.push_back(salary_repo);

        }
            return salary_vector;
    }
    else {

            cout << "File not found" << endl;
        }

    fin.close();


}

void Salary_Repository::add_salary_record(Salary& salary) {
    ofstream fout;
    string str;
    fout.open("salary.txt", ios::app);

    if(fout.is_open()) {

        fout << salary.get_name() << "," << salary.get_kt() << "," << salary.get_year() <<","
             << salary.get_month() << "," << salary.get_salary() << endl;
    }

}


