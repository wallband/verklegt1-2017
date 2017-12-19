#include "DrinkRepository.h"

DrinkRepository::DrinkRepository()
{
    have_vectors_been_changed = false;
}
void DrinkRepository::clean_vectors()
{
    drink_vector.clear();
    price_vector.clear();
}
void DrinkRepository::read_drinklist()      /// This function is used to read from DrinkList.txt into the drink_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/DRINKS/DrinkList.txt");
    if(fin.is_open())
    {
        while((fin >> str).good())
        {
            drink_vector.push_back(str);
        }

    }
    if(!fin.is_open())
    {
        cout << "Inni i read_drinklist (if!fin.is.open)" << endl;
        system("PAUSE");
        /* fstream fout;
         fout.open("DATA/DRINKS/DrinkList.txt");
         fout.close();*/
        throw FileNotFound();
    }
    fin.close();
}
void DrinkRepository::read_drinkpricelist()     /// This function is used to read from Drinkprice.txt into the price_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/DRINKS/DrinkPrice.txt");
    if(fin.is_open())
    {
        while((fin >> str).good())
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
void DrinkRepository::write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/)
{

    // string str1, str2;
    //remove ("DATA/DRINKS/DrinkList.txt");
    fstream fout;
    fout.open("DATA/DRINKS/DrinkList.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < drink_vector.size(); i++)                      /// I use this functino to write the modified drink menu to the DrinkList.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << drink_vector[i] << " to file:" << '\n' ;
        fout << drink_vector[i] << '\n';

    }
    fout.close();
    //remove ("DATA/DRINKS/DrinkPrice.txt");
    fstream fout2;
    fout2.open("DATA/DRINKS/DrinkPrice.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < price_vector.size(); i++)                      /// I use this functino to write the modified drink price to the DrinkPrice.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << price_vector[i] << " to file:" << '\n' ;
        fout2 << price_vector[i] << '\n';
    }
    fout2.close();
    system("PAUSE");



}
void DrinkRepository::add_drink_to_drinklist()              /// I use this function to enter a new drink into the DrinkList.txt file ///
{
    /// using input from the user. ///

    check_vectors();
    /*if(drink_vector.size() == 0)
    {
        read_drinklist();
    }*/
    /*cout << "Price vector is size = " << price_vector.size() << endl;
    if(price_vector.size() == 0)
    {
        read_drinkpricelist();
    }*/
    string name, price;
    int vector_size = drink_vector.size();
    int price_size = price_vector.size();
    cout << "Enter name for new drink " << endl;
    cin >> ws;
    getline(cin,name);
    drink_vector.resize(vector_size + 1);
    drink_vector.insert(drink_vector.end() -2, name);

    cout << "Enter price for new drink " << endl;
    cin >> price;
    price_vector.resize(price_size + 1);
    price_vector.insert(price_vector.end() -2, price);

    write_to_file_from_vector(/*drink_vector, price_vector*/);
}
void DrinkRepository::check_vectors()                                       ///Check if vectors are empty or if they have changed since they were loaded last.
{
    /// if the files have been changed they are reloaded to the vectors.
    if(drink_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Drinklist empty, reading from file" << endl;
        read_drinklist();
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

void DrinkRepository::remove_drink_from_drinklist()                             ///Remove a selected drink from the list of available drinks.
{
    string input;
    char yes_no;
    locale loc;
    check_vectors();
    cout << "Drink vector is size = " << drink_vector.size() << endl;

    for(unsigned int i = 0; i < drink_vector.size() - 1; i++)
    {
        cout << " " << i << ": " << drink_vector[i] << endl;
    }
    cout << "Please select which drink to remove: " << endl;
    //unsigned int intput = atoi(input.c_str())
    //do
    //{
    cin >> input;

    unsigned int intput = atoi(input.c_str());
    if(intput < 0 || intput > drink_vector.size())
    {
        cout << "Throw 2";
        throw InvalidInput();
    }
    /*if(input - '0' >= 0 && input - '0' <= drink_vector.size() -1)
    {*/


    cout << "Are you sure you want to remove " << drink_vector[intput] << " ?" << endl;
    cout << "y/n ->";
    cin >> yes_no;
    if(yes_no == 'y' || yes_no == 'Y')
    {
        drink_vector.erase (drink_vector.begin() + (intput));
        price_vector.erase (price_vector.begin() + (intput));
        cout << "Vector size after you removed drink" << drink_vector.size() << endl;
        for(unsigned int i = 0; i < drink_vector.size(); i++)
        {
            cout << "Drink: " << drink_vector[i] << " Price: " << price_vector[i] << endl;
        }
        cout << endl << "Saving new list to file" << endl;
        system("PAUSE");
        write_to_file_from_vector(/*drink_vector, price_vector*/);
        have_vectors_been_changed = true;
        clean_vectors();
    }

    else if(yes_no == 'n' || yes_no == 'N')
    {
        cout << "Nothing has changed, " << drink_vector[intput] << " was not removed" << endl;
        //  break;
    }
    else
    {
        throw InvalidInput();
    }



    //}
    /*if(!isdigit(input, loc))
    {
        cout << "Invalid input, try again" << endl;
    }*/
    // }while(intput >= 0 && intput <= drink_vector.size() -1 );
}


