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
    int no_of_accounts;
    static int custmr_count;

public:
    Account account[3];

    Customer() : User()
    {
        no_of_accounts = 0;
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
    void viewAllAccounts();
    void closeAccount();
    void closeAllAccounts();
    void depositInAccount();
    void withdrawFromAccount();

    // functions for integration of transaction class
    void doTransaction(int index, string receiver_accno, float transaction_amount);
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
    cout << "Number of Transactions: " << account[0].no_of_transactions + account[1].no_of_transactions << endl;
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
    cout << account[0].no_of_transactions + account[1].no_of_transactions << endl;
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
        closeAllAccounts();
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
    if (no_of_accounts < 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (account[i].getStatus() == false)
            {
                account[i].readAccount();
                no_of_accounts++;
                break;
            }
        }
    }

    else
        cout << "\n\t\t\tAccount Limit is Reached!" << endl;
}

void Customer::editAccount()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < no_of_accounts + 1; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].modifyAccountInfo();
            break;
        }
    }
}

void Customer::viewAllAccounts()
{
    for (int i = 0; i < no_of_accounts; i++)
    {
        if (account[i].getStatus() == true)
            account[i].displayAccountInfo();
    }
}

void Customer::closeAccount()
{
    viewAllAccounts();

    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < 3; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].deleteAccount();
            no_of_accounts--;
            cout << "\nAccount is Successfully Closed!";
            break;
        }
    }
}

void Customer::closeAllAccounts()
{
    for (int i = 0; i < no_of_accounts; i++)
        account[i].deleteAccount();

    cout << "\nAll Accounts are Successfully Closed!";
}

void Customer::depositInAccount()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].depositAmount();
            break;
        }
    }
}

void Customer::withdrawFromAccount()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].withdrawAmount();
            break;
        }
    }
}

// functions for integration of transaction class
void Customer::doTransaction(int index, string receiver_accno, float transaction_amount)
{
    account[index].makeTransaction(receiver_accno, transaction_amount);
}

void Customer::viewTransaction()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].showTransactions();
            break;
        }
    }
}

void Customer::removeTransactions()
{
    cout << "\nEnter the Account Number: ";
    cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].eraseTransactions();
            break;
        }
    }
}

// initiallizing static count data member
int Customer::custmr_count = 0;

const int CUSTOMERS_LIMIT = 15;
Customer custmr[CUSTOMERS_LIMIT];

#endif /* Child_Customer_Class_hpp */
