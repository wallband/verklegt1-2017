#include "CarRepository.h"


CarRepository::CarRepository()
{
    //ctor
}

void CarRepository::add_car(const Car& car) {

    ofstream fout;
    fout.open("cars.txt", ios::app);
    if(fout.is_open()) {
       fout << car << endl;

       fout.close();

    }
    else {
        /// throw error
    }
}
