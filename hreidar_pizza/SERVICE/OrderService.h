#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "../MODEL/PizzaRepository.h"


class OrderService
{
    public:
        OrderService();


    private:
        PizzaRepository pizzaRepo;

};

#endif // ORDERSERVICE_H
