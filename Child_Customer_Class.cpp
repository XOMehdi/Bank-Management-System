#include "Child_Customer_Class.hpp"

Customer custmr[CUSTOMERS_LIMIT];

// initiallizing static count data member
int Customer::custmr_count = 0;

void Customer::readCustomer()
{
    custmr_count++;
    customer_id = "BkCustomer" + std::to_string(custmr_count);

    std::cout << "\n----------------------------------------------------------------------------------------------" << std::endl;
    User::readUser();

    std::cout << "\nPlease enter your Phone Number: ";
    std::cin >> phone_number;

    std::cout << "\nA Customer with the Customer ID: " << customer_id << " has been created!" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Customer::modifyCustomerInfo()
{
    std::cout << "\n----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Customer ID cannot be changed! " << std::endl;
    std::cout << "Customer ID: " << customer_id << std::endl;

    User::modifyUserInfo();

    std::cout << "\nChange your Phone Number: ";
    std::cin >> phone_number;

    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Customer::displayCustomer()
{
    std::cout << "\n----------------------------------------------------------------------------------------------" << std::endl;
    User::displayUser();

    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Customer ID: " << customer_id << std::endl;
    std::cout << "Number of Accounts: " << no_of_accounts << std::endl;
    std::cout << "Number of Transactions: " << account[0].no_of_transactions + account[1].no_of_transactions << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Customer::tabularCustomerInfo()
{
    // printing data in a tabular form
    std::cout << ' ' << full_name.getFullName() << "     ";
    std::cout << pin << "     ";
    std::cout << phone_number << "       ";
    std::cout << customer_id << "     \t";
    std::cout << no_of_accounts << " \t\t\t    ";
    std::cout << account[0].no_of_transactions + account[1].no_of_transactions << std::endl;
}

void Customer::deleteCustomer()
{
    full_name.setFullName("  ", "  ");
    pin = "  ";
    custmr_count--;
    status = false;
    customer_id = "  ";
    phone_number = "  ";

    if (no_of_accounts > 0)
        closeAllAccounts();
}

int Customer::getCustomerCount()
{
    return custmr_count;
}

std::string Customer::getCustomerID() const
{
    return customer_id;
}

std::string Customer::getFullName()
{
    return full_name.getFullName();
}

std::string Customer::getPin() const
{
    return pin;
}

bool Customer::getStatus() const
{
    return status;
}

// functions for integration of account class
void Customer::openAccount()
{
    if (no_of_accounts < 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (account[i].getStatus() == false)
            {
                account[i].readAccount();
                no_of_accounts++;
                break;
            }
        }
    }

    else
        std::cout << "\n\t\t\tAccount Limit is Reached!" << std::endl;
}

void Customer::editAccount()
{
    std::cout << "\nEnter the Account Number: ";
    std::cin >> acc_num;

    for (int i = 0; i < no_of_accounts + 1; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].modifyAccountInfo();
            break;
        }
    }
}

void Customer::viewAllAccounts()
{
    for (int i = 0; i < no_of_accounts; i++)
    {
        if (account[i].getStatus() == true)
            account[i].displayAccountInfo();
    }
}

void Customer::closeAccount()
{
    viewAllAccounts();

    std::cout << "\nEnter the Account Number: ";
    std::cin >> acc_num;

    for (int i = 0; i < 3; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].deleteAccount();
            no_of_accounts--;
            std::cout << "\nAccount is Successfully Closed!";
            break;
        }
    }
}

void Customer::closeAllAccounts()
{
    for (int i = 0; i < no_of_accounts; i++)
        account[i].deleteAccount();

    std::cout << "\nAll Accounts are Successfully Closed!";
}

void Customer::depositInAccount()
{
    std::cout << "\nEnter the Account Number: ";
    std::cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].depositAmount();
            break;
        }
    }
}

void Customer::withdrawFromAccount()
{
    std::cout << "\nEnter the Account Number: ";
    std::cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].withdrawAmount();
            break;
        }
    }
}

// functions for integration of transaction class
void Customer::doTransaction(int index, std::string receiver_accno, float transaction_amount)
{
    account[index].makeTransaction(receiver_accno, transaction_amount);
}

void Customer::viewTransaction()
{
    std::cout << "\nEnter the Account Number: ";
    std::cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].showTransactions();
            break;
        }
    }
}

void Customer::removeTransactions()
{
    std::cout << "\nEnter the Account Number: ";
    std::cin >> acc_num;

    for (int i = 0; i < no_of_accounts; i++)
    {
        if (acc_num == account[i].getAccountNo())
        {
            account[i].eraseTransactions();
            break;
        }
    }
}