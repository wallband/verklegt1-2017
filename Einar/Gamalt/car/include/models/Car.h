#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>

using namespace std;



class Car
{
    public:
        Car(string manufacturer, string type, int age);
        string get_manufacturer();
        string get_type();
        int get_age();

        friend ostream& operator <<(ostream& out, const Car& car);




    private:
        string manufacturer;
        string type;
        int age;
};

#endif // CAR_H
