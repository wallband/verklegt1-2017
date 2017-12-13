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

        void add_drink_to_drinklist();           ///Remove
        void remove_drink_from_drinklist();      ///Remove

    private:
        vector<string> drink_vector;
        vector<string> price_vector;
        vector<Combo> combo_vector;
        //Combo combo;
};

#endif // COMBOREPOSITORY_H
