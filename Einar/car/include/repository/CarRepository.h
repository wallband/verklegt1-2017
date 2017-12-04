#ifndef CARREPOSITORY_H
#define CARREPOSITORY_H
#include "Car.h"
#include <fstream>

class CarRepository
{
    public:
        CarRepository();
        void add_car(const Car& car);

    private:
};

#endif // CARREPOSITORY_H
