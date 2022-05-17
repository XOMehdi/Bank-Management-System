#ifndef Transaction_Class_hpp
#define Transaction_Class_hpp

#include <iostream>
using namespace std;

class Transaction
{
private:
    string sender_accnum, receiver_accnum;
    float transaction_amount;
    int sender_index, receiver_index;
    bool sender_cond, receiver_cond; // variables to be assigned 'true' only if sender & receiver's account exist with the entered account number

public:
    Transaction();
    void makeTransaction();
};

Transaction::Transaction()
{
    sender_cond = false;
    receiver_cond = false;

    cout << "Please enter your Bank Account Number: ";
    cin >> sender_accnum;

    cout << "Please enter the Receiver's  Bank Account Number: ";
    cin >> receiver_accnum;

    cout << "Please enter the Transaction Amount: ";
    cin >> transaction_amount;
}

void Transaction::makeTransaction()
{
    do
    {
        for (int i = 0; i < 50; i++)
        {
            if (sender_accnum == user[i].get_Useraccountno())
            {
                sender_index = i;
                sender_cond = true;
            }

            else if (receiver_accnum == user[i].get_Useraccountno())
            {
                receiver_index = i;
                receiver_cond = true;
            }

            if (sender_cond == true && receiver_cond == true)
                break;
        }

        if (sender_cond == false)
        {
            cout << "Transaction Unsuccessful!!!" << endl;
            cout << "A sender/user with the specified Account Number: " << sender_accnum << " cannot be located!";
        }

        else if (receiver_cond == false)
        {
            cout << "Transaction Unsuccessful!!!" << endl;
            cout << "A receiver/user with the specified Account Number: " << receiver_accnum << " cannot be located!";
        }
    } while (sender_cond == false || receiver_cond == false);

    user[receiver_index].addBalance(transaction_amount);
    user[sender_index].subtractBalance(transaction_amount);

    cout << "Transaction Successful!!!" << endl;
    cout << "An amount of $" << transaction_amount << " successfully transferred to a user with Account Number: " << receiver_accnum << endl;
    cout << "\nYour Bank Balance before transaction: " << '$' << user[sender_index].get_balance() + transaction_amount << endl;
    cout << "Your Bank Balance after transaction: " << '$' << user[sender_index].get_balance();
}

#endif /* Transaction_Class_hpp */