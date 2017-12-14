#include "ToppingRepository.h"

ToppingRepository::ToppingRepository()
{
    have_vectors_been_changed = false;
}


void ToppingRepository::clean_vectors()
{
    topping_vector.clear();
    price_vector.clear();
}
void ToppingRepository::read_toppinglist()      /// This function is used to read from SideList.txt into the drink_vector ///
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
void ToppingRepository::read_toppingpricelist()     /// This function is used to read from Sideprice.txt into the price_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/TOPPINGS/ToppingPrice.txt");
    if(fin.is_open())
    {
        while((fin >> str).good())
        {
            price_vector.push_back(str);
        }
    }
    if(!fin.is_open())
    {
        throw FileNotFound();
    }
    fin.close();
}
void ToppingRepository::write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/)
{

    // string str1, str2;
    //remove ("DATA/DRINKS/DrinkList.txt");
    fstream fout;
    fout.open("DATA/TOPPINGS/ToppingList.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < topping_vector.size(); i++)                      /// I use this functino to write the modified side-dish menu to the SideList.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << topping_vector[i] << " to file:" << '\n' ;
        fout << topping_vector[i] << '\n';

    }
    fout.close();
    //remove ("DATA/DRINKS/DrinkPrice.txt");
    fstream fout2;
    fout2.open("DATA/TOPPINGS/ToppingPrice.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < price_vector.size(); i++)                      /// I use this functino to write the modified price to the SidePrice.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << price_vector[i] << " to file:" << '\n' ;
        fout2 << price_vector[i] << '\n';
    }
    fout2.close();



}
void ToppingRepository::add_topping_to_topping_list()
{
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
    int vector_size = topping_vector.size();
    int price_size = price_vector.size();
    cout << "Enter name for new topping " << endl;
    cin >> ws;
    getline(cin,name);
    topping_vector.resize(vector_size + 1);
    topping_vector.insert(topping_vector.end() -2, name);

    cout << "Enter price for new dish " << endl;
    cin >> price;
    price_vector.resize(price_size + 1);
    price_vector.insert(price_vector.end() -2, price);

    write_to_file_from_vector(/*topping_vector, price_vector*/);
}
void ToppingRepository::remove_topping_from_topping_list()
{
    string input;
    char yes_no;
    locale loc;
    check_vectors();
    cout << "Price vector is size = " << price_vector.size() << endl;

    for(unsigned int i = 0; i < topping_vector.size() - 1; i++)
    {
        cout << " " << i << ": " << topping_vector[i] << endl;
    }
    cout << "Please select which topping to remove: " << endl;
    //unsigned int intput = atoi(input.c_str())
    //do
    //{
    cin >> input;

    unsigned int intput = atoi(input.c_str());
    if(intput < 0 || intput > topping_vector.size() || intput == topping_vector.size() -1)
    {
        throw InvalidInput();
    }
    /*if(input - '0' >= 0 && input - '0' <= topping_vector.size() -1)
    {*/
    cout << "Are you sure you want to remove " << topping_vector[intput] << " ?" << endl;
    cout << "y/n ->";
    cin >> yes_no;
    if(yes_no == 'y' || yes_no == 'Y')
    {
        topping_vector.erase (topping_vector.begin() + (intput));
        price_vector.erase (price_vector.begin() + (intput));
        cout << "List size after you removed topping: " << topping_vector.size() << endl;
        for(unsigned int i = 0; i < topping_vector.size(); i++)
        {
            cout << "Topping: " << topping_vector[i] << "-- Price: " << price_vector[i] << endl;
        }
        cout << endl << "Saving new list to file" << endl;
        system("PAUSE");
        write_to_file_from_vector(/*topping_vector, price_vector*/);
        have_vectors_been_changed = true;
        clean_vectors();
    }
    else
    {
        cout << "Nothing has changed, " << topping_vector[intput] << " was not removed" << endl;
        //break;
    }


    //}
    /*if(!isdigit(input, loc))
    {
        cout << "Invalid input, try again" << endl;
    }*/
    // }while(intput >= 0 && intput <= drink_vector.size() -1 );
    system("PAUSE");
}
void ToppingRepository::check_vectors()
{
    if(topping_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Topping list empty, reading from file" << endl;
        read_toppinglist();
        have_vectors_been_changed = false;
    }
    if(price_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Pricelist empty, reading from file" << endl;
        read_toppingpricelist();
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

