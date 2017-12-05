#ifndef CARSERVICE_H
#define CARSERVICE_H

#include "Car.h"
#include "CarRepository.h"
class CarService
{
    public:
        CarService();
        void add_car(const Car& car);

    private:
        CarRepository car_repo;
};

#endif // CARSERVICE_H
