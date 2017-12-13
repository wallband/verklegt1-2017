#ifndef DRINKSERVICE_H
#define DRINKSERVICE_H
#include"DrinkRepository.h"


class DrinkService
{
    public:
        DrinkService();
        void add_drink();

    private:
        DrinkRepository drinkRepo;
};

#endif // DRINKSERVICE_H
