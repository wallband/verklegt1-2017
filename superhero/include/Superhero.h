#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Superhero
{
private:
    string name;
    int age;
    char superpower;

public:
    Superhero();
    Superhero(string name, int age, char superpower);
    friend istream& operator >>(istream& in, Superhero& superhero);
    friend ostream& operator << (ostream& out, const Superhero& superhero);
   // void set_name(Superhero superhero, string new_name);
};

#endif // SUPERHERO_H
