#include <iostream>
#include <string>
#include "Superhero.h"

using namespace std;

int main()
{
    char input;

    cout << "Welcome, please select:" << endl;

    while ((input != 'q') || (input != 'Q')) {

        cout << endl <<  "Make a new hero (M)" << endl;
        cout << "View list of heroes in registry (L)" << endl;
        cout << "Quit program (Q)" << endl;


        cout << ":";
        cin >> input;

        if(input =='m' || input == 'M') {
            string name;
            ofstream fout;
            fout.open("SuperHeroes.txt", ios::app);
            Superhero superhero;
            cout << endl;
            cin >> superhero;
            fout << superhero;
            fout.close();

        }

        else if(input =='l' || input == 'L') {
            ifstream fin;
            string str;
            fin.open("Superheroes.txt");
            if(fin.is_open()) {
                while(!fin.eof()){
                    getline(fin,str);
                    cout << endl;
                    cout << str << endl;
                } fin.close();
            }

            else {
                cout << "File not found" << endl;
            }
        }

        else if(input =='q' || input == 'Q') {
            return 0;
        }

        else {
            cout << "Selection not valid, please try again" << endl;
        }
    }
    return 0;
}
