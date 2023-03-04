#include "Account_Class.hpp"

Account::Account()
{
    status = false;
    balance = 0;
}

void Account::readAccount()
{
    status = true;
    acc_count++;

    if (acc_count < 10)
        account_num = "620154387" + std::to_string(acc_count);

    else
        account_num = "62015438" + std::to_string(acc_count);

    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "\nPlease set a Name of The Account Holder: ";
    std::getline(std::cin >> std::ws, account_name);

    std::cout << "\nPlease enter an Amount to be added to the Account Balance : ";
    std::cin >> balance;

    std::cout << "\nAn Account with the Account Number " << account_num << " has been created!" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Account::modifyAccountInfo()
{
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Account Number cannot be changed! " << std::endl;
    std::cout << "Account Number: " << account_num << std::endl;

    std::cout << "\nChange Account Holder's Name : ";
    std::getline(std::cin >> std::ws, account_name);
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Account::displayAccountInfo() const
{
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Account Number: " << account_num << std::endl;
    std::cout << "\nAccount Holder Name: " << account_name << std::endl;
    std::cout << "\nAccount Balance: " << balance << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Account::tabularAccInfo() const
{
    // printing data in a tabular form
    std::cout << ' ' << account_num << "           ";
    std::cout << account_name << " \t    ";
    std::cout << balance << std::endl;
}

void Account::deleteAccount()
{
    account_num = "  ";
    account_name = "  ";
    balance = 0;
    status = false;
    acc_count--;

    if (no_of_transactions > 0)
        eraseTransactions();
}

void Account::depositAmount()
{
    float deposit_amount;

    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Account Balance: " << balance << std::endl;

    std::cout << "\nEnter the Deposit Amount: ";
    std::cin >> deposit_amount;

    std::cout << "\nAn amount of " << deposit_amount << " successfully deposited to Account Number: " << account_num << std::endl;

    balance += deposit_amount;

    std::cout << "\nAccount Balance: " << balance << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

void Account::withdrawAmount()
{
    float withdraw_amount;

    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Account Balance: " << balance << std::endl;

    std::cout << "\nEnter the Withdrawal Amount: ";
    std::cin >> withdraw_amount;

    std::cout << "\nAn amount of " << withdraw_amount << " successfully withdrawn from Account Number: " << account_num << std::endl;

    balance -= withdraw_amount;

    std::cout << "\nAccount Balance: " << balance << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

std::string Account::getAccountNo() const
{
    return account_num;
}

float Account::getBalance() const
{
    return balance;
}

bool Account::getStatus() const
{
    return status;
}

int Account::getAccCount()
{
    return acc_count;
}

// functions for integration of transaction class
void Account::makeTransaction(std::string receiver_acno, float transaction_amount)
{
    if (no_of_transactions < 5)
    {
        for (int i = 0; i < 5; i++)
        {
            if (trans[i].getTransactionStatus() == false)
            {
                trans[i].recordTransaction(account_num, receiver_acno, transaction_amount);
                no_of_transactions++;
                break;
            }
        }
    }

    else
        std::cout << "Transactions Limit is Reached!" << std::endl;
}

void Account::showTransactions()
{
    for (int i = 0; i < no_of_transactions; i++)
    {
        if (trans[i].getTransactionStatus() == true)
            trans[i].displayTransaction();
    }
}

void Account::eraseTransactions()
{
    for (int i = 0; i < 5; i++)
    {
        if (trans[i].getTransactionStatus() == true)
        {
            trans[i].deleteTransRecord();
            no_of_transactions--;
        }
    }
}

// overloaded operators to add/subtract transaction amounts to/from the accounts' balance
void Account::operator+(float transaction_amount)
{
    balance += transaction_amount;
}

void Account::operator-(float transaction_amount)
{
    balance -= transaction_amount;
}

// initiallizing static count data member
int Account::acc_count = 0;
