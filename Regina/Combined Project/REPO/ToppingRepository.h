#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <locale>
#include "../EXCEPTIONS/FileNotFound.h"
#include "../EXCEPTIONS/InvalidInput.h"

using namespace std;

class ToppingRepository
{
public:
    ToppingRepository();
    void clean_vectors();
    void add_topping_to_topping_list();
    void remove_topping_from_topping_list();
    void read_toppinglist();
    void read_toppingpricelist();
    void write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/);
    bool have_vectors_been_changed;
    void check_vectors();

private:
    vector<string> topping_vector;
    vector<string> price_vector;
};

#endif // TOPPINGREPOSITORY_H
