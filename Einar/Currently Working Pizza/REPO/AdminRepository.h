#ifndef ADMINREPOSITORY_H
#define ADMINREPOSITORY_H
#include "DrinkService.h"

using namespace std;
class AdminRepository
{
public:
    AdminRepository();
    void add_drink_to_drinklist();

private:
    DrinkService drinkService;

};

#endif // ADMINREPOSITORY_H
