#include "PizzaRepository.h"
#include <fstream>
#include "../Pizza.h"

using namespace std;

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}
void PizzaRepository::storePizza(Pizza pizza) {

    ofstream fout;
    fout.open("Pizzas.txt");

    fout << pizza;

    fout.close();

}
Pizza PizzaRepository::retrivePizza() {

    ifstream fin;
    fin.open("Pizzas.txt");
    if(fin.is_open()) {

        Pizza pizza;
        fin >> pizza;

    return pizza;
    }
    else {

        cout << "File not found";
    }
    fin.close();




}
