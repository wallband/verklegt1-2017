#include "SideDishRepository.h"

SideDishRepository::SideDishRepository()
{
    have_vectors_been_changed = false;
}
void SideDishRepository::clean_vectors()
{
    dish_vector.clear();
    price_vector.clear();
}
void SideDishRepository::read_dishlist()      /// This function is used to read from SideList.txt into the dish_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/SIDE/SideList.txt");
    if(fin.is_open())
    {
        while((fin >> str).good())
        {
            dish_vector.push_back(str);
        }

    }
    if(!fin.is_open())
    {
        cout << "Inni i read_dishlist (if!fin.is.open)" << endl;
        system("PAUSE");
        throw FileNotFound();
    }
    fin.close();
}
void SideDishRepository::read_dishpricelist()     /// This function is used to read from Sideprice.txt into the price_vector ///
{
    ifstream fin;
    string str;
    fin.open("DATA/SIDE/SidePrice.txt");
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
void SideDishRepository::write_to_file_from_vector(/*vector<string> &drink, vector<string> &price*/)
{

    // string str1, str2;
    //remove ("DATA/DRINKS/DrinkList.txt");
    fstream fout;
    fout.open("DATA/SIDE/SideList.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < dish_vector.size(); i++)                      /// I use this functino to write the modified side-dish menu to the SideList.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << dish_vector[i] << " to file:" << '\n' ;
        fout << dish_vector[i] << '\n';

    }
    fout.close();
    //remove ("DATA/DRINKS/DrinkPrice.txt");
    fstream fout2;
    fout2.open("DATA/SIDE/SidePrice.txt", ios::out|ios::trunc);
    for(unsigned int i = 0; i < price_vector.size(); i++)                      /// I use this functino to write the modified price to the SidePrice.txt ///
    {
        /// and the DrinkPrice.txt files. ///
        cout << "Writing " << price_vector[i] << " to file:" << '\n' ;
        fout2 << price_vector[i] << '\n';
    }
    fout2.close();
    system("PAUSE");


}
void SideDishRepository::add_dish_to_side_dish_list()                   /// Adds a side-dish to the side dish menu. Input by the user.
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
    int vector_size = dish_vector.size();
    int price_size = price_vector.size();
    cout << "Enter name for new side-dish " << endl;
    cin >> ws;
    getline(cin,name);

    dish_vector.resize(vector_size + 1);
    dish_vector.insert(dish_vector.end() -2, name);

    cout << "Enter price for new dish " << endl;
    cin >> price;
    price_vector.resize(price_size + 1);
    price_vector.insert(price_vector.end() -2, price);

    write_to_file_from_vector(/*dish_vector, price_vector*/);
}
void SideDishRepository::remove_dish_from_side_dish_list()              ///Removes a side-dish from the side-dish menu. Selected by the user.
{
    string input;
    char yes_no;
    locale loc;
    check_vectors();
    cout << "Price vector is size = " << price_vector.size() << endl;

    for(unsigned int i = 0; i < dish_vector.size() - 1; i++)
    {
        cout << " " << i << ": " << dish_vector[i] << endl;
    }
    cout << "Please select which side-dish to remove: " << endl;
    //unsigned int intput = atoi(input.c_str())
    //do
    //{
    cin >> input;

    unsigned int intput = atoi(input.c_str());
    if(intput < 0 || intput > dish_vector.size() || intput == dish_vector.size() -1)
    {
        throw InvalidInput();
    }
    /*if(input - '0' >= 0 && input - '0' <= dish_vector.size() -1)
    {*/
    cout << "Are you sure you want to remove " << dish_vector[intput] << " ?" << endl;
    cout << "y/n ->";
    cin >> yes_no;
    if(yes_no == 'y' || yes_no == 'Y')
    {
        dish_vector.erase (dish_vector.begin() + (intput));
        price_vector.erase (price_vector.begin() + (intput));
        cout << "List size after you removed side-dish: " << dish_vector.size() << endl;
        for(unsigned int i = 0; i < dish_vector.size(); i++)
        {
            cout << "Dish: " << dish_vector[i] << "-- Price: " << price_vector[i] << endl;
        }
        cout << endl << "Saving new list to file" << endl;
        system("PAUSE");
        write_to_file_from_vector(/*dish_vector, price_vector*/);
        have_vectors_been_changed = true;
        clean_vectors();
    }
    else
    {
        cout << "Nothing has changed, " << dish_vector[intput] << " was not removed" << endl;
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
void SideDishRepository::check_vectors()                                            ///Check if vectors are empty or if they have changed since they were loaded last.
{                                                                                   /// if the files have been changed they are reloaded to the vectors.
    if(dish_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Side-dish list empty, reading from file" << endl;
        read_dishlist();
        have_vectors_been_changed = false;
    }
    if(price_vector.size() == 0 || have_vectors_been_changed == true)
    {
        cout << "Pricelist empty, reading from file" << endl;
        read_dishpricelist();
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
