#include "CarService.h"
#include "invalidmanifacturerexeption.h"
#include <iostream>
using namespace std;

CarService::CarService()
{
    //ctor
}

void CarService::add_car(const Car& car)
{
    if(isValidManufacturer(car) && isValidCarAge(car))
    {
        car_repo.add_car(car);
    }
    /// validate car



    //cout << car << endl;
}
bool CarService::isValidManufacturer(const Car& car)
{
    string manufacturer = car.get_manufacturer();

    for(unsigned int i = 0; i < manufacturer.length(); i++)
    {
        if(!isalpha(manufacturer[i]))
           {
               throw (InvalidManifacturerExeption());
           }
    }
    return true;
}
bool CarService::isValidCarAge(const Car& car)
{
    if(car.get_age() < 0)
    {
        throw (InvalidAgeOfCarException("The age is not valid!"));
    }
    return true;
}
