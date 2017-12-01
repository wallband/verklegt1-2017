#include <iostream>
#include <fstream>
using namespace std;

class Superhero
{
     private:
        string name;
        int age;
        char superpower;

        bool verbose;

    public:
        Superhero()
        {
            name = "";
            age = 0;
            superpower = 'n';

            verbose = true;
        }
        void setVerbose(bool v)
        {
            verbose = v;
        }

        Superhero(string name, int age, char superpower)
        {
            this->name = name;
            this->age = age;
            this->superpower = superpower;
        }

        friend istream& operator >> (istream& in, Superhero& power)
        {

            if(power.verbose)
            {
                cout << "Enter superhero name: ";
            }
            in >> ws;
            getline(in, power.name);

            if(power.verbose)
            {
            cout << "Enter age: ";
            }
            in >> power.age;

            if(power.verbose)
            {
            cout << "Enter superpower: ";
            }
            in >> power.superpower;

            return in;
        }

        friend ostream& operator << (ostream& out, const Superhero& power)
        {

            out << power.name;

            out << "(" << power.age << "): ";

            if (power.superpower == 'f')
            {
                out << "Flying" << endl;
            }
            else if (power.superpower == 'g')
            {
                out << "Giant" << endl;
            }
            else if(power.superpower == 'h')
            {
                out << "Hacker" << endl;
            }
            else if(power.superpower == 'n')
            {
                out << "None" << endl;
            }
            else
            {
                out << "Weakling" << endl;
            }

            return out;
       }
};


int main()
{

    Superhero power1;

    power1.setVerbose(true);

    cin >> power1;

    ofstream fout;
    fout.open("text_superhero.txt", ios::app);

    power1.setVerbose(false);
    fout << power1;
    fout.close();



    string str;

    ifstream fin;
    fin.open("text_superhero.txt", ios::app);

    if(fin.is_open())
    {
        while(!fin.eof())
        {
             getline(fin, str);
             cout << str << endl;
        }
    }
    else
    {
        cout << "Could not open file" << endl;
    }

    fin.close();

    return 0;
}
