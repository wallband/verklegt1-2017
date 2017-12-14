#include "DrinkService.h"

DrinkService::DrinkService()
{}

void DrinkService::add_drink()
{
    drinkRepo.add_drink_to_drinklist();
}
