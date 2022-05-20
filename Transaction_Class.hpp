#ifndef Transaction_Class_hpp
#define Transaction_Class_hpp

#include "Account_Class.hpp"
#include <iostream>
#include <ctime>
using namespace std;

class Transaction
{
private:
    string sender_accnum, receiver_accnum, transaction_time, transaction_date;
    float transaction_amount;
    int sender_index, receiver_index;
    bool sender_cond, receiver_cond; // variables to be assigned 'true' only if sender & receiver's account exist with the entered account number

public:
    Transaction();
    void makeTransaction();
    void showTransaction() const;
    bool getTransactionStatus() const;
};

Transaction::Transaction()
{
    transaction_time = "None";
    transaction_date = "None";
    sender_cond = false;
    receiver_cond = false;
    transaction_amount = 0;
}

void Transaction::makeTransaction()
{
    do
    {
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << "Please enter your Bank Account Number: ";
        cin >> sender_accnum;

        cout << "\nPlease enter the Receiver's  Bank Account Number: ";
        cin >> receiver_accnum;

        cout << "\nPlease enter the Transaction Amount: ";
        cin >> transaction_amount;
        cout << "----------------------------------------------------------------------------------------------" << endl;

        transaction_amount = abs(transaction_amount);

        for (int i = 0; i < 50; i++)
        {
            if (sender_accnum == accounts[i].getAccountNo())
            {
                sender_index = i;
                sender_cond = true;
            }

            else if (receiver_accnum == accounts[i].getAccountNo())
            {
                receiver_index = i;
                receiver_cond = true;
            }

            if (sender_cond == true && receiver_cond == true)
                break;
        }

        if (sender_cond == false || receiver_cond == false)
        {
            if (sender_cond == false && receiver_cond == true)
            {
                cout << "----------------------------------------------------------------------------------------------" << endl;
                cout << "Transaction Unsuccessful!!!" << endl;
                cout << "No Account exists with the specified Account Number: " << sender_accnum << endl;
                cout << "----------------------------------------------------------------------------------------------" << endl;
            }

            else if (sender_cond == true && receiver_cond == false)
            {
                cout << "----------------------------------------------------------------------------------------------" << endl;
                cout << "Transaction Unsuccessful!!!" << endl;
                cout << "No Account exists with the specified Account Number: " << receiver_accnum << endl;
                cout << "----------------------------------------------------------------------------------------------" << endl;
            }

            else if (sender_cond == false && receiver_cond == false)
            {
                cout << "----------------------------------------------------------------------------------------------" << endl;
                cout << "Transaction Unsuccessful!!!" << endl;
                cout << "No Accounts exist with the specified Account Numbers: " << endl;
                cout << sender_accnum << endl;
                cout << receiver_accnum << endl;
                cout << "----------------------------------------------------------------------------------------------" << endl;
            }

            cout << "Try Again!" << endl;
        }

    } while (sender_cond == false || receiver_cond == false);

    accounts[receiver_index].addTransactionAmount(transaction_amount);
    accounts[sender_index].subTransactionAmount(transaction_amount);

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Transaction Successful!!!" << endl;
    cout << "An amount of $" << transaction_amount << " successfully transferred to an account with Account Number: " << receiver_accnum << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Your Bank Balance before Transaction: " << '$' << accounts[sender_index].getBalance() + transaction_amount << endl;
    cout << "Your Bank Balance after Transaction: " << '$' << accounts[sender_index].getBalance() << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;

    // retrieving date & time of the transaction
    time_t dt = time(0);
    string date_time = ctime(&dt);

    // a characters array to store only relevant characters from the 'date_time' string variable
    char relevant_dt[24];
    for (int i = 0; i < 24; i++)
    {
        relevant_dt[i] = date_time[i];
    }

    // seprating time & date from the char array and storing them in 'transaction_time' & 'transaction_date' variable respectively
    transaction_date = relevant_dt[0];
    transaction_time = relevant_dt[11];

    for (int i = 1; i < 24; i++)
    {
        if (i < 10 || i >= 19)
        {
            transaction_date += relevant_dt[i];
        }

        else if (i > 11 && i < 19)
            transaction_time += relevant_dt[i];
    }
}

void Transaction::showTransaction() const
{
    // printing data in a tabular form
    cout << ' ' << transaction_time << "         --- ";
    cout << transaction_date << "  --- ";
    cout << sender_accnum << "            --- ";
    cout << receiver_accnum << "            --- ";
    cout << transaction_amount << endl;
}

bool Transaction::getTransactionStatus() const
{
    if (sender_cond == true && receiver_cond == true)
        return true;

    else
        return false;
}

Transaction trans[5];

#endif /* Transaction_Class_hpp */