#include "../REPO/PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    total = 0;
    totalPizza = 0;
    totalDrink = 0;
    totalSides = 0;
    phoneNr = "";
    stateOfPizza = '1';
}
void PizzaRepository::clearMem()
{
    OrderList.clear();
}
void PizzaRepository::orderTotal(int money)
{

    total += money;
}

int PizzaRepository::get_Total()
{
    return this -> total;
}

int PizzaRepository::numOfItems()
{
    return OrderList.size();
}

int PizzaRepository::getTotalPizza()
{
    return this -> totalPizza;
}
int PizzaRepository::getTotalDrink()
{
    return this -> totalDrink;
}
int PizzaRepository::getTotalSides()
{
    return this -> totalSides;
}
string PizzaRepository::getPhoneNr()
{
    return this -> phoneNr;
}
char PizzaRepository::getPizzaStatus()
{
    return this -> stateOfPizza;
}

void PizzaRepository::newTotal(int totalPrice)
{
    this -> total = totalPrice;
}
void PizzaRepository::newTotalPizza(int Pizza)
{
    this -> totalPizza = Pizza;
}
void PizzaRepository::newTotalDrink(int Drink)
{
    this ->totalDrink = Drink;
}
void PizzaRepository::newTotalSides(int Sides)
{
    this -> totalSides = Sides;
}
void PizzaRepository::newPhoneNr(string phone)
{
    this -> phoneNr = phone;
}
void PizzaRepository::newPizzaStatus(char pizzaState)
{
    this -> stateOfPizza = pizzaState;
}

string PizzaRepository::whatPizzaState(char s)
{

    if(s == '1')
    {
        return "In preperation";
    }
    if(s == '2')
    {
        return "In Oven";
    }
    if(s == '3')
    {
        return "Ready";
    }
    if(s == '4')
    {
        return "Paid";
    }
    else
    {
        return "Not valid state";
    }
}

void PizzaRepository::storePizza(string pizza, int items)
{

    if(items == 0)
    {
        pizza += " Margharita";
    }
    addVectorString(pizza);
}

void PizzaRepository::printOrder()
{

    for(unsigned int i = 0; i < OrderList.size(); i++)
    {
        int length = OrderList.at(i).length();
        if(length > 0)
        {
            cout <<"  - " << OrderList.at(i) << endl;
        }
    }
}

void PizzaRepository::saveOrder(int file, string phone)
{

    //cout << "save to file nr "<< file << endl;
    //system("pause");

    OrderRepo.saveOrder(file, OrderList, phone, getTotalPizza(), getTotalDrink(), getTotalSides(), get_Total(), getPizzaStatus());
}

void PizzaRepository::loadOrder(int file)
{

    string phone, temp;
    char pizzaState;
    int pizza, drink, side, totalPrice;

    ifstream fin;
    string fileNr = OrderRepo.numToString(file);
    string fileName = "DATA/ORDER/order" + fileNr + ".txt";
    fin.open(fileName.c_str());
    //cout << "open " << fileName <<endl;
    //system("pause");
    if(fin.fail())
    {
        cerr << "Error opening file " + fileName <<endl;
        //system("pause");
    }
    else
    {
        fin >> phone >> pizzaState >> pizza >> drink >> side >> totalPrice;
        newPhoneNr(phone);
        newPizzaStatus(pizzaState);
        newTotalPizza(pizza);
        newTotalDrink(drink);
        newTotalSides(side);
        newTotal(totalPrice);
        /*
                cout <<"phone: " << getPhoneNr() <<", pizzaState: " << getPizzaStatus();
                cout << ", pizza: " << getTotalPizza();
                cout <<", drink: " << getTotalDrink();
                cout << ", side: " << getTotalSides();
                cout <<", Total price: " << get_Total() << endl;
                system("pause");
                */
        while(!fin.eof())
        {
            getline(fin, temp);
            OrderList.push_back(temp);
            if(fin.eof())
            {
                break;
            }
        }
        fin.close();
    }
}
void PizzaRepository::input_Drinks()
{

    bool done = false;
    string str = "";
    string input;
    int inputNR;
    init();
    int limit = listOfDrinks.size();

    do
    {
        system("cls");

        drinksHeader();

        for(int i = 0; i < limit; i++)
        {
            cout << " " << (i + 1) << ": " << listOfDrinks.at(i) << endl;
        }
        cout <<"\n Selected drinks: " << str << endl;
        cin >> input;
        inputNR = atoi(input.c_str());

        if(inputNR >= 1 && inputNR <= (limit - 1))
        {

            str += listOfDrinks.at((inputNR - 1)) + " ";
            total += listOfDrinkPrice.at((inputNR - 1));
            addVectorString(listOfDrinks.at((inputNR - 1)));
            totalDrink++;
        }
        else if(inputNR == limit)
        {
            done = true;
        }
    }
    while(!done);
}

void PizzaRepository::input_Sides()
{

    bool done = false;
    string str = "";
    string input;
    int inputNR;
    init();
    int limit = listOfSides.size();

    do
    {
        system("cls");

        sidesHeader();

        for(int i = 0; i < limit; i++)
        {
            cout << " " << (i + 1) << ": " << listOfSides.at(i) << endl;
        }
        cout <<"\n Selected sides: " << str << endl;
        cin >> input;
        inputNR = atoi(input.c_str());

        if(inputNR >= 1 && inputNR <= (limit - 1))
        {

            str += listOfSides.at((inputNR - 1)) + " ";
            total += listOfSidesPrice.at((inputNR - 1));
            addVectorString(listOfSides.at((inputNR - 1)));
            totalSides++;

        }
        else if(inputNR == limit)
        {
            done = true;
        }
    }
    while(!done);
}

void PizzaRepository::input_Toppings(string str)
{

    string finished_pizza = str;
    bool done = false;
    string input = "";
    int inputNR;
    int items = 0;
    init();
    int limit = listOfToppings.size();

    do
    {
        system("cls");

        toppingHeader();
        for(int i = 0; i < limit; i++)
        {
            cout << " "<< (i + 1)<< ": " << listOfToppings.at(i) << endl;
        }
        cout <<"\n" << finished_pizza << endl;

        cin >> input;
        inputNR = atoi(input.c_str());


        if(inputNR >= 1 && inputNR <= (limit - 1))
        {
            finished_pizza += (" " + (listOfToppings.at((inputNR - 1))));
            total += listOfToppingPrice.at(inputNR - 1);
            items++;

        }
        else if(inputNR == limit)
        {
            done = true;
        }

    }
    while(!done);
    totalPizza++;
    storePizza(finished_pizza, items);
}

string PizzaRepository::select_Combo(string str)
{
    string combo = str;
    bool done = false;
    string input = "";
    int inputNr;
    init();
    int limit = listOfCombo.size();

    do
    {
        system("cls");
        comboHeader();
        for(int i = 0; i < limit; i++)
        {
            cout <<" " << (i + 1) <<". " << listOfCombo.at(i) <<": " << comboToppings.at(i) << endl;
        }
        cin >> input;
        inputNr = atoi(input.c_str());

        if(inputNr >=1 && inputNr < limit)
        {
            combo += comboToppings.at((inputNr - 1));
            totalPizza++;
            done = true;
        }
        else if(inputNr == limit)
        {
            combo = "";
            done = true;
        }

    }
    while(!done);
    return combo;
}

void PizzaRepository::addVectorString(string str)
{

    OrderList.push_back(str);
}

///Initializer function
void PizzaRepository::init()
{

    listOfToppings.clear();
    listOfToppingPrice.clear();
    listOfDrinks.clear();
    listOfDrinkPrice.clear();
    listOfSides.clear();
    listOfSidesPrice.clear();
    listOfCombo.clear();
    comboToppings.clear();
    listOfComboPrice.clear();

    string str;
    int temp;

    ifstream fin;
    fin.open("DATA/TOPPINGS/ToppingList.txt");
    if(fin.fail())
    {
        cerr << "Error opening topping-list file!" << endl;
    }
    else
    {
        while(fin >> str)
        {
            listOfToppings.push_back(str);
        }
        fin.close();
    }
    fin.open("DATA/TOPPINGS/ToppingPrice.txt");
    if(fin.fail())
    {
        cerr << "Error opening topping-price file!" << endl;
    }
    else
    {
        while(fin >> temp)
        {
            listOfToppingPrice.push_back(temp);
        }
        fin.close();
    }
    fin.open("DATA/DRINKS/DrinkList.txt");
    if(fin.fail())
    {
        cerr << "Error opening drink-list file!" << endl;
    }
    else
    {
        while(fin >> str)
        {
            listOfDrinks.push_back(str);
        }
        fin.close();
    }
    fin.open("DATA/DRINKS/DrinkPrice.txt");
    if(fin.fail())
    {
        cerr << "Error opening drink-price file!" << endl;
    }
    else
    {
        while(fin >> temp)
        {
            listOfDrinkPrice.push_back(temp);
        }
        fin.close();
    }
    fin.open("DATA/SIDE/SideList.txt");
    if(fin.fail())
    {
        cerr << "Error opening side-list file!" << endl;
    }
    else
    {
        while(fin >> str)
        {
            listOfSides.push_back(str);
        }
        fin.close();
    }
    fin.open("DATA/SIDE/SidePrice.txt");
    if(fin.fail())
    {
        cerr << "Error opening side-price file!" << endl;
    }
    else
    {
        while(fin >> temp)
        {
            listOfSidesPrice.push_back(temp);
        }
        fin.close();
    }
    fin.open("DATA/COMBO/ComboName.txt");
    if(fin.fail())
    {
        cerr << "Error opening combo-name file!" << endl;
        system("pause");
    }
    else
    {
        while(fin >> str)
        {
            listOfCombo.push_back(str);
            getline(fin, str);
            comboToppings.push_back(str);
        }
        fin.close();
    }

    fin.open("DATA/COMBO/ComboPrice.txt");
    if(fin.fail())
    {
        cerr << "Error opening combo-price file!" << endl;
        system("pause");
    }
    else
    {
        while(fin >> temp)
        {
            listOfComboPrice.push_back(temp);
        }
        fin.close();
    }
}

///Header functions for decoration
void PizzaRepository::toppingHeader()
{

    cout << "-----------------------" << endl;
    cout << "    Select toppings" << endl;
    cout << "-----------------------" << endl;
}
void PizzaRepository::comboHeader()
{
    cout << "-----------------------" << endl;
    cout << "     Select combo" << endl;
    cout << "-----------------------" << endl;
}
void PizzaRepository::drinksHeader()
{

    cout << "-----------------------" << endl;
    cout << "     Select drinks" << endl;
    cout << "-----------------------" << endl;
}
void PizzaRepository::sidesHeader()
{

    cout << "-----------------------" << endl;
    cout << "   Select side-dish" << endl;
    cout << "-----------------------" << endl;
}
