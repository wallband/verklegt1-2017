#include "Superhero.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Superhero::Superhero() {
    this->name = "";
    this->age = 0;
    this->superpower = 'n';
}

Superhero::Superhero(string name, int age, char superpower) {
    this->name = name;
    this->age = age;
    this->superpower = superpower;
}

istream& operator >> (istream& in, Superhero& superhero) {
    cout << "Name: ";
    in >> ws;
    getline(in, superhero.name);
    cout << "Age: ";
    in >> superhero.age;
    cout << "Superpower: (F)Flying, (G)Giant, (H)Hacker, (N)None: ";
    in>> superhero.superpower;

    return in;
}

ostream& operator << (ostream& out, const Superhero& superhero) {
    out << superhero.name << " (" << superhero.age << "): ";
    if ((superhero.superpower == 'f') || (superhero.superpower == 'F')) {
        out << "Flying" << endl;
    }
    else if ((superhero.superpower == 'g') || (superhero.superpower == 'G')) {
        out << "Giant" << endl;
    }
    else if ((superhero.superpower == 'h') || (superhero.superpower == 'H')) {
        out << "Hacker" << endl;
    }
    else if ((superhero.superpower == 'n') || (superhero.superpower == 'N')) {
        out << "None" << endl;
    }
    else {
        out << "Weakling" << endl;
    }

    return out;
}

//set_name(Superhero superhero, string dnew_name) {
  //  Superh = new_name;
//}
