#include "Salary.h"

Salary::Salary()
{
    //ctor
}
        ///Setters
void Salary::set_name() {
    string str;
    getline(cin,str);
    this->name = str;
}
void Salary::set_kennitala(){
    string str;
    getline(cin,str);
    this->kennitala = str;
}
void Salary::set_year(){
    this->year = year;
}
void Salary::set_month(){
    this->month = month;
}
void Salary::set_salary_amount(){
    cin >> this->salary_amount;

}

        ///Getters
string Salary::get_name(){
    return this->name;
}
string Salary::get_kennitala(){
    return this->kennitala;
}
int Salary::get_year(){
    return this->year;
}
int Salary::get_month(){
    return this->month;
}
int Salary::get_salary_amount(){
return this->salary_amount;
}

        ///Friend Functions
istream& operator >>(istream& in, Salary& salary) {
    salary.set_name();

    return in;
}

ostream& operator <<(ostream& out, Salary& salary) {

    return out;
}


