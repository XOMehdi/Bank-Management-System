#ifndef Child_Customer_Class_hpp
#define Child_Customer_Class_hpp

#include "Parent_Human_Class.hpp"
#include "Account_Class.hpp"
#include <iostream>

using namespace std;

class Customer : public Human
{
private:
    string customer_id, cnic_number, phone_number, acc_num;
    int no_of_accounts;
    static int custmr_count;

public:
    Customer() : Human()
    {
        customer_id = "BkCustmr" + to_string(custmr_count);
        cnic_number = "  ";
        phone_number = "  ";
        no_of_accounts = 0;
    }

    void readCustomer()
    {
        custmr_count++;
        Human::readHuman();

        cout << "\nPlease enter your CNIC Number: ";
        cin >> cnic_number;

        cout << "\nPlease enter your Phone Number: ";
        cin >> phone_number;

        cout << "\nA Customer with the Customer ID: " << customer_id << " has been created!";
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void modifyCustomerInfo()
    {
        cout << "Customer ID cannot be changed! " << endl;
        cout << "\nCustomer ID: " << customer_id << endl;

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

    string getCustomerID() const
    {
        return customer_id;
    }

    void deleteCustomer()
    {
        full_name = "  ";
        pin = "  ";
        custmr_count--;
        status = false;
        customer_id = "  ";
        cnic_number = "  ";
        phone_number = "  ";
        no_of_accounts = 0;
    }

    void openAccount()
    {
        no_of_accounts++;
        for (int i = 0; i < 25; i++)
        {
            if (accounts[i].getStatus() == false)
            {
                accounts[i].readAccount();

                cout << "|Account Number --- Account Holder Name --- Account Balance|" << endl;
                accounts[i].displayAccountInfo();
            }
        }
    }

    void closeAccount()
    {
        cout << "Enter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < 25; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].deleteAccount();
                cout << "\nAccount is Successfully Closed!";
            }
        }
    }

    void editAccount()
    {
        cout << "Enter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < 25; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].modifyAccountInfo();
            }
        }
    }

    static int customerCount()
    {
        return custmr_count;
    }
};
int Customer::custmr_count = 0;

Customer custmr[20];

#endif /* Child_Customer_Class_hpp */
