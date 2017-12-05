#ifndef STAFFUI_H
#define STAFFUI_H
#include "CarService.h"
#include "Car.h"

class StaffUI
{
    public:
        StaffUI();
        void main_menu();

    protected:

    private:
        void validate_user_input(char input);
        Car create_car();
        CarService car_service;
};

#endif // STAFFUI_H
