#include "AdminService.h"

AdminService::AdminService()
{}

void AdminService::add_drink_to_drinklist()
{
    drinkRepo.add_drink_to_drinklist();
}
void AdminService::remove_drink_from_drinklist()
{
    drinkRepo.remove_drink_from_drinklist();
}


void AdminService::add_dish_to_side_dish_list()
{
    sideRepo.add_dish_to_side_dish_list();
}
void AdminService::remove_dish_from_side_dish_list()
{
    sideRepo.remove_dish_from_side_dish_list();
}

void AdminService::add_topping_to_topping_list()
{
    toppingRepo.add_topping_to_topping_list();
}
void AdminService::remove_topping_from_topping_list()
{
    toppingRepo.remove_topping_from_topping_list();
}

void AdminService::remove_combo_from_list()
{
    comboRepo.remove_combo_from_list();
}
void AdminService::add_combo_to_list()
{
    comboRepo.add_combo_to_list();
}
