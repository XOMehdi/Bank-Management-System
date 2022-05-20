#include "Transaction_class.hpp"
#include "Account_Class.hpp"

#include <iostream>

using namespace std;

// member function to display all the transactions made by the users
void viewTransactions();
void viewAccountsInfo();

//                               'main function to test the transaction class and accounts class'

int main()
{
    accounts[0].readAccount();

    accounts[3].readAccount();

    trans[0].makeTransaction();
    trans[2].makeTransaction();

    viewTransactions();
    viewAccountsInfo();

    return 0;
}

void viewTransactions()
{
    cout << "---------------------------------------------Transactions List----------------------------------------------------" << endl;
    cout << "|Transaction Time --- Transaction Date --- Transferred By (AN) --- Transferred To (AN) --- Transaction Amount|" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (trans[i].getTransactionStatus() == true)
            trans[i].showTransaction();

        else
            cout << "                  ---                  ---                     ---                     ---                    " << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
}

void viewAccountsInfo()
{
    cout << "-------------------------Accounts List---------------------------" << endl;
    cout << "|Account Number --- Account Holder Name --- Account Balance|" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (accounts[i].getStatus() == true)
            accounts[i].displayAccountInfo();
        else
            cout << "                ---                     ---                 " << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}