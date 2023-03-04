#include "Parent_User_Class.hpp"
#include "Child_Manager_Class.hpp"
#include "Child_Customer_Class.hpp"
#include "Account_Class.hpp"
#include "Transaction_Class.hpp"

#include <iostream>
using namespace std;

/*	LIMIT OF OBJECTS IN THE SYSTEM
Total 3 managers
Total 15 customers
Total 45 accounts
Total 225 transactions
    VALUES/SIZES CAN BE ALTERED
*/

//            ----------------------------MAIN FUNCTIONS PROTOTYPES-----------------------
void managerAllControls(string manager_id, string manager_pin);
void customerAllOptions(string customer_id, string customer_pin);
void accountMenu(int index);
void accountOperations(int index);
void accountSettings(int index);
void transactionOptions(int index);
void transferAmount(int index);
//            ------------------------------------------------------------------------

//            ----------------------------MAIN FUNCTION-----------------------
int main()
{
    // --------------------------------------------
    // 3 fixed managers with unique identitites
    managers[0].setData("Moosa", "Muhy-ud-Din", "8765");
    managers[1].setData("Muhammad", "Mehdi", "8520");
    managers[2].setData("Hassan", "Saqib", "1234");
    // --------------------------------------------

    int mangOrCust, signOrLog;
    string managr_id, customr_id, manager_pin, customer_pin;

    cout << "\t\t\t----------------------------------------------------";
    cout << "\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl;
    cout << "\t\t\t----------------------------------------------------\n\n";

    do
    {
        cout << "\t\t\t|------------------------------------" << endl;
        cout << "\t\t\t|  Choose an Option:                 " << endl;
        cout << "\t\t\t|       1. Are You A Manager         " << endl;
        cout << "\t\t\t|       2. Are You A Customer        " << endl;
        cout << "\t\t\t|       3. Exit                      " << endl;
        cout << "\t\t\t|------------------------------------" << endl;

        cout << "\t\t\t\tEnter a number: ";
        cin >> mangOrCust;
        system("cls");

        switch (mangOrCust)
        {
        case 1:
        {
            cout << "\nEnter your ID: ";
            cin >> managr_id;

            cout << "\nEnter your Pin: ";
            cin >> manager_pin;
            system("cls");

            managerAllControls(managr_id, manager_pin);
            break;
        }

        case 2:
        {
            do
            {
                cout << "\t\t\t|------------------------------------" << endl;
                cout << "\t\t\t|  Choose an Option:                 " << endl;
                cout << "\t\t\t|       1. Sign Up                   " << endl;
                cout << "\t\t\t|       2. Log In                    " << endl;
                cout << "\t\t\t|       3. Exit This Menu            " << endl;
                cout << "\t\t\t|------------------------------------" << endl;

                cout << "\t\t\t\tEnter a number: ";
                cin >> signOrLog;
                system("cls");

                switch (signOrLog)
                {
                case 1:
                {
                    if (Customer::getCustomerCount() == CUSTOMERS_LIMIT)
                    {
                        cout << "\t\t\t\t\tSorry! Customer Slot is Full\n";
                        cout << "\t\t\t\t\tNo more Customers can be created at this moment!\n";
                        break;
                    }

                    else
                    {
                        for (int i = 0; i < CUSTOMERS_LIMIT; i++)
                        {
                            if (custmr[i].getStatus() == false)
                            {
                                custmr[i].readCustomer();
                                break;
                            }
                        }
                        break;
                    }
                }

                case 2:
                {
                    if (Customer::getCustomerCount() == 0)
                    {
                        cout << "\t\t\t\t\tPlease Sign Up as a Customer First!\n";
                        break;
                    }

                    else
                    {
                        cout << "\nEnter your ID: ";
                        cin >> customr_id;

                        cout << "\nEnter your Pin: ";
                        cin >> customer_pin;
                        system("cls");

                        customerAllOptions(customr_id, customer_pin);
                        break;
                    }
                }

                case 3:
                    system("cls");
                    break;

                default:
                    cout << "\t\t\t\tIncorrect Key Entered!" << endl;
                    cout << "\t\t\t\tTry Again!" << endl;
                    break;
                }

            } while (signOrLog != 3);
            break;
        }

        case 3:
            cout << "\t\t\t----------------------------------------------------";
            cout << "\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl;
            cout << "\t\t\t\t\t\tEXITED" << endl;
            cout << "\t\t\t----------------------------------------------------\n\n";
            break;

        default:
            cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
            break;
        }

    } while (mangOrCust != 3);

    return 0;
}

//                      --------------------------ALL FUNCTIONS DEFINITIONS-----------------------

//            ----------------------------ALL CONTROLS FOR MANAGERS FUNCTION-----------------------
void managerAllControls(string manager_id, string manager_pin)
{
    int manager_opt;
    for (int i = 0; i < Manager::getManagerCount(); i++)
    {

        if (manager_id == managers[i].getManagerID() && manager_pin == managers[i].getPin())
        {
            do
            {
                cout << "\n\n\t\t\t\tWelcome Mr '" << managers[i].getFullName() << "'\n";
                cout << "\t\t\t|------------------------------------" << endl;
                cout << "\t\t\t|  Choose an Option:                 " << endl;
                cout << "\t\t\t|     1. View Personal Info          " << endl;
                cout << "\t\t\t|     2. Edit Personal Info          " << endl;
                cout << "\t\t\t|     3. Edit a Customer's Info      " << endl;
                cout << "\t\t\t|     4. Remove a Customer           " << endl;
                cout << "\t\t\t|     5. View All Customers          " << endl;
                cout << "\t\t\t|     6. View All Accounts           " << endl;
                cout << "\t\t\t|     7. View All Transactions       " << endl;
                cout << "\t\t\t|     8. Exit This Menu              " << endl;
                cout << "\t\t\t|------------------------------------" << endl;

                cout << "\t\t\t\tEnter a number: ";
                cin >> manager_opt;
                system("cls");

                switch (manager_opt)
                {
                case 1:
                    managers[i].displayManager();
                    break;

                case 2:
                    managers[i].modifyManagerInfo();
                    break;

                case 3:
                {
                    if (Customer::getCustomerCount() == 0)
                    {
                        cout << "\n\t\t\t'No Customer Exists in the system at this moment'\n";
                        break;
                    }

                    else
                    {
                        managers[i].viewAllCustomersInfo();
                        managers[i].editCustomer();
                        break;
                    }

                    break;
                }

                case 4:
                {
                    if (Customer::getCustomerCount() == 0)
                    {
                        cout << "\n\t\t\t'No Customer Exists in the system at this moment'\n";
                        break;
                    }

                    else
                    {
                        managers[i].viewAllCustomersInfo();
                        managers[i].viewAllAccountsInfo();
                        managers[i].removeCustomer();
                        break;
                    }

                    break;
                }

                case 5:
                {
                    if (Customer::getCustomerCount() == 0)
                    {
                        cout << "\n\t\t\t'No Customer Exists in the system at this moment'\n";
                        break;
                    }

                    else
                    {
                        managers[i].viewAllCustomersInfo();
                        break;
                    }

                    break;
                }

                case 6:
                {
                    if (Account::getAccCount() == 0)
                    {
                        cout << "\n\t\t\t'No Account has been opened at the moment'\n";
                        break;
                    }

                    else
                    {
                        managers[i].viewAllAccountsInfo();
                        break;
                    }

                    break;
                }

                case 7:
                {
                    if (Transaction::getTransCount() == 0)
                    {
                        cout << "\n\t\t\t'No Transaction has been been at the moment'\n";
                        break;
                    }

                    else
                    {
                        managers[i].viewAllTransactions();
                        break;
                    }

                    break;
                }

                case 8:
                    system("cls");
                    break;

                default:
                    cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
                    break;
                }

            } while (manager_opt != 8);

            break;
        }
    }
}
//           ------------------------------------------------------------------------

//            ----------------------------ALL CONTROLS FOR CUSTOMERS FUNCTION-----------------------

void customerAllOptions(string customer_id, string customer_pin)
{
    int cust_opt;
    for (int i = 0; i < CUSTOMERS_LIMIT; i++)
    {
        if (customer_id == custmr[i].getCustomerID() && customer_pin == custmr[i].getPin())
        {
            do
            {
                cout << "\n\n\t\t\t\tWelcome Mr '" << custmr[i].getFullName() << "'\n";
                cout << "\t\t\t|------------------------------------" << endl;
                cout << "\t\t\t|  Choose an Option:                 " << endl;
                cout << "\t\t\t|     1. View Personal Info          " << endl;
                cout << "\t\t\t|     2. Edit Personal Info          " << endl;
                cout << "\t\t\t|     3. Delete Personal Info        " << endl;
                cout << "\t\t\t|     4. Account Options             " << endl;
                cout << "\t\t\t|     5. Exit This Menu              " << endl;
                cout << "\t\t\t|------------------------------------" << endl;

                cout << "\t\t\t\tEnter a number: ";
                cin >> cust_opt;
                system("cls");

                switch (cust_opt)
                {
                case 1:
                    custmr[i].displayCustomer();
                    break;

                case 2:
                    custmr[i].modifyCustomerInfo();
                    break;

                case 3:
                    custmr[i].deleteCustomer();
                    break;

                case 4:
                    accountMenu(i);
                    break;

                case 5:
                    system("cls");
                    break;

                default:
                    cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
                    break;
                }
            } while (cust_opt != 5);
            break;
        }
    }
}
//           ------------------------------------------------------------------------

//            ----------------------------ACCOUNTS FIRST MENU FOR CUSTOMERS-----------------------
void accountMenu(int index)
{
    int op;
    do
    {
        cout << "\n\n\t\t\t\tAccount Options\n";
        cout << "\t\t\t|------------------------------------" << endl;
        cout << "\t\t\t|  Choose an Option:                 " << endl;
        cout << "\t\t\t|     1. Open an Account             " << endl;
        cout << "\t\t\t|     2. Account Operations          " << endl;
        cout << "\t\t\t|     3. Account Settings            " << endl;
        cout << "\t\t\t|     4. Exit This Menu              " << endl;
        cout << "\t\t\t|------------------------------------" << endl;

        cout << "\t\t\t\tEnter a number: ";
        cin >> op;
        system("cls");

        switch (op)
        {
        case 1:
        {
            if (Account::getAccCount() == ACCOUNTS_LIMIT)
            {
                cout << "\t\t\t\t\tSorry! Account Slot is Full\n";
                cout << "\t\t\t\t\tNo more Accounts can be created at this moment!\n";
                break;
            }

            else
            {
                custmr[index].openAccount();
                break;
            }
            break;
        }

        case 2:
        {
            if (Account::getAccCount() == 0)
            {
                cout << "\t\t\t\t\tPlease Open An Account First!\n";
                break;
            }

            else
            {
                accountOperations(index);
                break;
            }

            break;
        }

        case 3:
        {
            if (Account::getAccCount() == 0)
            {
                cout << "\t\t\t\t\tPlease Open An Account First!\n";
                break;
            }

            else
            {
                accountSettings(index);
                break;
            }

            break;
        }

        case 4:
            system("cls");
            break;

        default:
            cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
            break;
        }
    } while (op != 4);
}
//           ------------------------------------------------------------------------

//            ----------------------------OPERATIONS ON ACCOUNT FOR CUSTOMER FUNCTION-----------------------

void accountOperations(int index)
{
    int key;
    do
    {
        cout << "\n\n\t\t\t\tAccount Operations \n";
        cout << "\t\t\t|------------------------------------" << endl;
        cout << "\t\t\t| Choose an Option:                  " << endl;
        cout << "\t\t\t|     1. Deposit Amount              " << endl;
        cout << "\t\t\t|     2. Withdraw Amount             " << endl;
        cout << "\t\t\t|     3. Transaction Options         " << endl;
        cout << "\t\t\t|     4. Exit This Menu              " << endl;
        cout << "\t\t\t|------------------------------------" << endl;

        cout << "\t\t\t\tEnter a number: ";
        cin >> key;
        system("cls");

        switch (key)
        {
        case 1:
            custmr[index].depositInAccount();
            break;

        case 2:
            custmr[index].withdrawFromAccount();
            break;

        case 3:
            transactionOptions(index);
            break;

        case 4:
            system("cls");
            break;

        default:
            cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
            break;
        }

    } while (key != 4);
}
//           ------------------------------------------------------------------------

//            ----------------------------TRANSACTION OPTIONS FOR CUSTOMER FUNCTION-----------------------
void transactionOptions(int index)
{
    int choice;
    do
    {
        cout << "\n\n\t\t\t\tTransaction Options \n";
        cout << "\t\t\t|------------------------------------" << endl;
        cout << "\t\t\t| Choose an Option:                  " << endl;
        cout << "\t\t\t|     1. Make a Transaction          " << endl;
        cout << "\t\t\t|     2. View Transaction            " << endl;
        cout << "\t\t\t|     3. Exit This Menu              " << endl;
        cout << "\t\t\t|------------------------------------" << endl;

        cout << "\t\t\t\tEnter a number: ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
        {
            if (Transaction::getTransCount() == TRANSACTIONS_LIMIT)
            {
                cout << "\t\t\t\t\tSorry! Transaction Limit is Reached\n";
                cout << "\t\t\t\t\tNo more Transactions can be made!\n";
                break;
            }

            else
            {
                transferAmount(index);
                break;
            }
            break;
        }

        case 2:
        {
            if (Transaction::getTransCount() == 0)
            {
                cout << "\t\t\t\t\tPlease Make a Transaction First!\n";
                break;
            }

            else
            {
                custmr[index].viewTransaction();
                break;
            }
            break;
        }

        case 3:
            system("cls");
            break;

        default:
            cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
            break;
        }
    } while (choice != 3);
}
//           ------------------------------------------------------------------------

//            ----------------------------BANK TO BANK MONEY TRANSFER B/W ACCOUNTS FUNCTION-----------------------
void transferAmount(int index)
{
    string sender_accnum, receiver_accnum;
    float transaction_amount;
    int sender_i, sender_j, receiver_i, receiver_j;
    bool sender_cond, receiver_cond;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "\nPlease enter your Bank Account Number (8 digits): ";
    cin >> sender_accnum;

    cout << "\nPlease enter the Receiver's  Bank Account Number (8 digits): ";
    cin >> receiver_accnum;

    cout << "\nPlease enter the Transaction Amount: ";
    cin >> transaction_amount;
    cout << "----------------------------------------------------------------------------------------------" << endl;

    transaction_amount = abs(transaction_amount);

    for (int i = 0; i < CUSTOMERS_LIMIT; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sender_accnum == custmr[i].account[j].getAccountNo())
            {
                sender_i = i;
                sender_j = j;
                sender_cond = true;
            }

            else if (receiver_accnum == custmr[i].account[j].getAccountNo())
            {
                receiver_i = i;
                receiver_j = j;
                receiver_cond = true;
            }

            if (sender_cond == true && receiver_cond == true)
                break;
        }
    }

    if (sender_cond == false || receiver_cond == false)
    {
        if (sender_cond == false && receiver_cond == true)
        {
            cout << "----------------------------------------------------------------------------------------------" << endl;
            cout << "Transaction Unsuccessful!!!" << endl;
            cout << "No Account exists with the specified Account Number: " << sender_accnum << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;
        }

        else if (sender_cond == true && receiver_cond == false)
        {
            cout << "----------------------------------------------------------------------------------------------" << endl;
            cout << "Transaction Unsuccessful!!!" << endl;
            cout << "No Account exists with the specified Account Number: " << receiver_accnum << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;
        }

        else if (sender_cond == false && receiver_cond == false)
        {
            cout << "----------------------------------------------------------------------------------------------" << endl;
            cout << "Transaction Unsuccessful!!!" << endl;
            cout << "No Accounts exist with the specified Account Numbers: " << endl;
            cout << sender_accnum << endl;
            cout << receiver_accnum << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;
        }

        cout << "Try Again!" << endl;
    }

    if (sender_cond == true && receiver_cond == true)
    {
        // overloaded operators to add/subtract transaction amounts to/from the accounts' balance
        custmr[sender_i].account[sender_j] - transaction_amount;
        custmr[receiver_i].account[receiver_j] + transaction_amount;

        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << "Transaction Successful!!!" << endl;
        cout << "An amount of $" << transaction_amount << " successfully transferred to an account with Account Number: " << receiver_accnum << endl;
        cout << "\n----------------------------------------------------------------------------------------------" << endl;
        cout << "Your Bank Balance before Transaction: " << '$' << custmr[sender_i].account[sender_j].getBalance() + transaction_amount << endl;
        cout << "Your Bank Balance after Transaction: " << '$' << custmr[sender_i].account[sender_j].getBalance() << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;

        custmr[index].doTransaction(sender_j, receiver_accnum, transaction_amount);
    }
}
//                          ------------------------------------------------------------------------

//            ----------------------------ACCOUNT OPTIONS/SETTINGS FOR CUSTOMER FUNCTION-----------------------
void accountSettings(int index)
{
    int option;
    do
    {
        cout << "\n\n\t\t\t\tAccount Settings\n";
        cout << "\t\t\t|------------------------------------" << endl;
        cout << "\t\t\t|  Choose an Option:                 " << endl;
        cout << "\t\t\t|     1. View Accounts Info          " << endl;
        cout << "\t\t\t|     2. Edit Account Info           " << endl;
        cout << "\t\t\t|     3. Close an Account            " << endl;
        cout << "\t\t\t|     4. Exit This Menu              " << endl;
        cout << "\t\t\t|------------------------------------" << endl;

        cout << "\t\t\t\tEnter a number: ";
        cin >> option;
        system("cls");

        switch (option)
        {
        case 1:
            custmr[index].viewAllAccounts();
            break;

        case 2:
            custmr[index].editAccount();
            break;

        case 3:
            custmr[index].closeAccount();
            break;

        case 4:
            system("cls");
            break;

        default:
            cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
            break;
        }

    } while (option != 4);
}
//           ------------------------------------------------------------------------