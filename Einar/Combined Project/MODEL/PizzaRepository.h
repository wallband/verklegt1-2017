#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "../main.h"

class PizzaRepository
{
    public:
        PizzaRepository();

        void init();
        void orderTotal(int money);
        int get_Total();
        void readToppings();
        int readDrinks();
        void addPizza(string str);
        void storePizza(string pizza, int items);
        void saveOrder();
        void addVectorString(string str);
        void toppingHeader();
        void drinksHeader();
        void input_Toppings(string str);

    private:
        //PizzaService service;
        int total;
        vector<string> listOfToppings;
        vector<string> listOfDrinks;
        vector<int> listOfToppingPrice;
        vector<int> listOfDrinkPrice;
        vector<string> OrderList;
};

#endif // PIZZAREPOSITORY_H
