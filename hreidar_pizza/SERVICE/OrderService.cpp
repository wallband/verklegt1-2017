#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

void OrderService::viewOrderList(){

    char selection;
    while(selection != '4'){
        service_header();
        cout << "1. Edit last order" << endl;
        cout << "2. View orders" << endl;
        cout << "\n4. Back" << endl;
        cin >>selection;

        if(selection == '1'){
            cout << endl;
        }
        if(selection == '2'){
            int N = orderRepo.readOrderList();
            cout <<"Selected object: " << N << endl;
            system("pause");
        }
    }

}

void OrderService::service_header(){

    system("CLS");
    cout << "-----------------------" << endl;
    cout << "    Order operations " << endl;
    cout << "-----------------------" << endl;
}
