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
        void loadPizza(int fileNr);
        string pizzaStart();
        string pizzaType(string str);
        void addPizza(string str);
        void addDrink();
        void addSide();
        void changePizzaState();
        void orderHeader();
        int finish_Order(int file);
        void clearMem();
        void initVector();


    private:

        PizzaRepository pizzaRepo;
        OrderService orderService;
};

#endif // PIZZASERVICE_H
