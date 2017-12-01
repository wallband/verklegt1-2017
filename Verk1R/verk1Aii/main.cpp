#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("textFileB.txt", ios::app);

    if (fout.is_open())
    {
        string str;
        cout << "Please write a sentence: " << endl;

        while(str[0] != '\\')
        {
            getline(cin, str);

            if (str[0] == '\\')
            {
                return 0;
            }
            else
            {
                fout << str << endl;
            }
        }
        fout.close();

    }else
    {
        cout << "File could not be openend!" << endl;
    }

    return 0;
}
