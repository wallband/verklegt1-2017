#include "OrderRepository.h"

void OrderRepository::saveOrder(int file, vector<string> listOfItems,
                                string phone, int pizza, int drink, int side, int total, char pizzaState){
    //string phone = "1234567";

    if(file > 0){
        overwriteIndex(file, phone, pizza, drink, side, total, pizzaState);
    }
    else{
        int fileNr = file;
        fileNr = addTotalItems();
        writeToFile(fileNr, listOfItems, phone, pizza, drink, side, total, pizzaState);
    }
}
string OrderRepository::overwriteIndex(int nr, string phone, int pizza, int drink, int side, int total, char pizzaState){

    string str;
    vector<string> tempList;
    string pizzaStr = numToString(pizza);
    string drinkStr = numToString(drink);
    string sideStr = numToString(side);
    string totalStr = numToString(total);

    string input = phone + " " + pizzaState + " "+ pizzaStr + " " + drinkStr + " " + sideStr + " " + totalStr;
    int limit = getTotalItems();

    ifstream fin;
    fin.open("DATA/ORDER/Index.txt");
    tempList.clear();
    if(fin.fail()){

        cerr << "Error opening Order-Total file!" << endl;
        //system("pause");
    }
    else{
        while(!fin.eof()){
            getline(fin, str);
            tempList.push_back(str);
        }
        fin.close();
    }
    //readList.reverse(readList.begin(), readList.end());
    for(int i = 0; i < limit; i++){
            readList.push_back(tempList.at(i));
        }

    readList.at((nr - 1)) = input;

    ofstream fout;

    fout.open("DATA/ORDER/Index.txt");

    if(fout.fail()){

        cerr << "Error opening Order-Index file!" << endl;
        //system("pause");
    }
    else{
        for(int i = 0; i < limit; i++){
            fout << readList.at(i) << endl;
        }
        fout.close();
    }
    return input;

}
void OrderRepository::writeToFile(int fileNr, vector<string> listOfItems,
                                string phone, int pizza, int drink, int side, int total, char pizzaState){

    string fileStart = "", strFileNr = "";
    if(fileNr > 0){
        strFileNr = numToString(fileNr);
        fileStart = overwriteIndex(fileNr, phone, pizza, drink, side, total, pizzaState);
    }
    else{
        fileNr = addTotalItems();
        fileStart = addToIndex(phone, pizza, drink, side, total, pizzaState);
        strFileNr = numToString(fileNr);
    }
        string str;
        string fileName = ("DATA/ORDER/order" + strFileNr + ".txt");

        listOfItems.push_back(fileStart);

        ofstream fout;
        fout.open(fileName.c_str());
        if(fout.fail()){
            cerr << "Error opening output file " + strFileNr <<endl;
        }
        else{
            int input = listOfItems.size();
            while(input != 0){
                --input;
                fout << listOfItems.at(input) << endl;
            }
            fout.close();
        }
}

int OrderRepository::addTotalItems(){

    int totalObj = (getTotalItems() + 1);

    ofstream fout;

    fout.open("DATA/ORDER/Total.txt");

    if(fout.fail()){

        cerr << "Error opening Order-Total file!" << endl;
    }
    else{
        fout << totalObj;
        fout.close();
    }
    return totalObj;
}
string OrderRepository::addToIndex(string phone, int pizza, int drink, int side, int total, char pizzaState){

    string pizzaStr = numToString(pizza);
    string drinkStr = numToString(drink);
    string sideStr = numToString(side);
    string totalStr = numToString(total);

    string input = phone + " " + pizzaState + " " + pizzaStr + " " + drinkStr + " " + sideStr + " " + totalStr;
    ofstream fout;

    fout.open("DATA/ORDER/Index.txt", ios::app);

    if(fout.fail()){

        cerr << "Error opening Order-Total file!" << endl;
    }
    else{
        fout << input << endl;
        fout.close();
    }
    return input;
}

string OrderRepository::numToString(int number){

    stringstream numString;
    numString << number;
    return numString.str();
}
string OrderRepository::whatPizzaState(char s){

    if(s == '1'){
        return "In preperation";
    }
    if(s == '2'){
        return "In Oven";
    }
    if(s == '3'){
        return "Ready";
    }
    if(s == '4'){
        return "Paid";
    }
    else{
        return "Not valid state";
    }
}

int OrderRepository::getTotalItems(){


    ifstream fin;
    int totalObj;
    fin.open("DATA/ORDER/Total.txt");

    if(fin.fail()){
        cerr << "Error opening Order-Total file!" << endl;
    }
    else{
        while(!fin.eof()){
            fin >> totalObj;
        }
        fin.close();
    }
    return totalObj;
}

bool OrderRepository::readItemList(int obj){

    if(obj == 0){
        return false;
    }
    else{
        return true;
    }
}

int OrderRepository::readOrderList(){

    int totalObjects = getTotalItems();

    if(readItemList(totalObjects) == true){
        string number;
        char pizzaState;
        int pizza, drink, side, total;
        ifstream fin;
        int obj = 1;

        fin.open("DATA/ORDER/Index.txt");

        if(fin.fail()){

            cerr << "Error opening Order-Index file!" << endl;
        }
        else{
            orderHeader();
            while(fin >> number){
                fin >> pizzaState >> pizza >> drink >> side >> total;
                cout << " - " << obj <<". Owner: " << number << ", status: "<< whatPizzaState(pizzaState) <<"\n\t"
                << pizza << " pizza/s, "
                << drink << " drink/s, "
                << side << " side/s, "
                << "total price: " << total<<endl;
                obj++;
            }
            fin.close();
            cout <<" - " << obj <<": Back"<< endl;
        }
        return orderSelect(totalObjects);
    }
    else{
        return 0;
    }

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
    cout << "----------------------------------------------------------" << endl;
    cout << "                     List of orders" << endl;
    cout << "----------------------------------------------------------\n" << endl;
}
