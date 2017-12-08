#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "../main.h"
#include "../MODEL/PizzaRepository.h"
#include "DrinkService.h"
#include "OrderService.h"





class PizzaService
{
    public:
        PizzaService();
        void makePizza();
        void addPizza(string str);
        void addDrink();
        void readPizza();
        void getPizza();
        void getListOfPizza();
        void orderHeader();
        void finish_Order();
        int getTotalPizza();
        int getTotalDrink();


    private:
        int totalPizza;
        int totalDrink;
        PizzaRepository pizzaRepo;
};

#endif // PIZZASERVICE_H
