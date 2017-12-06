#include "Salary_Repository.h"
#include <fstream>
#include <vector>

Salary_Repository::Salary_Repository()
{}

void Salary_Repository::add_salary(Salary& salary) {
        ofstream fout;
        ofstream fout_all;
        string filename = salary.get_kennitala() + ".txt";
    fout.open(filename, ios::app);
    fout_all.open("salary_everybody.txt", ios::app);
            fout << salary;
            fout_all << salary;




    fout.close();
}

vector<Salary> Salary_Repository::read_salaryfile_into_vector() {
    vector<Salary> salary_vector;
    Salary salary;

    ifstream fin;
    string filename;
    string str;
    cout << "Enter the kennitala you wish to review: ->";
    cin >> filename;
    fin.open(filename + ".txt");
    while(!fin.eof()) {
        if(fin.is_open()) {
        getline(fin,str);
        salary.set_name(str);

        getline(fin,str);
        salary.set_kennitala(str);

        getline(fin,str);
        salary.set_year(str);

        getline(fin,str);
        salary.set_month(str);

        getline(fin,str);
        salary.set_salary_amount(str);
        if(fin.eof()) {
                break;
            }



        salary_vector.push_back(salary);

        }
        else {
        cout << "Invalid kennitala";
        break;
    }
    }
    fin.close();
    return salary_vector;

}
/// This one is for add_fixed_salary
void Salary_Repository::add_fixed_salary(vector<Salary>& sal_vector, Salary& salary) {
    ofstream fout;

    string filename = salary.get_kennitala() + ".txt";
    fout.open(filename);
    for(unsigned int i = 0; i < sal_vector.size(); i++) {
        fout << sal_vector[i];
    }






    fout.close();
}
/*vector<Salary> Salary_Repository::read_salaryfile_into_vector() {
    vector<Salary> salary_vector;
    Salary salary;

    ifstream fin;
    string filename;
    string str;
    cout << "Enter the kennitala you wish to review: ->";
    cin >> filename;
    fin.open(filename + ".txt");
    while(!fin.eof()) {
        if(fin.is_open()) {
        getline(fin,str);
        salary.set_name(str);

        getline(fin,str);
        salary.set_kennitala(str);

        getline(fin,str);
        salary.set_year(str);

        getline(fin,str);
        salary.set_month(str);

        getline(fin,str);
        salary.set_salary_amount(str);
        if(fin.eof()) {
                break;
            }



        salary_vector.push_back(salary);

        }
        else {
        cout << "Invalid kennitala";
        break;
    }
    }
    fin.close();
    return salary_vector;

}*/


