#ifndef Account_Class_hpp
#define Account_Class_hpp

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account
{
private:
    string account_num;
    string account_name;
    float balance;
    bool status = false;

public:
    void readAccount();
    void displayAccountInfo() const;
    void modifyAccountInfo();
    void depositAmount();
    void withdrawAmount();
    void deleteAccount();

    // getter functions
    string getAccountNo() const;
    float getBalance() const;
    bool getStatus() const;

    // functions for integration of transaction class
    void addTransactionAmount(float);
    void subTransactionAmount(float);
};

void Account::readAccount()
{
    status = true;

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

void Account::depositAmount()
{
    float deposit_amount;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Enter the Deposit Amount: ";
    cin >> deposit_amount;
    cout << "----------------------------------------------------------------------------------------------" << endl;

    balance += deposit_amount;
}

void Account::withdrawAmount()
{
    float withdraw_amount;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Enter the Withdrawal Amount: ";
    cin >> withdraw_amount;
    cout << "----------------------------------------------------------------------------------------------" << endl;

    balance -= withdraw_amount;
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
    cout << ' ' << account_num << setw(12) << " ";
    cout << account_name << setw(16) << " ";
    cout << balance << endl;
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

void Account::addTransactionAmount(float transaction_amount)
{
    balance += transaction_amount;
}

void Account::subTransactionAmount(float transaction_amount)
{
    balance -= transaction_amount;
}

void Account::deleteAccount()
{
    account_num = "  ";
    account_name = "  ";
    balance = 0;
    status = false;
}

Account accounts[25];

#endif /* Account_Class_hpp */