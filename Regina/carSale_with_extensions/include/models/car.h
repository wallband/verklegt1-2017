#ifndef CAR_H
#define CAR_H

#include<string>
#include <iostream>
using namespace std;

class Car
{
    public:
        Car(string manufacturer, string type, int age);
        string get_manufacturer() const;
        string get_type() const;
        int get_age() const;

        friend ostream& operator << (ostream& out, const Car& car);

    private:
        string manufacturer;
        string type;
        int age;
};

#endif // CAR_H
