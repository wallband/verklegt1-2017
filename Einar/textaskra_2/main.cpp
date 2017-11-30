#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{

    string str;
    ofstream fout;

    fout.open("TextOutput.txt", ios::app);

    if(fout.is_open()){
        while(str[0] != '\\'){

            cout << "Enter string: " ;
            getline(cin,str);

                if (str[0] == '\\') {
                    return 0;
                }

                else {
                     fout << str << endl;
                }
        }
    }

    else {
        cout << "File is not available";
    }

    fout.close();

    return 0;
}
