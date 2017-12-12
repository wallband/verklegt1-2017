#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main()
{   ofstream fout();
    fout.open("DataTextFile.txt");

        fout <<< "Integer Value" << 5 << endl;
        fout << "Double Value" << 4.00 << endl;
        cout << "Double Value" << 4.00 << endl;

    fout.close();

    string c;
    ifstream fin;
    fin.open("DataTextFile.txt");
    if(fin.is_open()) {
        while(!fin.eof) {
            getline(fin, str)

        }
    }
    return 0;
}
