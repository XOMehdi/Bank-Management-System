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
    bool status;
    static int transactions_count;

public:
    Transaction();
    void recordTransaction(string sender_accnum, string receiver_accnum, float transaction_amount);
    void displayTransaction() const;
    void tabularTransInfo() const;
    void deleteTransRecord();

    // getter functions
    bool getTransactionStatus() const;
    static int getTransCount();
};

// all member functions definitions
Transaction::Transaction()
{
    transaction_time = "  ";
    transaction_date = "  ";
    status = false;
    transaction_amount = 0;
}

void Transaction::recordTransaction(string sender_accnum, string receiver_accnum, float transaction_amount)
{
    status = true;
    this->sender_accnum = sender_accnum;
    this->receiver_accnum = receiver_accnum;
    this->transaction_amount = transaction_amount;
    transactions_count++;

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

void Transaction::displayTransaction() const
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Transaction Time: " << transaction_time << endl;
    cout << "Transaction Date: " << transaction_date << endl;
    cout << "Transferred By (AN): " << sender_accnum << endl;
    cout << "Transferred To (AN): " << receiver_accnum << endl;
    cout << "Transaction Amount: " << transaction_amount << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
}

void Transaction::tabularTransInfo() const
{
    // printing data in a tabular form
    cout << ' ' << transaction_time << "             ";
    cout << transaction_date << "      ";
    cout << sender_accnum << "                ";
    cout << receiver_accnum << "                ";
    cout << transaction_amount << endl;
}

void Transaction::deleteTransRecord()
{
    transaction_time = "  ";
    transaction_date = "  ";
    sender_accnum = "  ";
    receiver_accnum = "  ";
    transaction_amount = 0;
    status = false;
    transactions_count--;
}

bool Transaction::getTransactionStatus() const
{
    return status;
}

int Transaction::getTransCount()
{
    return transactions_count;
}

// initiallizing static count data member
int Transaction::transactions_count = 0;

#endif /* Transaction_Class_hpp */