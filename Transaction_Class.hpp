#pragma once

#include <iostream>

#define TRANSACTIONS_LIMIT 225

class Transaction
{
private:
    std::string sender_accnum, receiver_accnum, transaction_time, transaction_date;
    float transaction_amount;
    bool status;
    static int transactions_count;

public:
    Transaction();
    void recordTransaction(std::string sender_accnum, std::string receiver_accnum, float transaction_amount);
    void displayTransaction() const;
    void tabularTransInfo() const;
    void deleteTransRecord();

    // getter functions
    bool getTransactionStatus() const;
    static int getTransCount();
};