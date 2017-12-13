#ifndef SIDEDISHREPOSITORY_H
#define SIDEDISHREPOSITORY_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <locale>
#include "../EXCEPTIONS/FileNotFound.h"
#include "../EXCEPTIONS/InvalidInput.h"

using namespace std;

class SideDishRepository
{
public:
    SideDishRepository();
    void clean_vectors();
    void add_dish_to_side_dish_list();
    void remove_dish_from_side_dish_list();
    void read_dishlist();
    void read_dishpricelist();
    void write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/);
    bool have_vectors_been_changed;
    void check_vectors();

private:
    vector<string> dish_vector;
    vector<string> price_vector;
};

#endif // SIDEDISHREPOSITORY_H
