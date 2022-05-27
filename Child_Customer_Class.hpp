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

        cout << "\nCNIC Number: " << cnic_number << endl;
        cout << "\nPhone Number: " << phone_number << endl;
        cout << "\nCustomer ID: " << customer_id << endl;
        cout << "\nNumber of Accounts: " << no_of_accounts << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
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
        no_of_accounts = 0;
    }

    string getCustomerID() const
    {
        return customer_id;
    }

    static int customerCount()
    {
        return custmr_count;
    }

    // functions for integration of account class
    void openAccount()
    {
        for (int i = 0; i < 25; i++)
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

        for (int i = 0; i < total_accounts + 1; i++)
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
        int count_condition = 0;

        for (int i = 0; i < no_of_accounts; i++)
        {
            cout << "Enter Your Account Number " << i + 1 << ": ";
            cin >> acc_num;

            for (int i = 0; i < total_accounts + 1; i++)
            {
                if (acc_num == accounts[i].getAccountNo())
                {
                    count_condition++;

                    if (count_condition == 1)
                        cout << "|Account Number --- Account Holder Name --- Account Balance|" << endl;

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

        for (int i = 0; i < total_accounts + 1; i++)
        {
            if (acc_num == accounts[i].getAccountNo())
            {
                accounts[i].deleteAccount();
                cout << "\nAccount is Successfully Closed!";
                break;
            }
        }
    }

    void depositInAccount()
    {
        cout << "\nEnter the Account Number: ";
        cin >> acc_num;

        for (int i = 0; i < total_accounts + 1; i++)
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

        for (int i = 0; i < total_accounts + 1; i++)
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
        for (int i = 0; i < 30; i++)
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

        int count_condition = 0;

        for (int i = 0; i < no_of_transactions; i++)
        {
            for (int i = 0; i < total_transactions + 1; i++)
            {
                if (acc_num == trans[i].getSenderAccNo())
                {
                    count_condition++;

                    if (count_condition == 0)
                        cout << "|Transaction Time --- Transaction Date --- Transferred By (AN) --- Transferred To (AN) --- Transaction Amount|" << endl;

                    trans[i].showTransaction();
                    break;
                }
            }
        }
    }
};
int Customer::custmr_count = 0;

Customer custmr[20];

#endif /* Child_Customer_Class_hpp */
