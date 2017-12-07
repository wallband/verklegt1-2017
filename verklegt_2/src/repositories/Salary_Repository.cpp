#include "Salary_Repository.h"
#include <fstream>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

Salary_Repository::Salary_Repository()
{}

void Salary_Repository::add_salary(Salary& salary) {
        ofstream fout;
        ofstream fout_all;
        string filename = salary.get_kennitala() + "_" + salary.get_year() + ".txt";
    fout.open(filename, ios::app);
    fout_all.open("salary_everybody.txt", ios::app);
            fout << salary;
            fout_all << salary;




    fout.close();
    fout_all.close();
}

vector<Salary> Salary_Repository::read_salaryfile_into_vector() {
    vector<Salary> salary_vector;
    Salary salary;

    ifstream fin;
    string filename;
    string year;
    string str;
    cout << "Enter the kennitala you wish to review: ->";
    cin >> filename;
    cout << "Enter the year you would like to view: ->";
    cin >> year;
    fin.open(filename + "_" + year + ".txt");
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
void Salary_Repository::add_fixed_salary(vector<Salary> sal_vector, Salary salary) {
    ofstream fout;

    string filename = salary.get_kennitala() + "_" + salary.get_year() + ".txt";
    fout.open(filename);
    cout << "Inni add_fixed_salary, fyrir loopuna sem les i skra" << endl;
    for(unsigned int i = 0; i < sal_vector.size(); i++) {
             salary = sal_vector[i];
             fout << salary;
    }
    cout << "Eftir loopu sem les i skra, inni add_fixed_salary" << endl;
    fout.close();
}
vector<Salary> Salary_Repository::read_salaryfile_into_vector2(Salary salary) {
    vector<Salary> salary_vector;

    ifstream fin;
    string filename = salary.get_kennitala() + "_" + salary.get_year() + ".txt";
    string str;
    fin.open(filename);
    if(fin.is_open()) {
        while(true){
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
            cout << "Var ad setja " << salary.get_name() << " i vectorinn" << endl;
            salary_vector.push_back(salary);
                if(fin.eof()) {
                    cout << "End of file, hoppar ut ur read_into_vector_2 " << endl;
                    break;
                }
        }
    }                               ///If the .txt file does not exist,
    else if(!fin.is_open()) {       ///use add_salary to create file and
        add_salary(salary);         ///add the salary class to it.
        cout << "File not found, making new file named " << salary.get_kennitala() + ".txt" << endl;
        //if(fin.is_open()) {
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
            salary_vector.push_back(salary);
       // }

    }
    else {
        cout << "Error while trying to read from file " << salary.get_kennitala() + "_" + salary.get_year() + ".txt" << endl;
    }
    fin.close();
    return salary_vector;
}
void Salary_Repository::total_salary(string year, string kennitala) {
    ifstream fin;
    vector<Salary> salary_vector;
    Salary salary;
    string str, amount;
    int total_salary_int = 0;
    int salary_int = 0;
    string filename = kennitala + "_" + year + ".txt";
    fin.open(filename);
    if(fin.is_open()) {
        while(true) {
            getline(fin,str);
            salary.set_name(str);

            getline(fin,str);
            salary.set_kennitala(str);

            getline(fin,str);
            salary.set_year(str);

            getline(fin,str);
            salary.set_month(str);

            getline(fin,amount);
            salary.set_salary_amount(amount);
            salary_vector.push_back(salary);
            if(fin.eof()) {
                break;
            }
        }
    }
    else {
        cout << "File not found, try again" << endl;
    }
    for(unsigned int i = 0; i < salary_vector.size(); i++) {
        salary_int = stoi(salary_vector[i].get_salary_amount());
        total_salary_int += salary_int;
    }
    salary_int = stoi(salary_vector.back().get_salary_amount());
    total_salary_int -= salary_int;
    cout << salary_vector[0].get_name()  << " Kt: " << kennitala << " had " << fixed << setprecision(3) << total_salary_int << " in salary for the year " << year << endl;
    fin.close();
}
