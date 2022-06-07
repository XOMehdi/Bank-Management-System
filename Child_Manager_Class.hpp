#ifndef Child_Manager_Class_hpp
#define Child_Manager_Class_hpp

#include "Parent_User_Class.hpp"
#include "Child_Customer_Class.hpp"
#include <iostream>

using namespace std;

class Manager : public User
{
private:
    string manager_id, customer_id;
    static int manager_count;

public:
    void setData(string first_name, string last_name, string pin);
    void displayManager();
    void modifyManagerInfo();

    // getter functions
    static int getManagerCount();
    string getFullName();
    string getPin() const;
    bool getStatus() const;

    // functions for integration of customer class
    void showCustomer();
    void editCustomer();
    void removeCustomer();

    // functions to display all data
    void viewAllCustomersInfo();
    void viewAllAccountsInfo();
    void viewAllTransactions();
};

// all member functions definitions
void Manager::setData(string first_name, string last_name, string pin)
{
    this->full_name.setFullName(first_name, last_name);
    this->pin = pin;

    manager_count++;
    manager_id = "BkManager" + to_string(manager_count);
}

void Manager::displayManager()
{
    cout << "\n--------------------------------------------------------------------------------------------" << endl;
    User::displayUser();

    cout << "Manager ID: " << manager_id << endl;
    cout << "Number of Customers Logged in the System: " << Customer::getCustomerCount() << endl;
    cout << "Number of Accounts Opened in the System: " << Account::getAccCount() << endl;
    cout << "Number of Transactions Made through the System: " << Transaction::getTransCount() << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Manager::modifyManagerInfo()
{
    cout << "\n--------------------------------------------------------------------------------------------" << endl;
    cout << "Manager ID cannot be changed! " << endl;
    cout << "Manager ID: " << manager_id << endl;

    User::modifyUserInfo();

    cout << "----------------------------------------------------------------------------------------------" << endl;
}

// functions for integration of customer class
void Manager::editCustomer()
{
    cout << "\nEnter the Customer's ID: ";
    cin >> customer_id;

    for (int i = 0; i < 15; i++)
    {
        if (customer_id == custmr[i].getCustomerID())
        {
            custmr[i].modifyCustomerInfo();
        }
    }
}

void Manager::removeCustomer()
{
    cout << "\nEnter the Customer's ID: ";
    cin >> customer_id;

    for (int i = 0; i < 15; i++)
    {
        if (customer_id == custmr[i].getCustomerID())
        {
            custmr[i].deleteCustomer();
            cout << "\nCustomer is Successfully Removed!";
        }
    }
}

//            ----------------------------VIEW ALL INFO FUNCTIONS-----------------------
void Manager::viewAllCustomersInfo()
{
    cout << "\n-----------------------------------------------Customers List-----------------------------------------------------------" << endl;
    cout << "|Customer's Name --- Pin --- Phone Number --- Customer ID --- No of Accounts --- No of Transactions|" << endl;
    for (int i = 0; i < Customer::getCustomerCount(); i++)
    {
        if (custmr[i].getStatus() == true)
            custmr[i].tabularCustomerInfo();

        else
            cout << "                ---                     ---                 " << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Manager::viewAllAccountsInfo()
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

void Manager::viewAllTransactions()
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
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
}

string Manager::getFullName()
{
    return full_name.getFullName();
}

string Manager::getPin() const
{
    return pin;
}

bool Manager::getStatus() const
{
    return status;
}

int Manager::getManagerCount()
{
    return manager_count;
}

// initiallizing static count data member
int Manager::manager_count = 0;

Manager managers[MANAGERS_LIMIT];

#endif /* Child_Manager_Class_hpp */
