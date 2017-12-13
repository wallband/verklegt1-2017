#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

void OrderRepository::saveOrder(vector<string> listOfItems,
                                int pizza, int drink, int side, int total)
{
    string phone = "1234567";

    int fileNr = 0;
    fileNr = addTotalItems();
    string fileStart = addToIndex(phone, pizza, drink, side, total);
    string strFileNr = numToString(fileNr);
    string str, fileName = ("DATA/ORDER/order" + strFileNr + ".txt");

    listOfItems.push_back(fileStart);
    //cout << endl << "Saving to file: "<< fileName << endl;

    ofstream fout;
    fout.open(fileName.c_str());
    if(fout.fail())
    {
        cerr << "Error opening output file " + strFileNr <<endl;
    }
    else
    {
        //fout << fileStart << endl;
        for(unsigned int i = 0; i < listOfItems.size(); i++)
        {

            fout << listOfItems.at(i) << endl;
        }
        fout.close();
    }



}

int OrderRepository::addTotalItems()
{

    int totalObj = (getTotalItems() + 1);

    ofstream fout;

    fout.open("DATA/ORDER/TOTAL.txt");

    if(fout.fail())
    {

        cerr << "Error opening Order-Total file!" << endl;
    }
    else
    {
        //while(!fout.eof()){
        fout << totalObj;
        //}
        fout.close();
    }
    return totalObj;
}
string OrderRepository::addToIndex(string phone, int pizza, int drink, int side, int total)
{

    string pizzaStr = numToString(pizza);
    string drinkStr = numToString(drink);
    string sideStr = numToString(side);
    string totalStr = numToString(total);

    string input = phone + " " + pizzaStr + " " + drinkStr + " " + sideStr + " " + totalStr;
    ofstream fout;

    fout.open("DATA/ORDER/INDEX.txt", ios::app);

    if(fout.fail())
    {

        cerr << "Error opening Order-Total file!" << endl;
    }
    else
    {
        fout << input << endl;
        fout.close();
    }
    return input;
}

string OrderRepository::numToString(int number)
{

    stringstream numString;
    numString << number;
    return numString.str();
}

int OrderRepository::getTotalItems()
{


    ifstream fin;
    int totalObj;
    fin.open("DATA/ORDER/TOTAL.txt");

    if(fin.fail())
    {
        cerr << "Error opening Order-Total file!" << endl;
    }
    else
    {
        while(!fin.eof())
        {
            fin >> totalObj;
        }
        fin.close();
    }
    return totalObj;
}

bool OrderRepository::readItemList(int obj)
{

    if(obj == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int OrderRepository::readOrderList()
{

    int totalObjects = getTotalItems();

    if(readItemList(totalObjects) == true)
    {
        string number;
        int pizza, drink, side, total;
        ifstream fin;
        int obj = 1;

        fin.open("DATA/ORDER/INDEX.txt");

        if(fin.fail())
        {

            cerr << "Error opening Order-Index file!" << endl;
        }
        else
        {
            orderHeader();
            while(!fin.eof())
            {
                //getline(fin, number, ',');
                fin >> number >> pizza >> drink >> side >> total;
                cout << " - " << obj <<". Owner: " << number <<"\n\t"
                     << pizza << " pizza/s, "
                     << drink << " drink/s, "
                     << side << " side/s, "
                     << "total price: " << total<<endl;
                obj++;
                //system("pause");
                if(fin.eof())
                {
                    break;
                }
            }
            fin.close();
            cout << obj <<": Back"<< endl;
        }
        return orderSelect(totalObjects);
    }
    //int value = orderSelect(totalObj);
    else
    {
        cout << "There are no Orders" << endl;
        return 0;
    }

}

int OrderRepository::orderSelect(int totalObj)
{

    string selection;
    int selectNR;
    cout <<"\nSelect a order to view..." << endl;
    while(selectNR != (totalObj + 1))
    {
        cin >> selection;
        selectNR = atoi(selection.c_str());
        if(selectNR >= 1 && selectNR <= totalObj)
        {
            break;
        }
        if(selectNR == (totalObj + 1))
        {
            selectNR = 0;
            break;
        }
        else
        {
            cout << "Invalid Order..." << endl;
        }
    }
    return selectNR;

}

void OrderRepository::orderHeader()
{

    system("cls");
    cout << "-----------------------" << endl;
    cout << "    List of orders" << endl;
    cout << "-----------------------" << endl;
}
