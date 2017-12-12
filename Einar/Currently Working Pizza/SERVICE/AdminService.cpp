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
