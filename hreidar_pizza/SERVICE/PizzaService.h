#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "../main.h"
#include "../REPO/PizzaRepository.h"
#include "DrinkService.h"
#include "OrderService.h"





class PizzaService
{
    public:
        PizzaService();
        void makePizza();
        string pizzaStart();
        string pizzaType(string str);
        void addPizza(string str);
        void addDrink();
        void addSide();
        void orderHeader();
        void finish_Order();
        //void deleteItem();


    private:
        PizzaRepository pizzaRepo;
        OrderService orderService;
};

#endif // PIZZASERVICE_H
