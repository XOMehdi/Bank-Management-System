#ifndef Transaction_Class_hpp
#define Transaction_Class_hpp

#include <iostream>
#include <ctime>
using namespace std;

class Transaction
{
private:
    string sender_accnum, receiver_accnum, transaction_time;
    float transaction_amount;
    int sender_index, receiver_index;
    bool sender_cond, receiver_cond; // variables to be assigned 'true' only if sender & receiver's account exist with the entered account number

public:
    Transaction();
    void makeTransaction();

    // getter functions
    string getTransactionTime();
    float getTransactionAmount();
    string getSenderAccNo();
    string getReceiverAccNo();
};

Transaction::Transaction()
{
    transaction_time = "None";
    sender_cond = false;
    receiver_cond = false;
}

void Transaction::makeTransaction()
{
    do
    {
        cout << "Please enter your Bank Account Number: ";
        cin >> sender_accnum;

        cout << "Please enter the Receiver's  Bank Account Number: ";
        cin >> receiver_accnum;

        cout << "Please enter the Transaction Amount: ";
        cin >> transaction_amount;

        for (int i = 0; i < 50; i++)
        {
            if (sender_accnum == user[i].getUserAccNo())
            {
                sender_index = i;
                sender_cond = true;
            }

            else if (receiver_accnum == user[i].getUserAccNo())
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
                cout << "No Accounts exist with the specified Account Number: " << endl;
                cout << sender_accnum << endl;
                cout << receiver_accnum << endl;
                cout << "----------------------------------------------------------------------------------------------" << endl;
            }

            cout << "Try Again!" << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;
        }

    } while (sender_cond == false || receiver_cond == false);

    user[receiver_index].addBalance(transaction_amount);
    user[sender_index].subtractBalance(transaction_amount);

    time_t current_time = time(0);
    transaction_time = ctime(&current_time);

    // a characters array to store only relevant characters from the 'transaction_time' string variable
    char relevant_time[24];
    for (int i = 0; i < 24; i++)
    {
        relevant_time[i] = transaction_time[i];
    }

    // resetting the value of 'transaction_time' variable with correct info from the char array
    transaction_time = relevant_time[0];
    for (int i = 1; i < 24; i++)
    {
        transaction_time += relevant_time[i];
    }

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Transaction Successful!!!" << endl;
    cout << "An amount of $" << transaction_amount << " successfully transferred to a user with Account Number: " << receiver_accnum << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Your Bank Balance before Transaction: " << '$' << user[sender_index].getBalance() + transaction_amount << endl;
    cout << "Your Bank Balance after Transaction: " << '$' << user[sender_index].getBalance() << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

string Transaction::getTransactionTime()
{
    return transaction_time;
}

float Transaction::getTransactionAmount()
{
    return transaction_amount;
}

string Transaction::getSenderAccNo()
{
    return sender_accnum;
}

string Transaction::getReceiverAccNo()
{
    return receiver_accnum;
}

Transaction trans[5];

#endif /* Transaction_Class_hpp */