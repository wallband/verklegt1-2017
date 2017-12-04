#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class items{

private:
    vector<items> itemList;

public:
    string name;
    int price;


};

int main()
{

    ifstream fin;

    fin.open("Toppings.txt");

    string item;
    int price;
    int counter = 0;
    if(fin.fail()){
        cerr << "Error opening file" << endl;
        return 0;
    }
    while(!fin.eof()){
        fin >> item >> price;
        cout << item << ", Price: " << price << endl;
        counter++;
    }
    cout << counter << " items in list";
    fin.close();
    return 0;
}
