#ifndef SALARY_H
#define SALARY_H

#include <string>
#include <iostream>

using namespace std;


class Salary
{
    public:
        Salary();

        void set_name();
        void set_kennitala();
        void set_year();
        void set_month();
        void set_salary_amount();

        string get_name();
        string get_kennitala();
        int get_year();
        int get_month();
        int get_salary_amount();

        friend istream& operator >>(istream& in, Salary& salary);
        friend ostream& operator <<(ostream& out, Salary& salary);


    private:
        string name;
        string kennitala;
        int year;
        int month;
        int salary_amount;
};

#endif // SALARY_H
