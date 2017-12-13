#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H
#include "AdminRepository.h"
#include "DrinkRepository.h"
#include "SideDishRepository.h"
#include "ToppingRepository.h"


class AdminService
{
public:
    AdminService();
    void add_drink_to_drinklist();
    void remove_drink_from_drinklist();

    void add_dish_to_side_dish_list();
    void remove_dish_from_side_dish_list();

    void add_topping_to_topping_list();
    void remove_topping_from_topping_list();

private:
    DrinkRepository drinkRepo;
    SideDishRepository sideRepo;
    ToppingRepository toppingRepo;
};

#endif // ADMINSERVICE_H
