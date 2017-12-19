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
    void clean_vectors();                   /// This function is used to clear out the vectors. Setting them to size 0.
    void add_topping_to_topping_list();     /// User gets to make a new topping which is placed on the toppings menu.
    void remove_topping_from_topping_list();/// User selects a topping to remove from the toppings menu.
    void read_toppinglist();                /// This function is used to read from ToppingList.txt into the topping_vector
    void read_toppingpricelist();           /// This function is used to read from ToppingPrice.txt into the price_vector
    void write_to_file_from_vector();       /// I use this functino to write the modified topping list to ToppingList.txt
    bool have_vectors_been_changed;         /// True/False variable used to determine if the vectors should be reloaded.
    void check_vectors();                   /// Check if vectors are empty or if they have changed since they were loaded last.

private:
    vector<string> topping_vector;
    vector<string> price_vector;
};

#endif // TOPPINGREPOSITORY_H
