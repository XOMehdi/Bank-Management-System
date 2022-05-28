#ifndef Child_Manager_Class_hpp
#define Child_Manager_Class_hpp

#include "Parent_Human_Class.hpp"
#include "Child_Customer_Class.hpp"
#include <iostream>

using namespace std;

class Manager : public Human
{
private:
    string manager_id, cust_id;
    int total_customers;
    static int manager_count;

public:
    void setData(string full_name, string pin)
    {
        this->full_name = full_name;
        this->pin = pin;

        manager_count++;
        manager_id = "BkManager" + to_string(manager_count);

        total_customers = Customer::getCustomerCount();
    }

    void displayManager() const
    {
        cout << "\n--------------------------------------------------------------------------------------------" << endl;
        Human::displayHuman();

        cout << "Manager ID: " << manager_id << endl;
        cout << "Total number of Customers: " << total_customers << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void modifyManagerInfo()
    {
        cout << "\n--------------------------------------------------------------------------------------------" << endl;
        cout << "Manager ID cannot be changed! " << endl;
        cout << "Manager ID: " << manager_id << endl;

        Human::modifyHumanInfo();

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    // functions for integration of customer class
    void showCustomer()
    {
        cout << "\nEnter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < 15; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].displayCustomer();
            }
        }
    }

    void editCustomer()
    {
        cout << "\nEnter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < 15; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].modifyCustomerInfo();
            }
        }
    }

    void removeCustomer()
    {
        cout << "\nEnter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < 15; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].deleteCustomer();
                cout << "\nCustomer is Successfully Removed!";
            }
        }
    }

    static int getManagerCount()
    {
        return manager_count;
    }

    //            ----------------------------VIEW ALL INFO FUNCTIONS-----------------------
    void viewAllCustomersInfo()
    {
        cout << "\n-------------------------Accounts List---------------------------" << endl;
        cout << "|Customer's Name --- Pin --- CNIC Number --- Phone Number --- Customer ID --- No of Accounts --- No of Transactions|" << endl;
        for (int i = 0; i < Customer::getCustomerCount(); i++)
        {
            if (custmr[i].getStatus() == true)
                custmr[i].tabularCustomerInfo();

            else
                cout << "                ---                     ---                 " << endl;
        }
        cout << "------------------------------------------------------------------" << endl;
    }

    void viewAllAccountsInfo()
    {
        cout << "\n-------------------------Accounts List---------------------------" << endl;
        cout << "|Account Number --- Account Holder Name --- Account Balance|" << endl;
        for (int i = 0; i < Account::getAccCount(); i++)
        {
            if (accounts[i].getStatus() == true)
                accounts[i].tabularAccInfo();

            else
                cout << "                ---                     ---                 " << endl;
        }
        cout << "------------------------------------------------------------------" << endl;
    }

    void viewAllTransactions()
    {
        cout << "\n---------------------------------------------Transactions List----------------------------------------------------" << endl;
        cout << "|Transaction Time --- Transaction Date --- Transferred By (AN) --- Transferred To (AN) --- Transaction Amount|" << endl;
        for (int i = 0; i < Transaction::getTransCount(); i++)
        {
            if (trans[i].getTransactionStatus() == true)
                trans[i].tabularTransInfo();

            else
                cout << "                  ---                  ---                     ---                     ---                    " << endl;
        }
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    }
};

int Manager::manager_count = 0;

Manager managers[3];

#endif /* Child_Manager_Class_hpp */
