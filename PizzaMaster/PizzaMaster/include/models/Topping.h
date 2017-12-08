#ifndef TOPPING_H
#define TOPPING_H

#include <string>
#include <iostream>



using namespace std;


class Topping
{
    public:
        Topping();

        string get_name();
        int get_price();

        void set_name(string new_name);
        void set_price(int new_price);

        //void add_topping(Pizza& pizza);




    private:
        string name;
        int price;


};

#endif // TOPPING_H
