#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H
#include "AdminRepository.h"
#include "DrinkRepository.h"


class AdminService
{
    public:
        AdminService();
        void add_drink_to_drinklist();
        void remove_drink_from_drinklist();

    private:
        AdminRepository adminRepo;
        DrinkRepository drinkRepo;
};

#endif // ADMINSERVICE_H
