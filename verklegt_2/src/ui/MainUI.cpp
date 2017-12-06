#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::startui(){

    char input;
    while(true){
    cout << "1. Add salary record." << endl;
    cout << "2. Get all salary records for given kennitala." << endl;
    cout << "3. Get total salary for given year and kennitala." << endl;
    cout << "4. Get employee with highest salary for given year." << endl;

    cin >> input;
    validate_input(input);
    }
}
void MainUI::add_salary(Salary salary) {

    salary_service.add_salary(salary);
}
void MainUI::read_salary_list() {
    salary_service.read_salary();

}
Salary MainUI::create_salary() {
    string name,kennitala;
    string year,month,salary_amount;
    cin.ignore();
    cout << "Name: ->"; getline(cin,name);
    salary_service.isValidNameStr(name);
    cout << "Kennitala: ->"; cin >> kennitala;
    salary_service.isValidKennitalaStr(kennitala);
    cout << "Year: ->"; cin >> year;
    salary_service.isValidYearInt(year);
    cout << "Month: ->"; cin >> month;
    salary_service.isValidMonthInt(month);
    cout << "Salary amount: ->"; cin >> salary_amount;
    salary_service.isValidSalaryAmountInt(salary_amount);

    return Salary(name,kennitala,year,month,salary_amount);
}

void MainUI::validate_input(char input) {

    if(input == '1') {
            system ("CLS");
        try{
            Salary salary = create_salary();
           // add_salary(salary);
            vector<Salary> sal_vect = salary_repo.read_salaryfile_into_vector2(salary);
            for(unsigned int i = 0; i < sal_vect.size(); i++) {
                cout << sal_vect[i];
            }
            //add_salary(salary);
            salary_service.is_salary_duplicate(sal_vect,salary);
        }
        catch(InvalidNameException e) {
        cout << "Invalid name, only use the alphabet letters. Please try again" << endl;
        }
        catch(InvalidKennitalaException e) {
        cout << "Invalid  kennitala, it may only contain 10 decimal numbers" << endl;
        }
        catch(InvalidYearException e) {
        cout << "Invalid year, you can only use the current year" << endl;
        }
        catch(InvalidMonthException e) {
        cout << "Invalid month" << endl;
        }
        catch(InvalidSalaryAmountException e) {
        cout << "Invalid salary amount, no one gets such a riddiculus amount each month" << endl;
        }
        catch(InvalidSalaryAmountMinusException e) {
        cout << "Invalid salary amount, no one gets payed such a riddiculusly small amount" << endl;
        }
        cout << "-----------------------" << endl;




    }
    else if(input == '2') {
        vector<Salary> sal_vect = salary_repo.read_salaryfile_into_vector();

        cout << "Salary Vector has " << sal_vect.size() << " variables" << endl;

        for(unsigned int i = 0; i < sal_vect.size(); i++) {
            cout << sal_vect[i] << endl;
        }
    }
    else if(input == '3') {

    }
    else if(input == '4') {

    }
    else if(input == '5') {

    }
    else {
            system("CLS");
        cout << "Invalid input, please try again" << endl;
    }
}


