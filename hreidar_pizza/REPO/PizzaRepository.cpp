#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    total = 0;
    totalPizza = 0;
    totalDrink = 0;
    totalSides = 0;
}

void PizzaRepository::orderTotal(int money){

    total += money;
}

int PizzaRepository::get_Total(){
    return this -> total;
}

int PizzaRepository::numOfItems(){
    return OrderList.size();
}

int PizzaRepository::getTotalPizza(){
    return this -> totalPizza;
}
int PizzaRepository::getTotalDrink(){
    return this -> totalDrink;
}
int PizzaRepository::getTotalSides(){
    return this -> totalSides;
}

void PizzaRepository::storePizza(string pizza, int items){

    if(items == 0){
        pizza += " Margharita";
    }
    addVectorString(pizza);
}

void PizzaRepository::saveOrder(){

    //printOrder(OrderList);
    //cout << "--------------------------------" << endl;
    //system("pause");
    OrderRepo.saveOrder(OrderList, getTotalPizza(), getTotalDrink(), getTotalSides(), get_Total());
}
void PizzaRepository::printOrder(){

    for(unsigned int i = 0; i < OrderList.size(); i++){
        cout <<"  - " << OrderList.at(i) << endl;
    }
}
/** //I am scared of this bit, almost ruined my program
void PizzaRepository::removeItem(){

    bool done = false;
    string input;
    int inputNR;
    //char select;
    int limit = OrderList.size();
        do{
            removeHeader();
            for(int i = 0; i < limit; i++){
                cout << (i + 1) <<": " << OrderList.at(i) << endl;
            }
            cout <<limit + 1 << ": Back" << endl;
            cin >> input;
            inputNR = atoi(input.c_str());
            if(inputNR >= 1 && inputNR <= limit){

                while(select != '2'){
                    cout << "Do you want to remove item "
                    << OrderList.at((inputNR - 1)) <<"?" << endl;
                    cout << "1: Yes" << endl;
                    cout << "2: No" << endl;
                    cin >> select;
                    if(select == '1'){
                        //int strlength = strlen(OrderList.at((inputNR - 1)));
                        int strlength = OrderList.at((inputNR - 1)).size();
                        OrderList.erase(OrderList.begin() + (inputNR - 1));
                        if(strlength > 6){ totalDrink--; }
                        else if(strlength > 11){ totalSides--; }
                        else{ totalPizza--; }
                    }
                }

            cout << "Almost done" << endl;
            }
            else if(inputNR == (limit + 1)){
                done = true;
            }

        }while(!done);
}
**/
void PizzaRepository::input_Drinks(){

    bool done = false;
    string str = "";
    string input;
    int inputNR;
    int limit = listOfDrinks.size();

    do{
        system("cls");

        drinksHeader();

        for(int i = 0; i < limit; i++){
            cout << " " << (i + 1) << ": " << listOfDrinks.at(i) << endl;
        }
        cout <<"\n Selected drinks: " << str << endl;
        cin >> input;
        inputNR = atoi(input.c_str());

        if(inputNR >= 1 && inputNR <= (limit - 1)){

            str += listOfDrinks.at((inputNR - 1)) + " ";
            total += listOfDrinkPrice.at((inputNR - 1));
            addVectorString(listOfDrinks.at((inputNR - 1)));
            totalDrink++;
        }
        else if(inputNR == limit){
            done = true;
        }
    }while(!done);
}

void PizzaRepository::input_Sides(){

    bool done = false;
    string str = "";
    string input;
    int inputNR;
    int limit = listOfSides.size();

    do{
        system("cls");

        sidesHeader();

        for(int i = 0; i < limit; i++){
            cout << " " << (i + 1) << ": " << listOfSides.at(i) << endl;
        }
        cout <<"\n Selected sides: " << str << endl;
        cin >> input;
        inputNR = atoi(input.c_str());

        if(inputNR >= 1 && inputNR <= (limit - 1)){

            str += listOfSides.at((inputNR - 1)) + " ";
            total += listOfSidesPrice.at((inputNR - 1));
            addVectorString(listOfSides.at((inputNR - 1)));
            totalSides++;

        }
        else if(inputNR == limit){
            done = true;
        }
    }while(!done);
}

void PizzaRepository::input_Toppings(string str){

    string finished_pizza = str;
    bool done = false;
    string input = "";
    int inputNR;
    int items = 0;
    int limit = listOfToppings.size();

    do{
        system("cls");

        toppingHeader();
        for(int i = 0; i < limit; i++){
            cout << " "<< (i + 1)<< ": " << listOfToppings.at(i) << endl;
        }
        cout <<"\n" << finished_pizza << endl;

        cin >> input;
        inputNR = atoi(input.c_str());


        if(inputNR >= 1 && inputNR <= (limit - 1)){
            //OrderList.push_back(listOfToppings.at((input - 1)));
            finished_pizza += (" " + (listOfToppings.at((inputNR - 1))));
            total += listOfToppingPrice.at(inputNR - 1);
            items++;

        }
        else if(inputNR == limit){
            done = true;
        }

    }while(!done);
    totalPizza++;
    storePizza(finished_pizza, items);
}

void PizzaRepository::addVectorString(string str){

    OrderList.push_back(str);
}


///Initializer function
void PizzaRepository::init(){

    listOfToppings.clear();
    listOfToppingPrice.clear();
    listOfDrinks.clear();
    listOfDrinkPrice.clear();
    listOfSides.clear();
    listOfSidesPrice.clear();
    string str;
    int temp;

    ifstream fin;

    fin.open("DATA/TOPPINGS/ToppingList.txt");

    if(fin.fail()){

        cerr << "Error opening topping-list file!" << endl;
    }
    else{

        while(fin >> str){
            listOfToppings.push_back(str);
        }
        fin.close();
    }

    fin.open("DATA/TOPPINGS/ToppingPrice.txt");

    if(fin.fail()){

        cerr << "Error opening topping-price file!" << endl;
    }
    else{

        while(fin >> temp){
            listOfToppingPrice.push_back(temp);
        }
        fin.close();
    }

    fin.open("DATA/DRINKS/DrinkList.txt");

    if(fin.fail()){

        cerr << "Error opening drink-list file!" << endl;
    }
    else{

        while(fin >> str){
            listOfDrinks.push_back(str);
        }
        fin.close();
    }

    fin.open("DATA/DRINKS/DrinkPrice.txt");

    if(fin.fail()){

        cerr << "Error opening drink-price file!" << endl;
    }
    else{

        while(fin >> temp){
            listOfDrinkPrice.push_back(temp);
        }
        fin.close();
    }

    fin.open("DATA/SIDE/SideList.txt");

    if(fin.fail()){

        cerr << "Error opening side-list file!" << endl;
    }
    else{

        while(fin >> str){
            listOfSides.push_back(str);
        }
        fin.close();
    }

    fin.open("DATA/SIDE/SidePrice.txt");

    if(fin.fail()){

        cerr << "Error opening side-price file!" << endl;
    }
    else{

        while(fin >> temp){
            listOfSidesPrice.push_back(temp);
        }
        fin.close();
    }
}

///Header functions for decoration
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
void PizzaRepository::sidesHeader(){

    cout << "-----------------------" << endl;
    cout << "   Select side-dish" << endl;
    cout << "-----------------------" << endl;
}
