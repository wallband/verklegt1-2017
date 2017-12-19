#ifndef SIDEDISHREPOSITORY_H
#define SIDEDISHREPOSITORY_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <locale>
#include "../EXCEPTIONS/FileNotFound.h"
#include "../EXCEPTIONS/InvalidInput.h"

using namespace std;

class SideDishRepository
{
public:
    SideDishRepository();
    void clean_vectors();                   /// This function is used to clear out the vectors. Setting them to size 0.
    void add_dish_to_side_dish_list();      /// User gets to make a new dish which is placed on the side-dish menu.
    void remove_dish_from_side_dish_list(); /// User selects a dish to remove from the side-dish menu.
    void read_dishlist();                   /// This function is used to read from DishList.txt into the dish_vector
    void read_dishpricelist();              /// This function is used to read from DishPrice.txt into the price_vector
    void write_to_file_from_vector();       /// I use this functino to write the modified Side-Dish menu to DishList.txt
    bool have_vectors_been_changed;         /// True/False variable used to determine if the vectors should be reloaded.
    void check_vectors();                   /// Check if vectors are empty or if they have changed since they were loaded last.

private:
    vector<string> dish_vector;
    vector<string> price_vector;
};

#endif // SIDEDISHREPOSITORY_H
