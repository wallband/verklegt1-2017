#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "../main.h"
#include "OrderRepository.h"


class PizzaRepository
{
    private:
        OrderRepository OrderRepo;
        int total;
        int totalPizza;
        int totalDrink;
        int totalSides;
        string phoneNr;
        vector<string> listOfToppings;
        vector<string> listOfDrinks;
        vector<string> listOfSides;
        vector<int> listOfToppingPrice;
        vector<int> listOfDrinkPrice;
        vector<int> listOfSidesPrice;
        vector<string> OrderList;
        status stateOfPizza;

    public:
        PizzaRepository();
        void init();
        int numOfItems();
        void input_Drinks();
        void input_Sides();
        void orderTotal(int money);
        int get_Total();
        int getTotalPizza();
        int getTotalDrink();
        int getTotalSides();
        string getPhoneNr();

        void clearMem();
        void newTotal(int total);
        void newTotalPizza(int totalPizza);
        void newTotalDrink(int totalDrink);
        void newTotalSides(int totalSides);
        void newPhoneNr(string phoneNr);

        void storePizza(string pizza, int items);
        void saveOrder(int file, string phone);
        void loadOrder(int file);
        void printOrder();
        ///void removeItem(); // !!Dangerous!!
        void addVectorString(string str);
        void toppingHeader();
        void drinksHeader();
        void sidesHeader();
        void input_Toppings(string str);


};

#endif // PIZZAREPOSITORY_H
