#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "../main.h"
#include "../SERVICE/PizzaService.h"
#include "../REPO/PizzaRepository.h"
#include "../SERVICE/OrderService.h"



class PizzaUI
{
public:
    void initVector();
    void startUI();
    void contUI(int fileNr);
    void selectItems();
    void ui_Header();
    void admin_Header();
    void view_Orders();
    void view_OrdersBaker();
    void view_OrdersSales();
    void order_Operations(int selection);
    void order_OperationsBaker(int selection);
    void order_OperationsSales(int selection);

private:
    PizzaService pizza_Service;
    OrderService order_Service;
    //PizzaRepository pizzaRepo;
};

#endif // PIZZAUI_H
