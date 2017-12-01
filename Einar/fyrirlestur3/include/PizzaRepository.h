#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include "../Pizza.h"

class PizzaRepository
{
    public:
        PizzaRepository();
        virtual ~PizzaRepository();

        void storePizza(Pizza pizza);
        Pizza retrivePizza();


    protected:

    private:
};

#endif // PIZZAREPOSITORY_H
