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
        int lines = count_lines("DATA/COMBO/ComboName");
        /*for(int i = 0; i < lines; i++)
        {
            Combo combo;
            fin >> str;
            combo.set_name(str);
            while(getline(fin,str,'\n'))
            {
                combo.list_of_toppings.push_back(str);
            }
            combo_vector.push_back(combo);
        }*/
        Combo combo;
            while(fin >> str)
            {
                combo.set_name(str);
                getline(fin, str, ',');
                combo.list_of_toppings.push_back(str);
                combo_vector.push_back(combo);
            }
            //combo_vector.push_back(combo);
            //delete combo;


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
    cout << "Combo vector is size: " << combo_vector.size() << endl;
    for(unsigned int i = 0; i < combo_vector.size(); i++)
    {
        cout << i << " : Name = " << combo_vector[i].get_name();
        for(unsigned int j = 0; j < combo_vector[i].list_of_toppings[i].size(); j++)
        {
            cout << " with toppings nr " << j << " : " << combo_vector[i].list_of_toppings[j];
        }
        cout << endl;
    }
}
void ComboRepository::read_drinkpricelist()     /// This function is used to read from Drinkprice.txt into the price_vector ///
{
    ifstream fin;
    string str;
    int i = 0;
    unsigned int price;
    fin.open("DATA/COMBO/ComboPrice.txt");
    if(fin.is_open())
    {
        while(fin >> str)
        {
            price = atoi(str.c_str());
            //combo_vector[i].set_price(price);
            price_vector.push_back(str);
            //i++;
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
    for(unsigned int i = 0; i < combo_vector.size(); i++)                      /// I use this functino to write the modified drink menu to the DrinkList.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << combo_vector[i].get_name() << " to file:" << '\n' ;
        fout << combo_vector[i].get_name();
        for(int j = 0; j < combo_vector[i].get_topping_vector_size(); j++)
        {
            cout << "," << combo_vector[i].list_of_toppings[j];
        }
        cout << endl;
    }

    fout.close();
    //remove ("DATA/DRINKS/DrinkPrice.txt");
    fstream fout2;
    fout2.open("DATA/COMBO/ComboPrice.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < price_vector.size(); i++)                      /// I use this functino to write the modified drink menu to the DrinkList.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << combo_vector[i].get_price() << " to file:" << '\n' ;
        fout2 << combo_vector[i].get_price() << '\n';
    }
    fout2.close();



}
void ComboRepository::add_combo_to_list()              /// I use this function to enter a new drink into the DrinkList.txt file ///
{                                                           /// using input from the user. ///

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
    string name, price, input;
    Combo combo1;
    int intprice = 0;
    int vector_size = combo_vector.size();
    int price_size = price_vector.size();
    cout << "Enter name for new drink " << endl;
    cin >> ws;
    getline(cin,name);
    combo1.set_name(name);
    while(input != "q" || input != "Q")
    {
        cout << "Type in topping for your new combo named: " << combo1.get_name() << endl;
        cout << "Enter 'q' to exit." << endl;
        cin >> input;
        combo1.list_of_toppings.push_back(input);
    }
    combo_vector.resize(vector_size + 1);

    combo_vector.insert(combo_vector.end() -2, combo1);
    cout << "Enter price for new drink " << endl;               // TODO (einar#1#12/13/17): Kominn hingað.  Redda Combo
    cin >> intprice;
    price_vector.resize(price_size + 1);
    price_vector.insert(price_vector.end() -2, price);

    write_to_file_from_vector(/*combo_vector, price_vector*/);
}
void ComboRepository::check_vectors()
{
    if(combo_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Combolist empty, reading from file" << endl;
        read_combolist();
        have_vectors_been_changed = false;
    }
    if(price_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Pricelist empty, reading from file" << endl;
        read_drinkpricelist();
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
    cout << "Price vector is size = " << price_vector.size() << endl;

    for(unsigned int i = 0; i < combo_vector.size() - 1; i++)
    {
        cout << " " << i << ": " << combo_vector[i].get_name() << endl;
    }
    cout << "Please select which drink to remove: " << endl;
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
    cout << "Are you sure you want to remove " << combo_vector[intput].get_name() << " ?" << endl;
    cout << "y/n ->";
    cin >> yes_no;
    if(yes_no == 'y' || yes_no == 'Y')
    {
        combo_vector.erase (combo_vector.begin() + (intput));
        price_vector.erase (price_vector.begin() + (intput));
        cout << "Vector size after you removed combo" << combo_vector.size() << endl;
        for(unsigned int i = 0; i < combo_vector.size(); i++)
        {
            cout << "Combo: " << combo_vector[i].get_name() << " Price: " << price_vector[i] << endl;
        }
        cout << endl << "Saving new list to file" << endl;
        system("PAUSE");
        write_to_file_from_vector(/*combo_vector, price_vector*/);
        have_vectors_been_changed = true;
        clean_vectors();
    }
    else
    {
        cout << "Nothing has changed, " << combo_vector[intput].get_name() << " was not removed" << endl;
        //break;
    }


    //}
    /*if(!isdigit(input, loc))
    {
        cout << "Invalid input, try again" << endl;
    }*/
    // }while(intput >= 0 && intput <= combo_vector.size() -1 );
}
int ComboRepository::count_lines(string filename)
{
    ifstream fin;
    string str;
    int counter = 0;
    fin.open(filename + ".txt");

    while (getline(fin,str))
	{
        ++counter;
	}
	return counter;
}

