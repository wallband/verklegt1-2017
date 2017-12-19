#ifndef COMBOREPOSITORY_H
#define COMBOREPOSITORY_H
#include "Combo.h"
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


class ComboRepository
{
public:
    ComboRepository();
    void add_combo_to_list();           /// User gets to make a new pizza-combo which is placed on the menu.
    void remove_combo_from_list();      /// User selects a pizza-combo to remove from the menu.
    void clean_vectors();               /// This function is used to clear out the vectors. Setting them to size 0.
    void read_combolist();              /// This function is used to read from ComboName.txt into the combo_vector
    void read_combopricelist();         /// This function is used to read from Comboprice.txt into the price_vector
    void write_to_file_from_vector();   /// I use this functino to write the modified Pizza Combo menu to the ComboName.txt
    bool have_vectors_been_changed;     /// True/False variable used to determine if the vectors should be reloaded.
    void check_vectors();               /// Check if vectors are empty or if they have changed since they were loaded last.
    void read_toppinglist();            /// This function is used to read from ToppingList.txt into the toppings_vector.



private:
    vector<string> combo_vector;        ///
    vector<string> comboToppings;       ///
    vector<string> price_vector;        ///
    vector<string> topping_vector;      ///
    // vector<Combo> combo_vector;
    //Combo combo;
};

#endif // COMBOREPOSITORY_H
