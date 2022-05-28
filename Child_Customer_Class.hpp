#ifndef Child_Customer_Class_hpp
#define Child_Customer_Class_hpp

#include "Parent_Human_Class.hpp"
#include "Account_Class.hpp"
#include "Transaction_Class.hpp"
#include <iostream>

using namespace std;

class Customer : public Human
{
private:
    string customer_id, cnic_number, phone_number, acc_num;
    int no_of_accounts, no_of_transactions, total_accounts, total_transactions;
    static int custmr_count;

public:
    Customer() : Human()
    {
        total_accounts = Account::getAccCount();
        total_transactions = Transaction::getTransCount();

        no_of_accounts = 0;
        no_of_transactions = 0;
    }

    void readCustomer()
    {
        custmr_count++;
        customer_id = "BkCustomer" + to_string(custmr_count);

        cout << "\n----------------------------------------------------------------------------------------------" << endl;
        Human::readHuman();

        cout << "\nPlease enter your CNIC Number: ";
        cin >> cnic_number;

        cout << "\nPlease enter your Phone Number: ";
        cin >> phone_number;

        cout << "\nA Customer with the Customer ID: " << customer_id << " has been created!" << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void modifyCustomerInfo()
    {
        cout << "\n----------------------------------------------------------------------------------------------" << endl;
        cout << "Customer ID cannot be changed! " << endl;
        cout << "Customer ID: " << customer_id << endl;

        Human::modifyHumanInfo();

        cout << "\nChange your Phone Number: ";
        cin >> phone_number;

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void displayCustomer() const
    {
        cout << "\n----------------------------------------------------------------------------------------------" << endl;
        Human::displayHuman();

        cout << "CNIC Number: " << cnic_number << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Customer ID: " << customer_id << endl;
        cout << "Number of Accounts: " << no_of_accounts << endl;
        cout << "Number of Transactions: " << no_of_transactions << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void tabularCustomerInfo() const
    {
        // printing data in a tabular form
        cout << ' ' << full_name << "     ";
        cout << pin << "     ";
        cout << cnic_number << "     ";
        cout << phone_number << "     ";
        cout << customer_id << "     \t";
        cout << no_of_accounts << " \t\t\t    ";
        cout << no_of_transactions << endl;
    }

    void deleteCustomer()
    {
        full_name = "  ";
        pin = "  ";
        custmr_count--;
        status = false;
        customer_id = "  ";
        cnic_number = "  ";
        phone_number = "  ";

        if (no_of_accounts > 0)
        {
            closeAllAccounts();
            removeTransactions();
        }
    }

    string getCustomerID() const
    {
        return customer_id;
    }

    static int getCustomerCount()
    {
        return custmr_count;
    }

    // functions for integration of account class
    void openAccount()
    {
        for (int i = 0; i < 30; i++)
        {
            if (accounts[i].getStatus() == false)
            {
                accounts[i].readAccount();
                no_of_accounts++;
                break;
            }
        }
    }

    void editAccount()
    {
        cout << "\nEnter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < 30; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].modifyAccountInfo();
                break;
            }
        }
    }

    void viewAccount()
    {
        for (int i = 0; i < no_of_accounts; i++)
        {
            cout << "\nEnter Your Account Number " << i + 1 << ": ";
            cin >> acc_num;

            for (int i = 0; i < 30; i++)
            {
                if (acc_num == accounts[i].getAccountNo())
                {
                    accounts[i].displayAccountInfo();
                    break;
                }
            }
        }
    }

    void closeAccount()
    {
        cout << "\nEnter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < 30; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].deleteAccount();
                cout << "\nAccount is Successfully Closed!";
                break;
            }
        }
    }

    void closeAllAccounts()
    {
        for (int i = 0; i < no_of_accounts; i++)
        {
            cout << "\nEnter Your Account Number " << i + 1 << ": ";
            cin >> acc_num;

            for (int i = 0; i < 30; i++)
            {
                if (acc_num == accounts[i].getAccountNo())
                {
                    accounts[i].deleteAccount();
                    break;
                }
            }
        }
    }

    void depositInAccount()
    {
        cout << "\nEnter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < 30; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].depositAmount();
                break;
            }
        }
    }

    void withdrawFromAccount()
    {
        cout << "\nEnter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < 30; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].withdrawAmount();
                break;
            }
        }
    }

    // functions for integration of transaction class
    void doTransaction()
    {
        for (int i = 0; i < 50; i++)
        {
            if (trans[i].getTransactionStatus() == false)
            {
                trans[i].makeTransaction();
                no_of_transactions++;
                break;
            }
        }
    }

    void viewTransaction()
    {
        cout << "\nEnter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < no_of_transactions; i++)
        {
            for (int i = 0; i < 50; i++)
            {
                if (acc_num == trans[i].getSenderAccNo())
                {
                    trans[i].showTransaction();
                    break;
                }
            }
        }
    }

    void removeTransactions()
    {
        cout << "\nEnter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < no_of_transactions; i++)
        {
            for (int i = 0; i < 50; i++)
            {
                if (acc_num == trans[i].getSenderAccNo())
                {
                    trans[i].deleteTransRecord();
                    break;
                }
            }
        }
    }
};
int Customer::custmr_count = 0;

Customer custmr[15];

#endif /* Child_Customer_Class_hpp */
