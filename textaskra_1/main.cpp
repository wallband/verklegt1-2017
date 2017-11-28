#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int COUNTER = 0;
int number_of_lines();
int main()
{
    string str;
    ifstream fin;
    char input = 'y';


    fin.open("textFile.txt");
    cout << "Here are the first 10 lines from your .txt file, which contains " << number_of_lines() << " lines" << endl;
    cout << "---------------------" << endl;
    if (fin.is_open()) {
        for(int i = 0; i <10 ; i++) {
            getline(fin, str);
            cout << str << endl;
            COUNTER ++;
        }
    cout << "---------------------" << endl;
    cout << "Read the next 10 lines? y/n ";
    cin >> input;
    cout << "---------------------" << endl;

    while(!fin.eof() && COUNTER < number_of_lines()){
            if (input == 'y' || input == 'Y'){
                for(int i = 0; i <= 10 ; i++) {

                getline(fin, str);
                cout << str << endl;
                COUNTER ++;

                    if(COUNTER == number_of_lines()){
                        cout << "------NO MORE LINES------" << endl << endl;
                        return 0;
                    }
                }
                cout << "---------------------" << endl;
            }

        else if (input == 'n' || input =='N'){
            cout << endl << endl;
            cout << "-- User exited the program --" << endl;
            return 0;
        }

            else if (cout << "Invalid input" << endl){
                while ((input != 'y') || (input != 'Y') || (input != 'n') || (input != 'N')){
                cout << "---------------------" << endl;
                cout << "Read the next 10 lines? y/n ";
                cin >> input;
                cout << "---------------------" << endl;
                    if (input == 'y' || input == 'Y'){
                        for(int i = 0; i <= 10 ; i++) {
                            getline(fin, str);
                            cout << str << endl;
                            COUNTER ++;

                            if(COUNTER == number_of_lines()){
                                cout << "------NO MORE LINES------" << endl << endl;
                                return 0;
                            }
                        }
                    }
                    else if (input == 'n' || input == 'N'){
                        cout << endl << endl;
                        cout << "-- User exited the program --" << endl;
                        return 0;
                    }
                    else {

                        cout << "Invalid input" << endl;

                    }
                }
            }

                cout << "Read the next 10 lines? y/n ";
                cin >> input;
                cout << "---------------------" << endl;
        }
    }

        fin.close();

    if (!fin.is_open()){
        cout << "Unable to read from file" << endl;
    }
    return 0;
}
int number_of_lines() {
  int number_of_lines = 0;
    string str;
    ifstream fin("textFile.txt");

    while (getline(fin, str))
        ++number_of_lines;

    return number_of_lines;

}

