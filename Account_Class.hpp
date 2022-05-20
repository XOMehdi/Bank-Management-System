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

public:
    void readAccount();                             // function to get data from user
    void displayAccountInfo() const;                // function to show data on screen
    void modifyAccountInfo();                       // function to add new data
    void depositAmount(float deposit_amount = 0);   // function to accept amount and add to balance amount
    void withdrawAmount(float withdraw_amount = 0); // function to accept amount and subtract from balance amount
    void report() const;                            // function to show data in tabular format

    string getAccountNo() const; // function to return account number
    float getBalance() const;    // function to return balance amount
};                               // class ends here

void Account::readAccount()
{
    cout << "Enter the Account Number:";
    cin >> account_num;

    cout << "Enter the Name of The Account Holder: ";
    getline(cin, account_name);

    cout << "Enter The Amount to be added to the Account Balance : ";
    cin >> balance;
    cout << "\nAccount Created..";
}

void Account::displayAccountInfo() const
{
    cout << account_num << setw(10) << " ";
    cout << account_name << setw(10) << " ";
    cout << balance << endl;
}

void Account::modifyAccountInfo()
{
    cout << "Change Account Number: ";
    cin >> account_num;

    cout << "Change Account Holder's Name : ";
    getline(cin, account_name);
}

void Account::depositAmount(float deposit_amount = 0)
{
    float deposit_amount;
    cout << "Enter the Deposit Amount: ";
    cin >> deposit_amount;

    balance += deposit_amount;
}

void Account::withdrawAmount(float withdraw_amount = 0)
{
    float withdraw_amount;
    cout << "Enter the Withdrawal Amount: ";
    cin >> withdraw_amount;

    balance -= withdraw_amount;
}

string Account::getAccountNo() const
{
    return account_num;
}

float Account::getBalance() const
{
    return balance;
}

Account accounts[50];

#endif /* Account_Class_hpp */