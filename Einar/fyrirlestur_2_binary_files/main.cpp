#include <iostream>
#include <fstream>
using namespace std;
class DataClass{

private:
    int i;
    double d;
    string str;
    char c;
    bool verbose;


public:

    DataClass() {
    i = 0;
    d =0.0;
    str = "";
    c = 'c';
    verbose = 1;;
    }


    friend istream& operator >>(istream& in, DataClass& data) {
        cout << "Enter integer";
        in >> data.i;

         cout << "Enter real number";
        in >> data.d;

         cout << "Enter string";
        in >> data.str;

         cout << "Enter character";
        in >> data.c;


        return in;
    }

    friend istream& operator <<(ostream& out, const DataClass& data) {
        out << data.i;
        out << data.d;
        out << data.str;
        out << data.c;

        return out;
    }
};


int main()
{
    DataClass data1;
    cin >> data1;

    ofstream out;
    fout.open("text_file_DataClass.txt");
    fout << data1;
    fout.close();

    ifstream fin;
    fin.open("text_file_DataClass.txt");

    if(fin.is_open()) {
        fin >> data;
    }

    return 0;
}
