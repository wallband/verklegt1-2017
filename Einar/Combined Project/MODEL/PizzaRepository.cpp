#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    total = 0;
}

void PizzaRepository::init(){

    listOfToppings.clear();
    listOfToppingPrice.clear();
    listOfDrinks.clear();
    listOfDrinkPrice.clear();
    string str;
    int temp;

    ifstream fin;

    fin.open("DATA/TOPPINGS/ToppingList.txt");

    if(fin.fail()){

        cerr << "Error opening toppinglist file!" << endl;
    }
    else{

        while(fin >> str){
            listOfToppings.push_back(str);
        }
        fin.close();
    }

    fin.open("DATA/TOPPINGS/ToppingPrice.txt");

    if(fin.fail()){

        cerr << "Error opening toppingprice file!" << endl;
    }
    else{

        while(fin >> temp){
            listOfToppingPrice.push_back(temp);
        }
        fin.close();
    }

    fin.open("DATA/DRINKS/DrinkList.txt");

    if(fin.fail()){

        cerr << "Error opening drinklist file!" << endl;
    }
    else{

        while(fin >> str){
            listOfDrinks.push_back(str);
        }
        fin.close();
    }

    fin.open("DATA/DRINKS/DrinkPrice.txt");

    if(fin.fail()){

        cerr << "Error opening drinkprice file!" << endl;
    }
    else{

        while(fin >> temp){
            listOfDrinkPrice.push_back(temp);
        }
        fin.close();
    }
}
void PizzaRepository::orderTotal(int money){

    total += money;
}

int PizzaRepository::get_Total(){
    return this -> total;
}

void PizzaRepository::addPizza(string str){


}

void PizzaRepository::storePizza(string pizza, int items){

    if(items == 0){
        pizza += " Margharita";
    }
    addVectorString(pizza);
}

void PizzaRepository::saveOrder(){

    //cout << OrderList.at(0);
    for(unsigned int i = 0; i < OrderList.size(); i++){
        cout <<"  - " << OrderList.at(i) << endl;
    }

}

void PizzaRepository::readToppings(){

}
int PizzaRepository::readDrinks(){

    bool done = false;
    string str = "";
    int drinks = 0;
    int input;
    int limit = listOfDrinks.size();

    do{
        system("cls");

        drinksHeader();

        for(int i = 0; i < limit; i++){
            cout << " " << (i + 1) << ": " << listOfDrinks.at(i) << endl;
        }
        cout <<"\n Selected drinks: " << str << endl;
        cin >> input;

        if(input >= 1 && input <= (limit - 1)){

            str += listOfDrinks.at((input - 1)) + " ";
            total += listOfDrinkPrice.at((input - 1));
            addVectorString(listOfDrinks.at((input - 1)));
            drinks++;

        }
        else if(input == limit){
            done = true;
        }
    }while(!done);
    return drinks;
}

void PizzaRepository::addVectorString(string str){

    OrderList.push_back(str);
}

void PizzaRepository::input_Toppings(string str){

    string finished_pizza = str;
    bool done = false;
    int input;
    int items = 0;
    int limit = listOfToppings.size();

    do{
        system("cls");

        toppingHeader();
        for(int i = 0; i < limit; i++){
            cout << " "<< (i + 1)<< ": " << listOfToppings.at(i) << endl;
        }
        //cout <<"\nItem nr " << input <<" is not a valid option..." <<endl;
        cout <<"\n" << finished_pizza << endl;
        cin >> input;

        if(input >= 1 && input <= (limit - 1)){
            //OrderList.push_back(listOfToppings.at((input - 1)));
            finished_pizza += (" " + (listOfToppings.at((input - 1))));
            total += listOfToppingPrice.at(input - 1);
            items++;

        }
        else if(input == limit){
            done = true;
        }

    }while(!done);
    //system("pause");
    storePizza(finished_pizza, items);
}

void PizzaRepository::toppingHeader(){

    cout << "-----------------------" << endl;
    cout << "    Select toppings" << endl;
    cout << "-----------------------" << endl;
}
void PizzaRepository::drinksHeader(){

    cout << "-----------------------" << endl;
    cout << "     Select drinks" << endl;
    cout << "-----------------------" << endl;
}
