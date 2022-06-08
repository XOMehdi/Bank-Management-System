#ifndef Child_Customer_Class_hpp
#define Child_Customer_Class_hpp

#include "Parent_User_Class.hpp"
#include "Account_Class.hpp"
#include "Transaction_Class.hpp"
#include <iostream>

using namespace std;

class Customer : public User
{
private:
    string customer_id, phone_number, acc_num;
    int no_of_accounts, no_of_transactions;
    static int custmr_count;

public:
    Customer() : User()
    {
        no_of_accounts = 0;
        no_of_transactions = 0;
    }

    void readCustomer();
    void modifyCustomerInfo();
    void displayCustomer();
    void tabularCustomerInfo();
    void deleteCustomer();

    // getter functions
    static int getCustomerCount();
    string getCustomerID() const;
    string getFullName();
    string getPin() const;
    bool getStatus() const;

    // functions for integration of account class
    void openAccount();
    void editAccount();
    void viewAccount();
    void closeAccount();
    void closeAllAccounts();
    void depositInAccount();
    void withdrawFromAccount();

    // functions for integration of transaction class
    void doTransaction();
    void viewTransaction();
    void removeTransactions();
};

// all member functions definitions
void Customer::readCustomer()
{
    custmr_count++;
    customer_id = "BkCustomer" + to_string(custmr_count);

    cout << "\n----------------------------------------------------------------------------------------------" << endl;
    User::readUser();

    cout << "\nPlease enter your Phone Number: ";
    cin >> phone_number;

    cout << "\nA Customer with the Customer ID: " << customer_id << " has been created!" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Customer::modifyCustomerInfo()
{
    cout << "\n----------------------------------------------------------------------------------------------" << endl;
    cout << "Customer ID cannot be changed! " << endl;
    cout << "Customer ID: " << customer_id << endl;

    User::modifyUserInfo();

    cout << "\nChange your Phone Number: ";
    cin >> phone_number;

    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Customer::displayCustomer()
{
    cout << "\n----------------------------------------------------------------------------------------------" << endl;
    User::displayUser();

    cout << "Phone Number: " << phone_number << endl;
    cout << "Customer ID: " << customer_id << endl;
    cout << "Number of Accounts: " << no_of_accounts << endl;
    cout << "Number of Transactions: " << no_of_transactions << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Customer::tabularCustomerInfo()
{
    // printing data in a tabular form
    cout << ' ' << full_name.getFullName() << "     ";
    cout << pin << "     ";
    cout << phone_number << "       ";
    cout << customer_id << "     \t";
    cout << no_of_accounts << " \t\t\t    ";
    cout << no_of_transactions << endl;
}

void Customer::deleteCustomer()
{
    full_name.setFullName("  ", "  ");
    pin = "  ";
    custmr_count--;
    status = false;
    customer_id = "  ";
    phone_number = "  ";

    if (no_of_accounts > 0)
    {
        closeAllAccounts();
        removeTransactions();
    }
}

int Customer::getCustomerCount()
{
    return custmr_count;
}

string Customer::getCustomerID() const
{
    return customer_id;
}

string Customer::getFullName()
{
    return full_name.getFullName();
}

string Customer::getPin() const
{
    return pin;
}

bool Customer::getStatus() const
{
    return status;
}

// functions for integration of account class
void Customer::openAccount()
{
    for (int i = 0; i < ACCOUNTS_LIMIT; i++)
    {
        if (accounts[i].getStatus() == false)
        {
            accounts[i].readAccount();
            no_of_accounts++;
            break;
        }
    }
}

void Customer::editAccount()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < ACCOUNTS_LIMIT; i++)
    {
        if (acc_num == accounts[i].getAccountNo())
        {
            accounts[i].modifyAccountInfo();
            break;
        }
    }
}

void Customer::viewAccount()
{
    for (int i = 0; i < no_of_accounts; i++)
    {
        cout << "\nEnter Your Account Number " << i + 1 << ": ";
        cin >> acc_num;

        for (int i = 0; i < ACCOUNTS_LIMIT; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].displayAccountInfo();
                break;
            }
        }
    }
}

void Customer::closeAccount()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < ACCOUNTS_LIMIT; i++)
    {
        if (acc_num == accounts[i].getAccountNo())
        {
            accounts[i].deleteAccount();
            cout << "\nAccount is Successfully Closed!";
            break;
        }
    }
}

void Customer::closeAllAccounts()
{
    for (int i = 0; i < no_of_accounts; i++)
    {
        cout << "\nEnter Account Number " << i + 1 << ": ";
        cin >> acc_num;

        for (int i = 0; i < ACCOUNTS_LIMIT; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].deleteAccount();
                break;
            }
        }
    }
}

void Customer::depositInAccount()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < ACCOUNTS_LIMIT; i++)
    {
        if (acc_num == accounts[i].getAccountNo())
        {
            accounts[i].depositAmount();
            break;
        }
    }
}

void Customer::withdrawFromAccount()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < ACCOUNTS_LIMIT; i++)
    {
        if (acc_num == accounts[i].getAccountNo())
        {
            accounts[i].withdrawAmount();
            break;
        }
    }
}

// functions for integration of transaction class
void Customer::doTransaction()
{
    for (int i = 0; i < TRANSACTIONS_LIMIT; i++)
    {
        if (trans[i].getTransactionStatus() == false)
        {
            trans[i].makeTransaction();
            no_of_transactions++;
            break;
        }
    }
}

void Customer::viewTransaction()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < no_of_transactions; i++)
    {
        for (int i = 0; i < TRANSACTIONS_LIMIT; i++)
        {
            if (acc_num == trans[i].getSenderAccNo())
            {
                trans[i].showTransaction();
                break;
            }
        }
    }
}

void Customer::removeTransactions()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < no_of_transactions; i++)
    {
        for (int i = 0; i < TRANSACTIONS_LIMIT; i++)
        {
            if (acc_num == trans[i].getSenderAccNo())
            {
                trans[i].deleteTransRecord();
                break;
            }
        }
    }
}

// initiallizing static count data member
int Customer::custmr_count = 0;

const int CUSTOMERS_LIMIT = 15;
Customer custmr[CUSTOMERS_LIMIT];

#endif /* Child_Customer_Class_hpp */
