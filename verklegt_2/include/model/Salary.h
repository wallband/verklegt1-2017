#ifndef SALARY_H
#define SALARY_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "InvalidNameException.h"
#include <vector>
using namespace std;


class Salary
{
    public:
        Salary();
        Salary(string name, string kennitala, string year, string month, string salary_amount);
        ///     Setters         ///
        void set_name(string name1);
        void set_kennitala(string kennitala1);
        void set_year(string year1);
        void set_month(string month1);
        void set_salary_amount(string amount1);
        ///     Getters         ///
        string get_name();
        string get_kennitala();
        string get_year();
        string get_month();
        string get_salary_amount();
        ///   Friend Functions  ///
        friend istream& operator >>(istream& in, Salary& salary);
        friend ostream& operator <<(ostream& out, Salary& salary);


    private:
        string name;
        string kennitala;
        string year;
        string month;
        string salary_amount;
};

#endif // SALARY_H
