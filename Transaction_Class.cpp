#include "Transaction_Class.hpp"

#include <ctime>

Transaction::Transaction()
{
    transaction_time = "  ";
    transaction_date = "  ";
    status = false;
    transaction_amount = 0;
}

void Transaction::recordTransaction(std::string sender_accnum, std::string receiver_accnum, float transaction_amount)
{
    status = true;
    this->sender_accnum = sender_accnum;
    this->receiver_accnum = receiver_accnum;
    this->transaction_amount = transaction_amount;
    transactions_count++;

    // retrieving date & time of the transaction
    time_t dt = time(0);
    std::string date_time = ctime(&dt);

    // a characters array to store only relevant characters from the 'date_time' std::string variable
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
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Transaction Time: " << transaction_time << std::endl;
    std::cout << "Transaction Date: " << transaction_date << std::endl;
    std::cout << "Transferred By (AN): " << sender_accnum << std::endl;
    std::cout << "Transferred To (AN): " << receiver_accnum << std::endl;
    std::cout << "Transaction Amount: " << transaction_amount << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Transaction::tabularTransInfo() const
{
    // printing data in a tabular form
    std::cout << ' ' << transaction_time << "             ";
    std::cout << transaction_date << "      ";
    std::cout << sender_accnum << "                ";
    std::cout << receiver_accnum << "                ";
    std::cout << transaction_amount << std::endl;
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
