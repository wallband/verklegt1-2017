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
    void clean_vectors();               /// This function is used to clear out the vectors. Setting them to size 0.
    void add_drink_to_drinklist();      /// User gets to make a new drink which is placed on the drinks menu.
    void read_drinklist();              /// This function is used to read from DrinkList.txt into the drink_vector
    void read_drinkpricelist();         /// This function is used to read from DrinkPrice.txt into the price_vector
    void write_to_file_from_vector();   /// I use this functino to write the modified Drinks menu to the DrinkList.txt
    void remove_drink_from_drinklist(); /// User selects a drink to remove from the menu.
    bool have_vectors_been_changed;     /// True/False variable used to determine if the vectors should be reloaded.
    void check_vectors();               /// Check if vectors are empty or if they have changed since they were loaded last.

private:
    vector<string> drink_vector;
    vector<string> price_vector;
};

#endif // DRINKREPOSITORY_H
