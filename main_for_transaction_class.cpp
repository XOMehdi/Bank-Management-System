#include "User_Class.hpp"
#include "Transaction_class.hpp"

#include <iostream>

using namespace std;

void displayTransactions();

int main()
{
    user[0].setUserAccountNo("12345678");
    user[0].setUserBalance(250000);

    user[5].setUserAccountNo("23456789");
    user[5].setUserBalance(14000);

    trans[0].makeTransaction();
    trans[2].makeTransaction();

    displayTransactions();

    return 0;
}

void displayTransactions()
{
    cout << "-------------------------------------------Transactions List-------------------------------------" << endl;
    cout << "|Transaction Date & Time  --- Transferred By (AN) --- Transaction Amount --- Transferred To (AN)|" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (trans[i].getTransactionTime() != "None")
            cout << '|' << trans[i].getTransactionTime() << " " << trans[i].getTransactionDate() << " ---      " << trans[i].getSenderAccNo() << "       ---       "
                 << trans[i].getTransactionAmount() << "         ---      " << trans[i].getReceiverAccNo() << "      |" << endl;

        else
            cout << "|                         ---                     ---                    ---                    |" << endl;
    }
}
