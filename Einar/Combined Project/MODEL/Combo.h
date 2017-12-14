#ifndef COMBO_H
#define COMBO_H
#include <string>
#include <vector>

using namespace std;


class Combo
{
    public:
        Combo();
        void set_name(string name);
        void set_price(int price);
        string get_name();
        vector<string> list_of_toppings;
        int get_topping_vector_size();


    private:
        string name;
        int price;

};

#endif // COMBO_H
