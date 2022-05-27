#include "Parent_Human_Class.hpp"
#include "Child_Manager_Class.hpp"
#include "Child_Customer_Class.hpp"
#include "Account_Class.hpp"
#include "Transaction_Class.hpp"

#include <iostream>
using namespace std;

/*
Total 10 managers
Total 20 customers
Total 25 accounts
Total 30 transactions
*/

// account as data member of customers (composition)?

//            ----------------------------MAIN FUNCTIONS PROTOTYPES-----------------------

void managerMenu(string);
void managerData(int);
void managerOptionsCustomer(int);

void customerMenu(string);

void accountMenu(int);
void accountOperations(int);
void accountSettings(int);

void transactionOptions(int);

void viewAllTransactions();
void viewAllAccountsInfo();

// used inside account options function
int custmr_signup_count = 0, open_accounts_count = 0, transactions_count;

//           ------------------------------------------------------------------------

//									MAIN FUNCTION
int main()
{
	// --------------------------------------------
	// 3 fixed managers with unique passwords
	managers[0].setData("Moosa Muhy-ud-Din", "8765");
	managers[1].setData("Muhammad Mehdi", "8520");
	managers[2].setData("Hassan Kaamchor", "1234");
	// --------------------------------------------

	int mangOrCust, signOrLog;
	string manager_pin, customer_pin;

	cout << "\t\t\t----------------------------------------------------";
	cout << "\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl;
	cout << "\t\t\t----------------------------------------------------\n\n";

	do
	{
		cout << "\t\t\t|------------------------------------" << endl;
		cout << "\t\t\t|  Choose an Option:                 " << endl;
		cout << "\t\t\t|       1. Are You A Manager         " << endl;
		cout << "\t\t\t|       2. Are You A Customer        " << endl;
		cout << "\t\t\t|       3. Exit           			" << endl;
		cout << "\t\t\t|------------------------------------" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> mangOrCust;
		system("cls");

		switch (mangOrCust)
		{
		case 1:
		{
			cout << "Enter your Pin: ";
			cin >> manager_pin;
			system("cls");

			managerMenu(manager_pin);
			break;
		}

		case 2:
		{
			do
			{
				cout << "\t\t\t|------------------------------------" << endl;
				cout << "\t\t\t|  Choose an Option:                 " << endl;
				cout << "\t\t\t|       1. Sign Up         			" << endl;
				cout << "\t\t\t|       2. Log In                    " << endl;
				cout << "\t\t\t|       3. Exit This Menu          	" << endl;
				cout << "\t\t\t|------------------------------------" << endl;

				cout << "\t\t\t\tEnter a number: ";
				cin >> signOrLog;
				system("cls");

				switch (signOrLog)
				{
				case 1:
				{
					if (custmr_signup_count == 20)
					{
						cout << "\t\t\t\t\tSorry! Customer Slot is Full\n";
						cout << "\t\t\t\t\tNo more Customers can be created at this moment!\n";
						break;
					}

					else
					{
						for (int i = 0; i < 20; i++)
						{
							if (custmr[i].getStatus() == false)
							{
								custmr[i].readCustomer();
								custmr_signup_count++;
								break;
							}
						}
						// system("cls");
						break;
					}
				}

				case 2:
				{
					if (custmr_signup_count == 0)
					{
						cout << "\t\t\t\t\tPlease Sign Up as a Customer First!\n";
						break;
					}

					else
					{
						cout << "Enter your Pin: ";
						cin >> customer_pin;
						system("cls");

						customerMenu(customer_pin);
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

//                      --------------------------FUNCTIONS DEFINITIONS-----------------------

//            ----------------------------ALL CONTROLS FOR MANAGERS FUNCTION-----------------------
void managerMenu(string managers_pin)
{
	int manager_opt;
	for (int i = 0; i < Manager::getManagerCount(); i++)
	{

		if (managers_pin == managers[i].getPin())
		{
			do
			{
				cout << "\n\n\t\t\t\tWelcome Mr '" << managers[i].getName() << "'\n";
				cout << "\t\t\t|------------------------------------" << endl;
				cout << "\t\t\t|  Choose an Option:                 " << endl;
				cout << "\t\t\t|     1. Personal Info               " << endl;
				cout << "\t\t\t|     2. Customer Operations         " << endl;
				cout << "\t\t\t|     3. View All Accounts           " << endl;
				cout << "\t\t\t|     4. View All Transactions       " << endl;
				cout << "\t\t\t|     5. Exit This Menu              " << endl;
				cout << "\t\t\t|------------------------------------" << endl;

				cout << "\t\t\t\tEnter a number: ";
				cin >> manager_opt;

				switch (manager_opt)
				{
				case 1:
					managerData(i);
					break;

				case 2:
				{
					if (custmr_signup_count == 0)
					{
						cout << "\n\t\t\t'No Customer Exists in the system at this moment'\n";
						break;
					}

					else
					{
						managerOptionsCustomer(i);
						break;
					}

					break;
				}

				case 3:
				{
					if (transactions_count == 0)
					{
						cout << "\n\t\t\t'No Account has been opened at the moment'\n";
						break;
					}

					else
					{
						viewAllAccountsInfo();
						break;
					}

					break;
				}

				case 4:
				{
					if (open_accounts_count == 0)
					{
						cout << "\n\t\t\t'No Transaction has been been at the moment'\n";
						break;
					}

					else
					{
						viewAllTransactions();
						break;
					}

					break;
				}

				case 5:
					system("cls");
					break;

				default:
					cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
					break;
				}

			} while (manager_opt != 5);

			break;
		}
	}
}
//           ------------------------------------------------------------------------

//            ----------------------------CUSTOMER OPTIONS FOR MANAGER FUNCTION-----------------------
void managerOptionsCustomer(int index)
{
	int choice;
	do
	{
		cout << "\n\n\t\t\t\tCustomer Options for Manager\n";
		cout << "\t\t\t|------------------------------------" << endl;
		cout << "\t\t\t| Choose an Option:                  " << endl;
		cout << "\t\t\t|     1. View a Customer             " << endl;
		cout << "\t\t\t|     2. Edit a Customer             " << endl;
		cout << "\t\t\t|     3. Remove a Customer           " << endl;
		cout << "\t\t\t|  	 4. Show All Customers          " << endl;
		cout << "\t\t\t|     5. Exit This Menu              " << endl;
		cout << "\t\t\t|------------------------------------" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			managers[index].showCustomer();
			break;

		case 2:
			managers[index].editCustomer();
			break;

		case 3:
			managers[index].removeCustomer();
			custmr_signup_count--;
			break;

		case 4:
			managers[index].showAllCustomers();
			break;

		case 5:
			system("cls");
			break;

		default:
			cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
			break;
		}
	} while (choice != 5);
}
//           ------------------------------------------------------------------------

//            ----------------------------MANAGER'S DATA VIEW/EDIT FUNCTION-----------------------
void managerData(int index)
{
	int opt;
	do
	{
		cout << "\n\n\t\t\t\tManager Options\n";
		cout << "\t\t\t|------------------------------------" << endl;
		cout << "\t\t\t| Choose an Option:                  " << endl;
		cout << "\t\t\t|     1. View Personal Info          " << endl;
		cout << "\t\t\t|     2. Edit Personal Info          " << endl;
		cout << "\t\t\t|     3. Exit This Menu              " << endl;
		cout << "\t\t\t|------------------------------------" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			managers[index].displayManager();
			break;

		case 2:
			managers[index].modifyManagerInfo();
			break;

		case 3:
			system("cls");
			break;

		default:
			cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
			break;
		}
	} while (opt != 3);
}
//           ------------------------------------------------------------------------

//            ----------------------------ALL CONTROLS FOR CUSTOMERS FUNCTION-----------------------
void customerMenu(string cust_pin)
{
	int cust_opt;
	for (int i = 0; i < 20; i++)
	{
		if (cust_pin == custmr[i].getPin())
		{
			do
			{
				cout << "\n\n\t\t\t\tWelcome Mr '" << custmr[i].getName() << "'\n";
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
					custmr_signup_count--;
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
		cout << "\t\t\t|  	 2. Account Operations          " << endl;
		cout << "\t\t\t|  	 3. Account Settings 			" << endl;
		cout << "\t\t\t|     4. Exit This Menu              " << endl;
		cout << "\t\t\t|------------------------------------" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> op;

		switch (op)
		{
		case 1:
		{
			if (open_accounts_count == 25)
			{
				cout << "\t\t\t\t\tSorry! Account Slot is Full\n";
				cout << "\t\t\t\t\tNo more Accounts can be created at this moment!\n";
				break;
			}

			else
			{
				custmr[index].openAccount();
				open_accounts_count++;
				break;
			}
			break;
		}

		case 2:
		{
			if (open_accounts_count == 0)
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
			if (open_accounts_count == 0)
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

		switch (choice)
		{
		case 1:
		{
			if (transactions_count == 30)
			{
				cout << "\t\t\t\t\tSorry! Transaction Limit is Reached\n";
				cout << "\t\t\t\t\tNo more Transactions can be made!\n";
				break;
			}

			else
			{
				custmr[index].doTransaction();
				transactions_count++;
				break;
			}
			break;
		}
		case 2:
		{
			if (transactions_count == 0)
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

//            ----------------------------ACCOUNT OPTIONS/SETTINGS FOR CUSTOMER FUNCTION-----------------------
void accountSettings(int index)
{
	int option;
	do
	{
		cout << "\n\n\t\t\t\tAccount Settings\n";
		cout << "\t\t\t|------------------------------------" << endl;
		cout << "\t\t\t|  Choose an Option:                 " << endl;
		cout << "\t\t\t|  	 1. View Accounts Info          " << endl;
		cout << "\t\t\t|  	 2. Edit Account Info           " << endl;
		cout << "\t\t\t|  	 3. Close an Account            " << endl;
		cout << "\t\t\t|     4. Exit This Menu              " << endl;
		cout << "\t\t\t|------------------------------------" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> option;

		switch (option)
		{
		case 1:
			custmr[index].viewAccount();
			break;

		case 2:
			custmr[index].editAccount();
			break;

		case 3:
			custmr[index].closeAccount();
			open_accounts_count--;
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

//            ----------------------------VIEW FUNCTIONS FOR MANAGERS-----------------------

void viewAllAccountsInfo()
{
	cout << "\n-------------------------Accounts List---------------------------" << endl;
	cout << "|Account Number --- Account Holder Name --- Account Balance|" << endl;
	for (int i = 0; i < open_accounts_count; i++)
	{
		if (accounts[i].getStatus() == true)
			accounts[i].displayAccountInfo();

		else
			cout << "                ---                     ---                 " << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
}

void viewAllTransactions()
{
	cout << "\n---------------------------------------------Transactions List----------------------------------------------------" << endl;
	cout << "|Transaction Time --- Transaction Date --- Transferred By (AN) --- Transferred To (AN) --- Transaction Amount|" << endl;
	for (int i = 0; i < transactions_count; i++)
	{
		if (trans[i].getTransactionStatus() == true)
			trans[i].showTransaction();

		else
			cout << "                  ---                  ---                     ---                     ---                    " << endl;
	}
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
}