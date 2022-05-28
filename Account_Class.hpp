#ifndef Account_Class_hpp
#define Account_Class_hpp

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account
{
private:
    string account_num, account_name;
    float balance;
    bool status;
    static int acc_count;

public:
    Account();
    void readAccount();
    void displayAccountInfo() const;
    void TabularAccInfo() const;
    void modifyAccountInfo();
    void deleteAccount();
    void depositAmount();
    void withdrawAmount();

    // getter functions
    string getAccountNo() const;
    float getBalance() const;
    bool getStatus() const;
    static int getAccCount();

    // functions for integration of transaction class
    void addTransactionAmount(float);
    void subTransactionAmount(float);
    void transferAmount();
    void displayTransaction();
};

Account::Account()
{
    status = false;
    balance = 0;
}

void Account::readAccount()
{
    status = true;
    acc_count++;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Please set an Account Number (8 digits): ";
    cin >> account_num;
    cin.ignore();

    cout << "\nPlease set a Name of The Account Holder: ";
    getline(cin, account_name);

    cout << "\nPlease enter an Amount to be added to the Account Balance : ";
    cin >> balance;

    cout << "\nAccount Created!" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Account::modifyAccountInfo()
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Change Account Number (8 digits): ";
    cin >> account_num;
    cin.ignore();

    cout << "\nChange Account Holder's Name : ";
    getline(cin, account_name);
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

void Account::TabularAccInfo() const
{
    // printing data in a tabular form
    cout << ' ' << account_num << setw(12) << " ";
    cout << account_name << setw(16) << " ";
    cout << balance << endl;
}

void Account::deleteAccount()
{
    account_num = "  ";
    account_name = "  ";
    balance = 0;
    status = false;
    acc_count--;
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

void Account::addTransactionAmount(float transaction_amount)
{
    balance += transaction_amount;
}

/*
// -------operator overloading 'increment' with for loop?
void operator++(int)
{   float transaction_amount;

    cout << "\nPlease enter the Transaction Amount: ";
    cin >> transaction_amount;

    for (int i = 0; i < transaction_amount; i++)
        balance++;
}
*/

void Account::subTransactionAmount(float transaction_amount)
{
    balance -= transaction_amount;
}

int Account::acc_count = 0;

Account accounts[30];

#endif /* Account_Class_hpp */