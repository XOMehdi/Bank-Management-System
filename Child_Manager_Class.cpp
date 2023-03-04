#include "Child_Manager_Class.hpp"

Manager managers[MANAGERS_LIMIT];

// initiallizing static count data member
int Manager::manager_count = 0;

void Manager::setData(std::string first_name, std::string last_name, std::string pin)
{
    this->full_name.setFullName(first_name, last_name);
    this->pin = pin;

    manager_count++;
    manager_id = "BkManager" + std::to_string(manager_count);
}

void Manager::displayManager()
{
    std::cout << "\n--------------------------------------------------------------------------------------------" << std::endl;
    User::displayUser();

    std::cout << "Manager ID: " << manager_id << std::endl;
    std::cout << "Number of Customers Logged in the System: " << Customer::getCustomerCount() << std::endl;
    std::cout << "Number of Accounts Opened in the System: " << Account::getAccCount() << std::endl;
    std::cout << "Number of Transactions Made through the System: " << Transaction::getTransCount() << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Manager::modifyManagerInfo()
{
    std::cout << "\n--------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Manager ID cannot be changed! " << std::endl;
    std::cout << "Manager ID: " << manager_id << std::endl;

    User::modifyUserInfo();

    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

// functions for integration of customer class
void Manager::editCustomer()
{
    std::cout << "\nEnter the Customer's ID: ";
    std::cin >> customer_id;

    for (int i = 0; i < CUSTOMERS_LIMIT; i++)
    {
        if (customer_id == custmr[i].getCustomerID())
        {
            custmr[i].modifyCustomerInfo();
            break;
        }
    }
}

void Manager::removeCustomer()
{
    std::cout << "\nEnter the Customer's ID: ";
    std::cin >> customer_id;

    for (int i = 0; i < CUSTOMERS_LIMIT; i++)
    {
        if (customer_id == custmr[i].getCustomerID())
        {
            custmr[i].deleteCustomer();
            std::cout << "\nCustomer is Successfully Removed!";
            break;
        }
    }
}

//            ----------------------------VIEW ALL INFO FUNCTIONS-----------------------
void Manager::viewAllCustomersInfo()
{
    std::cout << "\n-----------------------------------------------Customers List---------------------------------------------------" << std::endl;
    std::cout << "|Customer's Name --- Pin --- Phone Number --- Customer ID --- No of Accounts --- No of Transactions|" << std::endl;
    for (int i = 0; i < Customer::getCustomerCount(); i++)
    {
        if (custmr[i].getStatus() == true)
            custmr[i].tabularCustomerInfo();

        else
            std::cout << "                ---                     ---                 " << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
}

void Manager::viewAllAccountsInfo()
{
    std::cout << "\n-------------------------Accounts List---------------------------" << std::endl;
    std::cout << "|Account Number --- Account Holder Name --- Account Balance|" << std::endl;

    for (int i = 0; i < Customer::getCustomerCount(); i++)
    {
        for (int j = 0; j < 2; j++) // 2 = max accounts any customer can have
        {
            if (custmr[i].account[j].getStatus() == true)
                custmr[i].account[j].tabularAccInfo();
        }
    }
    std::cout << "------------------------------------------------------------------" << std::endl;
}

void Manager::viewAllTransactions()
{
    std::cout << "\n---------------------------------------------Transactions List----------------------------------------------------" << std::endl;
    std::cout << "|Transaction Time --- Transaction Date --- Transferred By (AN) --- Transferred To (AN) --- Transaction Amount|" << std::endl;

    for (int i = 0; i < Customer::getCustomerCount(); i++)
    {
        for (int j = 0; j < 2; j++) // 2 = max accounts any customer can have
        {
            for (int k = 0; k < 5; k++)
            {
                if (custmr[i].account[j].trans[k].getTransactionStatus() == true)
                    custmr[i].account[j].trans[k].tabularTransInfo();
            }
        }
    }
    std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
}

std::string Manager::getManagerID() const
{
    return manager_id;
}

std::string Manager::getFullName()
{
    return full_name.getFullName();
}

std::string Manager::getPin() const
{
    return pin;
}

bool Manager::getStatus() const
{
    return status;
}

int Manager::getManagerCount()
{
    return manager_count;
}
