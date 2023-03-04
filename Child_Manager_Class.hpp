#pragma once

#include "Parent_User_Class.hpp"
#include "Child_Customer_Class.hpp"

#include <iostream>

#define MANAGERS_LIMIT 3

class Manager : public User
{
private:
    std::string manager_id, customer_id;
    static int manager_count;

public:
    void setData(std::string first_name, std::string last_name, std::string pin);
    void displayManager();
    void modifyManagerInfo();

    // getter functions
    static int getManagerCount();
    std::string getManagerID() const;
    std::string getFullName();
    std::string getPin() const;
    bool getStatus() const;

    // functions for integration of customer class
    void showCustomer();
    void editCustomer();
    void removeCustomer();

    // functions to display all data
    void viewAllCustomersInfo();
    void viewAllAccountsInfo();
    void viewAllTransactions();
};

extern Manager managers[MANAGERS_LIMIT];