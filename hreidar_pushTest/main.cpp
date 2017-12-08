#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void inputData(vector<string> &toppingList, vector<int> &toppingPrice){

    ifstream fin;

    string str;
    int temp;

    fin.open("DATA/TOPPINGS/ToppingList.txt");
    if(fin.fail()){
        cerr << "Error opening file" <<endl;
    }
    else{
        while(fin >> str){
            toppingList.push_back(str);
        }
        fin.close();
    }

    fin.open("DATA/TOPPINGS/ToppingPrice.txt");
    if(fin.fail()){
        cerr << "Error opening file" <<endl;
    }
    else{
        while(fin >> temp){
            toppingPrice.push_back(temp);
        }
        fin.close();
    }
}

void selectToppings(vector<string> &toppingList, vector<int> &toppingPrice,
                    vector<string> &selectedToppings, int &total)
{
    bool done = false;
    int input;
    int limit = toppingList.size();

    do{
        for(int i = 0; i < limit; i++){
            cout << "Case "<< (i + 1)<< ": " << toppingList.at(i) << endl;
        }
        cin >> input;
        if(input >= 1 && input <= (limit - 1)){
            selectedToppings.push_back(toppingList.at((input - 1)));
            total += toppingPrice.at(input - 1);
        }
        else if(input == limit){
            done = true;
        }
        else{
            cout << "Not valid option..." <<endl;
        }
        system("cls");

    }while(!done);

}

int main()
{
    vector<string> toppingList;
    vector<int> toppingPrice;
    vector<string> selectedToppings;
    int total = 0;

    inputData(toppingList, toppingPrice);



    selectToppings(toppingList, toppingPrice, selectedToppings, total);


    cout <<"1 Pizza med: ";
    for(unsigned int i = 0; i < selectedToppings.size(); i++){
        cout << selectedToppings.at(i)<< ", ";
    }
    cout << "total is: " << total;

    return 0;
}
