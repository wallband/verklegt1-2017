#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "../main.h"
#include "OrderRepository.h"

class PizzaRepository
{
    public:
        PizzaRepository();

        void init();
        void orderTotal(int money);
        int get_Total();
        int numOfItems();
        void input_Drinks();
        void input_Sides();
        int getTotalPizza();
        int getTotalDrink();
        int getTotalSides();
        void storePizza(string pizza, int items);
        void saveOrder();
        void printOrder();
        ///void removeItem(); // !!Dangerous!!
        void addVectorString(string str);
        void toppingHeader();
        void drinksHeader();
        void sidesHeader();
        void input_Toppings(string str);

    private:
        OrderRepository OrderRepo;
        int total;
        int totalPizza;
        int totalDrink;
        int totalSides;
        vector<string> listOfToppings;
        vector<string> listOfDrinks;
        vector<string> listOfSides;
        vector<int> listOfToppingPrice;
        vector<int> listOfDrinkPrice;
        vector<int> listOfSidesPrice;
        vector<string> OrderList;
};

#endif // PIZZAREPOSITORY_H
