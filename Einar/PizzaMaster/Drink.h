#ifndef DRINK_H
#define DRINK_H
#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Drink
{
    public:
        Drink();
        Drink(string name, double price, int number_of_bottles);

        void add_drink(Drink drink);
        void display_drinks();
        void set_name(string name);
        void set_price(double price);
        void set_number_of_bottles(int number_of_bottles);
        void show_vector_size(Drink drink);
       // vector get_vector();

        friend ostream& operator <<(ostream& out, Drink drink);
        friend istream& operator <<(istream& in, Drink drink);

        virtual ~Drink();

    protected:

    private:
        int number_of_bottles;
        string name;
        double price;
        vector<Drink> list_of_drinks;
};

#endif // DRINK_H
