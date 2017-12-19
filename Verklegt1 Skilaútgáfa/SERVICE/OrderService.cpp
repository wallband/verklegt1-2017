#include "OrderService.h"

int OrderService::viewOrderList()
{

    int select = 0;
    char selection;
    bool done = false;
    do
    {
        service_header();
        cout << "1. Edit last order" << endl;
        cout << "2. View orders" << endl;
        cout << "\n4. Cancel" << endl;
        cin >>selection;

        if(selection == '1')
        {

            select = orderRepo.getTotalItems();
            done = true;
        }
        if(selection == '2')
        {
            select = orderRepo.readOrderList();
            /*
            if(select > 0){
                cout <<"Selected object: " << select << endl;
                break;
            }
            */
            done = true;
            //system("pause");
        }
        if(selection == '4')
        {

            select = 0;
            done = true;
        }
    }
    while(!done);
    return select;

}

void OrderService::service_header()
{

    system("CLS");
    cout << "-----------------------" << endl;
    cout << "    Order selection " << endl;
    cout << "-----------------------\n" << endl;
}

void OrderService::state_header()
{

    system("CLS");
    cout << "-----------------------" << endl;
    cout << "     State selection " << endl;
    cout << "-----------------------\n" << endl;
}
