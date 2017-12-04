#include "CarService.h"

CarService::CarService()
{
    //ctor
}

void CarService::add_car(const Car& car) {
    car_repo.add_car(car);
    cout << car << endl;

}
