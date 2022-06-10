#ifndef Account_Class_hpp
#define Account_Class_hpp

#include "Transaction_Class.hpp"
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    string account_num, account_name;
    float balance;
    bool status;
    static int acc_count;

public:
    Transaction trans[5];
    int no_of_transactions;

    Account();
    void readAccount();
    void displayAccountInfo() const;
    void tabularAccInfo() const;
    void modifyAccountInfo();
    void deleteAccount();
    void depositAmount();
    void withdrawAmount();

    // getter functions
    string getAccountNo() const;
    float getBalance() const;
    bool getStatus() const;
    static int getAccCount();

    // functions for integration of transaction class using operator overloading
    void makeTransaction(string receiver_acno, float transaction_amount);
    void showTransactions();
    void eraseTransactions();
    void operator+(float);
    void operator-(float);
};

// all member functions definitions
Account::Account()
{
    status = false;
    balance = 0;
}

void Account::readAccount()
{
    status = true;
    acc_count++;

    if (acc_count < 10)
        account_num = "620154387" + to_string(acc_count);

    else
        account_num = "62015438" + to_string(acc_count);

    cout << "----------------------------------------------------------------------------------------------" << endl;

    cout << "\nPlease set a Name of The Account Holder: ";
    getline(cin >> ws, account_name);

    cout << "\nPlease enter an Amount to be added to the Account Balance : ";
    cin >> balance;

    cout << "\nAn Account with the Account Number " << account_num << " has been created!" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Account::modifyAccountInfo()
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Account Number cannot be changed! " << endl;
    cout << "Account Number: " << account_num << endl;

    cout << "\nChange Account Holder's Name : ";
    getline(cin >> ws, account_name);
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Account::displayAccountInfo() const
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Account Number: " << account_num << endl;
    cout << "\nAccount Holder Name: " << account_name << endl;
    cout << "\nAccount Balance: " << balance << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Account::tabularAccInfo() const
{
    // printing data in a tabular form
    cout << ' ' << account_num << "           ";
    cout << account_name << " \t    ";
    cout << balance << endl;
}

void Account::deleteAccount()
{
    account_num = "  ";
    account_name = "  ";
    balance = 0;
    status = false;
    acc_count--;

    if (no_of_transactions > 0)
        eraseTransactions();
}

void Account::depositAmount()
{
    float deposit_amount;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Account Balance: " << balance << endl;

    cout << "\nEnter the Deposit Amount: ";
    cin >> deposit_amount;

    cout << "\nAn amount of " << deposit_amount << " successfully deposited to Account Number: " << account_num << endl;

    balance += deposit_amount;

    cout << "\nAccount Balance: " << balance << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Account::withdrawAmount()
{
    float withdraw_amount;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Account Balance: " << balance << endl;

    cout << "\nEnter the Withdrawal Amount: ";
    cin >> withdraw_amount;

    cout << "\nAn amount of " << withdraw_amount << " successfully withdrawn from Account Number: " << account_num << endl;

    balance -= withdraw_amount;

    cout << "\nAccount Balance: " << balance << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

string Account::getAccountNo() const
{
    return account_num;
}

float Account::getBalance() const
{
    return balance;
}

bool Account::getStatus() const
{
    return status;
}

int Account::getAccCount()
{
    return acc_count;
}

// functions for integration of transaction class
void Account::makeTransaction(string receiver_acno, float transaction_amount)
{
    if (no_of_transactions < 5)
    {
        for (int i = 0; i < 5; i++)
        {
            if (trans[i].getTransactionStatus() == false)
            {
                trans[i].recordTransaction(account_num, receiver_acno, transaction_amount);
                no_of_transactions++;
                break;
            }
        }
    }

    else
        cout << "Transactions Limit is Reached!" << endl;
}

void Account::showTransactions()
{
    for (int i = 0; i < no_of_transactions; i++)
    {
        if (trans[i].getTransactionStatus() == true)
            trans[i].displayTransaction();
    }
}

void Account::eraseTransactions()
{
    for (int i = 0; i < 5; i++)
    {
        if (trans[i].getTransactionStatus() == true)
        {
            trans[i].deleteTransRecord();
            no_of_transactions--;
        }
    }
}

// overloaded operators to add/subtract transaction amounts to/from the accounts' balance
void Account::operator+(float transaction_amount)
{
    balance += transaction_amount;
}

void Account::operator-(float transaction_amount)
{
    balance -= transaction_amount;
}

// initiallizing static count data member
int Account::acc_count = 0;

#endif /* Account_Class_hpp */