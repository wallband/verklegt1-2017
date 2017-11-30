#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
using namespace std;

class Superhero
{

private:
    char _name[20];
    int _age;
    char _superpower;

public:
    Superhero();
    virtual ~Superhero();
    Superhero(char name, int age, char superpower);

    friend istream& operator >>(istream& in, Superhero& superhero);
    friend ostream& operator <<(ostream& out, const Superhero& superhero);

void fixString();
void read_from_file();
void write_to_file();
void prompt_user();
void read_write_to_file(Superhero hero);



};

#endif // SUPERHERO_H
