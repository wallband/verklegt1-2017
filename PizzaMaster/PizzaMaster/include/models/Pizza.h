#ifndef PIZZA_H
#define PIZZA_H
#include <Topping.h>
#include <vector>
#include <string>

using namespace std;

class Pizza
{
    public:
        Pizza(string pizza_size, string pizza_bottom);
        Pizza();

    private:
        string pizza_size;
        string pizza_bottom;
        string pizza_comment;
        Topping topping;
        vector<Topping> toppings_vector;

};

#endif // PIZZA_H
