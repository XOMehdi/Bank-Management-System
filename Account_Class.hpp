#pragma once

#include "Transaction_Class.hpp"

#include <iostream>

#define ACCOUNTS_LIMIT 45

class Account
{
private:
    std::string account_num, account_name;
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
    std::string getAccountNo() const;
    float getBalance() const;
    bool getStatus() const;
    static int getAccCount();

    // functions for integration of transaction class using operator overloading
    void makeTransaction(std::string receiver_acno, float transaction_amount);
    void showTransactions();
    void eraseTransactions();
    void operator+(float);
    void operator-(float);
};