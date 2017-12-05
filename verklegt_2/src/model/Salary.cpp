#include "Salary.h"

Salary::Salary()
{}
Salary::Salary(string name, string kennitala, string year, string month, string salary_amount){
    this->name = name;
    this->kennitala = kennitala;
    this->year = year;
    this->month = month;
    this->salary_amount = salary_amount;
}

        ///Setters
void Salary::set_name(string name1) {
    this->name = name1;
}
void Salary::set_kennitala(string kennitala1){
    this->kennitala = kennitala1;
}
void Salary::set_year(string year1){

    this->year = year1;
}
void Salary::set_month(string month1){
    this->month = month1;
}
void Salary::set_salary_amount(string amount1){
    this->salary_amount = amount1;

}

        ///Getters
string Salary::get_name(){
    return this->name;
}
string Salary::get_kennitala(){
    return this->kennitala;
}
string Salary::get_year(){
    return this->year;
}
string Salary::get_month(){
    return this->month;
}
string Salary::get_salary_amount(){
return this->salary_amount;
}

        ///Friend Functions
/*istream& operator >>(istream& in, Salary& salary) {
    in >>

    return in;
}*/

ostream& operator <<(ostream& out, Salary& salary) {
    out << salary.get_name() << "," << salary.get_kennitala() << ","
        << salary.get_year() << "," << salary.get_month() << ","
        << salary.get_salary_amount() << endl;
    return out;
}


