#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "../main.h"
#include "../SERVICE/PizzaService.h"
#include "../REPO/PizzaRepository.h"
#include "../SERVICE/OrderService.h"



class PizzaUI
{
public:
    PizzaUI();

    void startUI();
    void ui_Header();
    void view_Orders();

private:
    PizzaService pizza_Service;
    OrderService order_Service;
    //PizzaRepository pizzaRepo;
};

#endif // PIZZAUI_H
