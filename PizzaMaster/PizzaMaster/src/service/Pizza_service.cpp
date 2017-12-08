#include "Pizza_service.h"

Pizza_service::Pizza_service(){
}
void Pizza_service::make_pizza(Order& order){ ///Takes the new order and
    char input;                               ///adds to it by reference
    string size, bottom_type;                 ///
    cout << "Please select size" << endl;
    cout << "1: Large." << endl;
    cout << "2: Medium." << endl;
    cout << "3: Small." << endl;

    cout << "-> "; cin >> input;
    cout << endl;
    validate_size(input, size);

    cout << "Please select size" << endl;
    cout << "1: Soggy." << endl;
    cout << "2: DeepDish." << endl;
    cout << "3: Sardines" << endl;

    cout << "-> "; cin >> input;
    cout << endl;
    validate_bottom(input, bottom_type);

    cout << "Size selected is " << size << " and bottom type is " << bottom_type << endl;
    Pizza pizza(size, bottom_type);
    order.pizza_vector.push_back (pizza);
    cout << "Number of pizzas in order: " << order.pizza_vector.size() << endl;
}
void Pizza_service::validate_size(char input, string& size) {
    if(input == '1') {
        size = "Large";
    }
    else if(input == '2') {
        size = "Medium";
    }
    else if(input == '3') {
        size = "Small";
    }

}

void Pizza_service::validate_bottom(char input, string& bottom) {
    if(input == '1') {
        bottom = "Soggy";
    }
    else if(input == '2') {
        bottom = "DeepDish";
    }
    else if(input == '3') {
        bottom = "Sardines";
    }

}
void Pizza_service::add_topping(Pizza& pizza) {
             ///Call topping UI




}
