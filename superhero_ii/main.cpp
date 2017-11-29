#include <iostream>
#include <fstream>
#include <string>
#include "Superhero.h"
using namespace std;


int main()
{
    Superhero hero;
    char input;


    while(input != 'q' || input != 'Q'){
        hero.prompt_user();
        cout << "->" ; cin >> input;

    if(input == 'w' || input == 'W'){ /// Lesið í skrá.
       hero.write_to_file();
    }
        else if(input == 'r' || input == 'R') { /// Lesið úr skrá og prentað á skjá
            hero.read_from_file();
        }
            else if(input == 'q' || input == 'Q'){ ///Til að drepa forrit
                return 0;
            }
                else {///Ef input er rangt.
                    cout << "Invalid input, please try again" << endl;
                }

    }





    return 0;
}
