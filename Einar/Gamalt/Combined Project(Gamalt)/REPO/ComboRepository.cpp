#include "ComboRepository.h"
#include "Combo.h"
ComboRepository::ComboRepository()
{}

void ComboRepository::clean_vectors()
{
    combo_vector.clear();
    price_vector.clear();
}
void ComboRepository::read_combolist()      /// This function is used to read from DrinkList.txt into the combo_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/COMBO/ComboName.txt");
    if(fin.is_open())
    {
        while(fin >> str)
        {
            combo_vector.push_back(str);
            getline(fin, str);
            comboToppings.push_back(str);
        }

    }
    if(!fin.is_open())
    {
        cout << "Inni i read_combolist (if!fin.is.open)" << endl;
        system("PAUSE");
        /* fstream fout;
         fout.open("DATA/DRINKS/DrinkList.txt");
         fout.close();*/
        throw FileNotFound();
    }
    fin.close();

}
void ComboRepository::read_drinkpricelist()     /// This function is used to read from Drinkprice.txt into the price_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/COMBO/ComboPrice.txt");
    if(fin.is_open())
    {
        while(fin >> str)
        {
            price_vector.push_back(str);
        }

    }
    if(!fin.is_open())
    {
        /* fstream fout;
         fout.open("DATA/DRINKS/DrinkPrice.txt");
         fout.close();*/
        throw FileNotFound();
    }
    fin.close();
}
void ComboRepository::write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/)
{

    // string str1, str2;
    //remove ("DATA/DRINKS/DrinkList.txt");
    fstream fout;
    fout.open("DATA/COMBO/ComboName.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < combo_vector.size(); i++)                      /// I use this functino to write the modified side-dish menu to the SideList.txt ///
    {
        cout << "Writing " << combo_vector[i] << " to file:" << '\n' ;
        fout << combo_vector[i] << comboToppings[i] << endl;
    }

    fout.close();
    //remove ("DATA/DRINKS/DrinkPrice.txt");
    fstream fout2;
    fout2.open("DATA/COMBO/ComboPrice.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < price_vector.size(); i++)                      /// I use this functino to write the modified price menu to the DrinkList.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << price_vector[i] << " to file:" << '\n' ;
        fout2 << price_vector[i] << '\n';
    }
    fout2.close();



}
void ComboRepository::add_combo_to_list()              /// I use this function to enter a new drink into the DrinkList.txt file ///
{
    /// using input from the user. ///
    system("CLS");
    check_vectors();
    /*if(combo_vector.size() == 0)
    {
        read_drinklist();
    }*/
    /*cout << "Price vector is size = " << price_vector.size() << endl;
    if(price_vector.size() == 0)
    {
        read_drinkpricelist();
    }*/
    string name, price,input, topping;
    bool done = false;
    int vector_size = combo_vector.size();
    int price_size = price_vector.size();
    unsigned int intput;
    cout << "Enter name for new combo " << endl;
    cin >> ws;
    getline(cin,name);
    combo_vector.resize(vector_size + 1);
    combo_vector.insert(combo_vector.end() -2, name);



    do
    {
        system ("CLS");
        cout << "Select toppings for your new combo named: -" << name << "-" << endl;
        for(unsigned int i = 0; i < topping_vector.size(); i++)
        {
            cout << " " << (i + 1) << ": " << topping_vector[i] << endl;
        }
        cout << " " << "0: Done" << endl;
        cout << "Toppings selected: " << topping << endl;
        cin >> input;
        intput = atoi(input.c_str());
        if(intput >= 1 && intput <= topping_vector.size() - 1)
        {
            topping += topping_vector[intput - 1] + " ";
        }
        else if (intput == 0)
        {
            done = true;
        }
        else
        {
            throw InvalidInput();
        }
    }
    while(!done);
    comboToppings.resize(price_size + 1);
    comboToppings.insert(comboToppings.end() -2, topping);

    cout << "Enter price for new combo " << endl;               // TODO (einar#1#12/13/17): Kominn hingað.  Redda Combo
    cin >> price;
    price_vector.resize(price_size + 1);
    price_vector.insert(price_vector.end() -2, price);

    write_to_file_from_vector(/*combo_vector, price_vector*/);
}

void ComboRepository::check_vectors()
{
    if(combo_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Drinklist empty, reading from file" << endl;
        read_combolist();
        have_vectors_been_changed = false;
    }
    if(price_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Pricelist empty, reading from file" << endl;
        read_drinkpricelist();
        have_vectors_been_changed = false;
    }
    if(topping_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Toppinglist empty, reading from file" << endl;
        read_toppinglist();
        have_vectors_been_changed = false;
    }

    /*if(have_vectors_been_changed == true)
    {
        cout << "Drinklist and Pricelist have changed since we started, reloading them now..." << endl;
        read_drinklist();
        read_drinkpricelist();
        have_vectors_been_changed = false;
    }*/
}

void ComboRepository::remove_combo_from_list()
{
    string input;
    char yes_no;
    locale loc;
    check_vectors();
    cout << "Combo vector is size = " << combo_vector.size() << endl;
    cout << "Toppings vector is size = " << comboToppings.size() << endl;
    cout << "Price vector is size = " << price_vector.size() << endl;

    for(unsigned int i = 0; i < combo_vector.size() - 1; i++)
    {
        cout << " " << i << ": " << combo_vector[i] << endl;
    }
    cout << "Please select which combo to remove: " << endl;
    //unsigned int intput = atoi(input.c_str())
    //do
    //{
    cin >> input;

    unsigned int intput = atoi(input.c_str());
    if(intput < 0 || intput > combo_vector.size())
    {
        throw InvalidInput();
    }
    /*if(input - '0' >= 0 && input - '0' <= combo_vector.size() -1)
    {*/
    cout << "Are you sure you want to remove " << combo_vector[intput] << " ?" << endl;
    cout << "y/n ->";
    cin >> yes_no;
    if(yes_no == 'y' || yes_no == 'Y')
    {
        combo_vector.erase (combo_vector.begin() + (intput));
        comboToppings.erase (comboToppings.begin() + (intput));
        price_vector.erase (price_vector.begin() + (intput));
        cout << "Vector size after you removed combo" << combo_vector.size() << endl;
        for(unsigned int i = 0; i < combo_vector.size(); i++)
        {
            cout << "Combo: " << combo_vector[i] << " Price: " << price_vector[i] << endl;
        }
        cout << endl << "Saving new list to file" << endl;
        system("PAUSE");
        write_to_file_from_vector(/*combo_vector, price_vector*/);
        have_vectors_been_changed = true;
        clean_vectors();
    }
    else
    {
        cout << "Nothing has changed, " << combo_vector[intput] << " was not removed" << endl;
        //break;
    }


    //}
    /*if(!isdigit(input, loc))
    {
        cout << "Invalid input, try again" << endl;
    }*/
    // }while(intput >= 0 && intput <= combo_vector.size() -1 );
}
void ComboRepository::read_toppinglist()      /// This function is used to read from SideList.txt into the drink_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/TOPPINGS/ToppingList.txt");
    if(fin.is_open())
    {
        while((fin >> str).good())
        {
            topping_vector.push_back(str);
        }

    }
    if(!fin.is_open())
    {
        cout << "Inni i read_toppinglist (if!fin.is.open)" << endl;
        system("PAUSE");
        throw FileNotFound();
    }
    fin.close();
}

