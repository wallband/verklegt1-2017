#include "Employee_Repository.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Employee_Repository::Employee_Repository(){
}

void Employee_Repository::read_employee_list() {
    ifstream fin;
    fin.open("employee_list.txt");
    string str;

    if(fin.is_open()) {
        while(!fin.eof()){
        getline(fin, str);
        cout << str << endl;
        }
    }

    fin.close();
}

