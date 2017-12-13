#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include "../REPO/OrderRepository.h"
#include "../main.h"


class OrderService
{
    public:
        OrderService();
        void viewOrderList();
        void service_header();


    private:
        OrderRepository orderRepo;

};

#endif // ORDERSERVICE_H
