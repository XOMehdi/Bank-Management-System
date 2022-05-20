#ifndef Transaction_Class_hpp
#define Transaction_Class_hpp

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
        cout << "Please enter your Bank Account Number: ";
        cin >> sender_accnum;

        cout << "Please enter the Receiver's  Bank Account Number: ";
        cin >> receiver_accnum;

        cout << "Please enter the Transaction Amount: ";
        cin >> transaction_amount;

        transaction_amount = abs(transaction_amount);

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
                cout << "No Accounts exist with the specified Account Numbers: " << endl;
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

    // retrieving date & time of the transaction
    time_t dt = time(0);
    string date_time = ctime(&dt);

    // a characters array to store only relevant characters from the 'date_time' string variable
    char relevant_dt[24];
    for (int i = 0; i < 24; i++)
    {
        relevant_dt[i] = date_time[i];
    }

    // storing only the time in the 'transaction_time' & the date in the 'transaction_date' variable from the char array
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

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Transaction Successful!!!" << endl;
    cout << "An amount of $" << transaction_amount << " successfully transferred to a user with Account Number: " << receiver_accnum << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Your Bank Balance before Transaction: " << '$' << user[sender_index].getBalance() + transaction_amount << endl;
    cout << "Your Bank Balance after Transaction: " << '$' << user[sender_index].getBalance() << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
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