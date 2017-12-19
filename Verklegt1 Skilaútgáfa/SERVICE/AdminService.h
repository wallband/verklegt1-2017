#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H
#include "AdminRepository.h"
#include "DrinkRepository.h"
#include "SideDishRepository.h"
#include "ToppingRepository.h"
#include "ComboRepository.h"


class AdminService
{
public:
    AdminService();
    void add_drink_to_drinklist();              /// Function used to add a drink to the list of available drinks.
    void remove_drink_from_drinklist();         /// Function used to remove a drink selected by the user, from the list of available drinks.

    void add_dish_to_side_dish_list();          /// Function used to add a dish to the list of available side-dishes.
    void remove_dish_from_side_dish_list();     /// Function used to remove a dish selected by the user, from the list of available side-dishes.

    void add_topping_to_topping_list();         /// Function used to add a topping to the list of available toppings.
    void remove_topping_from_topping_list();    /// Function used to remove a topping selected by the user, from the list of available toppings.

    void remove_combo_from_list();              /// Function used to add a pizza-combo to the list of available pizza-combos.
    void add_combo_to_list();                   /// Function used to remove a pizza-combo selected by the user, from the list of available pizza-combos.

private:
    DrinkRepository drinkRepo;
    SideDishRepository sideRepo;
    ToppingRepository toppingRepo;
    ComboRepository comboRepo;
};

#endif // ADMINSERVICE_H
