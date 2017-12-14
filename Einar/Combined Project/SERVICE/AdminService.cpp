#include "AdminService.h"

AdminService::AdminService()
{}

void AdminService::add_drink_to_drinklist()          ///Use this function to add a drink to the list of available drinks.
{
    drinkRepo.add_drink_to_drinklist();
}
void AdminService::remove_drink_from_drinklist()    ///Use this function to remove a drink from the available drinks list.
{
    drinkRepo.remove_drink_from_drinklist();
}


void AdminService::add_dish_to_side_dish_list()     ///Use this function to add a dish to the list of available dishes.
{
    sideRepo.add_dish_to_side_dish_list();
}
void AdminService::remove_dish_from_side_dish_list()    ///Use this function to remove a dish from the available dishes list.
{
    sideRepo.remove_dish_from_side_dish_list();
}

void AdminService::add_topping_to_topping_list()        ///Use this function to add a topping to the list of available toppings.
{
    toppingRepo.add_topping_to_topping_list();
}
void AdminService::remove_topping_from_topping_list()   ///Use this function to remove a topping from the available toppings list.
{
    toppingRepo.remove_topping_from_topping_list();
}

void AdminService::remove_combo_from_list()             ///Use this function to add a pizza-combo to the list of available pizza-combos.
{
    comboRepo.remove_combo_from_list();
}
void AdminService::add_combo_to_list()                  ///Use this function to remove a pizza-combo from the available pizza-combos list.
{
    comboRepo.add_combo_to_list();
}
