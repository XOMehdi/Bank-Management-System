#ifndef Child_Customer_Class_hpp
#define Child_Customer_Class_hpp

#include "Parent_Human_Class.hpp"
#include <iostream>

using namespace std;

class Customer : public Human
{
private:
    string customer_id, cnic_number, phone_number;
    int no_of_accounts;

public:
    Customer() : Human()
    {
        customer_id = "BankCustomer" + to_string(obj_count);
    }

    void readCustomer()
    {
        Human::readHuman();

        cout << "\nPlease enter your CNIC Number: ";
        cin >> cnic_number;

        cout << "\nPlease enter your Phone Number: ";
        cin >> phone_number;

        cout << "\nHow many accounts do you have: ";
        cin >> no_of_accounts;

        cout << "\nYou are now Registered as a Customer! ";
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void modifyCustomerInfo()
    {
        cout << "Your ID cannot be changed! " << endl;
        cout << "\nYour Customer ID is: " << customer_id << endl;

        Human::modifyHumanInfo();

        cout << "\nChange your Phone Number: ";
        cin >> phone_number;

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void displayCustomer() const
    {
        Human::displayHuman();

        cout << "\nCNIC Number: " << cnic_number << endl;
        cout << "\nPhone Number: " << phone_number << endl;
        cout << "\nCustomer ID: " << customer_id;
        cout << "\nNumber of Accounts: " << no_of_accounts;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }
};

Customer custmr[50];

#endif /* Child_Customer_Class_hpp */
