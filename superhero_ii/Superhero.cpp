#include "Superhero.h"
#include <iostream>
#include <stddef.h>
#include <fstream>
using namespace std;

Superhero::Superhero()
{
     _name[0] = '\0';
        _age = 0;
        _superpower = 'n';
    //ctor
}

Superhero::~Superhero()
{
    //dtor
}
    /*Superhero::Superhero(){
        _name[0] = '\0';
        _age = 0;
        _superpower = 'n';
    }*/

    Superhero::Superhero(char name, int age, char superpower) {
        _name[20] = name;
        _age = age;
        _superpower = superpower;
    }

    istream& operator >>(istream& in, Superhero& superhero) {
        cout << "Enter name ";  in >> superhero._name;
        cout << "Enter age ";   in >> superhero._age;
        cout << "Enter power "; in >> superhero._superpower;

    return in;
}

    ostream& operator <<(ostream& out, const Superhero& superhero) {
        out << superhero._name << endl;
        out << superhero._age << endl;
        out << superhero._superpower << endl;

    return out;
}
void Superhero::fixString() {
    _name[19] = '\0';
}

void Superhero::read_from_file() {
    ifstream fread;
    fread.open("binary_file_SuperheroClass.dat", ios::binary);

    if(fread.is_open()) {
        fread.seekg(0,fread.end);
        int recordCount = fread.tellg() / sizeof(Superhero);
        fread.seekg(0, fread.beg);

        Superhero *hero2 = new Superhero[recordCount];

        fread.read((char*)(hero2), (sizeof(Superhero) * recordCount));
        for(int i = 0; i < recordCount; i++) {
            hero2[i].fixString();
            cout << hero2[i] << endl;
        }
        cout << "-----------" << endl;
        fread.close();
        delete[] hero2;
    }

    else {
        cout << "File not found" << endl;
    }

}
void Superhero::write_to_file() {
    cout << "How many heroes do you want to make ?" << endl;
    int size_of_arr;
    cin >> size_of_arr;

    Superhero *hero1 = new Superhero[size_of_arr];

    ofstream fout;

    fout.open("binary_file_SuperheroClass.dat", ios::binary|ios::app);

    for(int i = 0; i < size_of_arr; i++) {
        cin >> hero1[i];
        cout << hero1[i] << endl;

        fout.write((char*)(&hero1[i]), sizeof(Superhero));
    }
    fout.close();
    delete[] hero1;
}

void Superhero::prompt_user(){
        cout << "w: Write new heroes" << endl;
        cout << "r: Read list of stored heroes" << endl;
        cout << "q: Quit" << endl;
}

