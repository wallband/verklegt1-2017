#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>
using namespace std;


class Topping
{
    public:
        Topping();
        Topping(char *name, double price);
        virtual ~Topping();

        friend ostream& operator <<(ostream& out, Topping& topping);



    protected:

    private:
        char name[32];
        double price = 0;
};

#endif // TOPPING_H
