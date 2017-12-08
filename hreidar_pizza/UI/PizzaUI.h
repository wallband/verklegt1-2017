#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "../main.h"
#include "../SERVICE/PizzaService.h"
#include "../MODEL/PizzaRepository.h"



class PizzaUI
{
    public:
        PizzaUI();

        void startUI();
        void finishOrder();
        void ui_Header();

    private:
        PizzaService pizza_Service;
        //PizzaRepository pizzaRepo;
};

#endif // PIZZAUI_H
