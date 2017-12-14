#ifndef COMBOREPOSITORY_H
#define COMBOREPOSITORY_H
#include "Combo.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <locale>
#include "../EXCEPTIONS/FileNotFound.h"
#include "../EXCEPTIONS/InvalidInput.h"


class ComboRepository
{
    public:
        ComboRepository();
        void add_combo_to_list();
        void remove_combo_from_list();
        void clean_vectors();
        void read_combolist();
        void read_drinkpricelist();
        void write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/);
        bool have_vectors_been_changed;
        void check_vectors();
    void read_toppinglist();



    private:
        vector<string> combo_vector;
        vector<string> comboToppings;
        vector<string> price_vector;
        vector<string> topping_vector;
       // vector<Combo> combo_vector;
        //Combo combo;
};

#endif // COMBOREPOSITORY_H
