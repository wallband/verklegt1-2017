#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "../REPO/OrderRepository.h"
#include "../main.h"


class OrderService
{
public:
    int viewOrderList();    ///Small UI for either choosing the last item in the order-list or a specific item
    void service_header();  ///Header functions for decoration
    void state_header();


private:
    OrderRepository orderRepo;

};

#endif // ORDERSERVICE_H
