#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

void OrderRepository::saveOrder(){


}

int OrderRepository::readOrderList(){

    string number;
    int pizza, drink, side, total;
    ifstream fin;
    int obj = 1;
    int totalObj;
    fin.open("DATA/ORDER/TOTAL.txt");

    if(fin.fail()){

        cerr << "Error opening Order-Total file!" << endl;
    }
    else{
        while(fin >> totalObj){
            fin >> totalObj;
        }
        fin.close();

    }


    fin.open("DATA/ORDER/INDEX.txt");

    if(fin.fail()){

        cerr << "Error opening Order-Index file!" << endl;
    }
    else{
        orderHeader();
        while(!fin.eof()){
            //getline(fin, number, ',');
            fin >> number >> pizza >> drink >> side >> total;
            cout << " - " << obj <<". Owner: " << number <<"\n\t"
            << pizza << " pizza/s, "
            << drink << " drink/s, "
            << side << " side/s, "
            << "total price: " << total<<endl;
            obj++;
            //system("pause");
            if(fin.eof()){ break; }
        }
        fin.close();
        cout << obj <<": Back"<< endl;
    }
    //int value = orderSelect(totalObj);
    return orderSelect(totalObj);
}

int OrderRepository::orderSelect(int totalObj){

    string selection;
    int selectNR;
    cout <<"\nSelect a order to view..." << endl;
    while(selectNR != (totalObj + 1)){
        cin >> selection;
        selectNR = atoi(selection.c_str());
        if(selectNR >= 1 && selectNR <= totalObj){
            break;
        }
        if(selectNR == (totalObj + 1)){
            selectNR = 0;
            break;
        }
        else{
            cout << "Invalid Order..." << endl;
        }
    }
    return selectNR;

}

void OrderRepository::orderHeader(){

    system("cls");
    cout << "-----------------------" << endl;
    cout << "    List of orders" << endl;
    cout << "-----------------------" << endl;
}
