#ifndef DRINKREPOSITORY_H
#define DRINKREPOSITORY_H
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <locale>
#include <stdio.h>
#include <ctype.h>
#include "../EXCEPTIONS/FileNotFound.h"
#include "../EXCEPTIONS/InvalidInput.h"

using namespace std;

class DrinkRepository
{
public:
    DrinkRepository();
    void clean_vectors();
    void add_drink_to_drinklist();
    void read_drinklist();
    void read_drinkpricelist();
    void write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/);
    void remove_drink_from_drinklist();
    bool have_vectors_been_changed;
    void check_vectors();

private:
    vector<string> drink_vector;
    vector<string> price_vector;
};

#endif // DRINKREPOSITORY_H
