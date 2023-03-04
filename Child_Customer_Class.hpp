#pragma once

#include "Parent_User_Class.hpp"
#include "Account_Class.hpp"
#include "Transaction_Class.hpp"

#include <iostream>

#define CUSTOMERS_LIMIT 15

class Customer : public User
{
private:
    std::string customer_id, phone_number, acc_num;
    int no_of_accounts;
    static int custmr_count;

public:
    Account account[3];

    Customer() : User()
    {
        no_of_accounts = 0;
    }

    void readCustomer();
    void modifyCustomerInfo();
    void displayCustomer();
    void tabularCustomerInfo();
    void deleteCustomer();

    // getter functions
    static int getCustomerCount();
    std::string getCustomerID() const;
    std::string getFullName();
    std::string getPin() const;
    bool getStatus() const;

    // functions for integration of account class
    void openAccount();
    void editAccount();
    void viewAllAccounts();
    void closeAccount();
    void closeAllAccounts();
    void depositInAccount();
    void withdrawFromAccount();

    // functions for integration of transaction class
    void doTransaction(int index, std::string receiver_accno, float transaction_amount);
    void viewTransaction();
    void removeTransactions();
};

extern Customer custmr[CUSTOMERS_LIMIT];
