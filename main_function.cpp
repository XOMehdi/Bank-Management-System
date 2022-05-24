
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

// instead make changes inside respective functions?
int mangr_signup_count = 0, custmr_signup_count = 0;

// make counts for transaction and accounts for efficient code (for loops)
// accounts and transaction optimization still pending

//            ----------------------------MAIN FUNCTIONS PROTOTYPES-----------------------

void managerOptions(string);
void managerData(int);
void managerOptionsCustomer(int);

void customerOptions(string);

void accountOptions(int);
void accountOperations();

void viewAllTransactions();
void viewAllAccountsInfo();

//           ------------------------------------------------------------------------

//									MAIN FUNCTION
int main()
{
	string manager_pin, customer_pin;
	int signOrLog, signUp, logIn;

	cout << "\t\t\t----------------------------------------------------";
	cout << "\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl;
	cout << "\t\t\t----------------------------------------------------\n\n";

	do
	{
		cout << "\t\t\t|------------------------------------" << endl;
		cout << "\t\t\t|  Choose an Option:                 " << endl;
		cout << "\t\t\t|       1. Sign Up         			" << endl;
		cout << "\t\t\t|       2. Log In                    " << endl;
		cout << "\t\t\t|       3. Exit           			" << endl;
		cout << "\t\t\t|------------------------------------" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> signOrLog;
		system("cls");

		switch (signOrLog)
		{
		case 1:
		{
			do
			{
				cout << "\t\t\t|------------------------------------" << endl;
				cout << "\t\t\t|  Sign Up As:                       " << endl;
				cout << "\t\t\t|       1. Manager         			" << endl;
				cout << "\t\t\t|       2. Customer                  " << endl;
				cout << "\t\t\t|       3. Exit This Menu            " << endl;
				cout << "\t\t\t|------------------------------------" << endl;

				cout << "\t\t\t\tEnter a number: ";
				cin >> signUp;
				system("cls");

				switch (signUp)
				{
				case 1:
				{
					if (mangr_signup_count == 10)
					{
						cout << "\t\t\t\t\tSorry Manager Slot is Full\n";
						cout << "\t\t\t\t\tNo more Managers can be created!\n";

						signUp = 3;
						break;
					}

					else
					{
						for (int i = 0; i < 10; i++)
						{
							if (managr[i].getStatus() == false)
							{
								managr[i].readManager();
								mangr_signup_count++;
								break;
							}
						}
						// system("cls");
						break;
					}
				}

				case 2:
				{
					if (custmr_signup_count == 20)
					{
						cout << "\t\t\t\t\tSorry Customer Slot is Full\n";
						cout << "\t\t\t\t\tNo more Customers can be created!\n";

						signUp = 3;
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

				case 3:
					system("cls");
					break;

				default:
					cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
					break;
				}

			} while (signUp != 3);
		}

		case 2:
		{
			do
			{
				cout << "\t\t\t|------------------------------------" << endl;
				cout << "\t\t\t|  Log In As:                        " << endl;
				cout << "\t\t\t|       1. Manager         			" << endl;
				cout << "\t\t\t|       2. Customer                  " << endl;
				cout << "\t\t\t|       3. Exit This Menu            " << endl;
				cout << "\t\t\t|------------------------------------" << endl;

				cout << "\t\t\t\tEnter a number: ";
				cin >> logIn;
				system("cls");

				switch (logIn)
				{
				case 1:
				{
					if (mangr_signup_count < 1)
					{
						cout << "\t\t\t\t\tPlease Sign Up as a Manager first!\n";
						logIn = 3;
						break;
					}

					else
					{
						cout << "Enter your Pin: ";
						cin >> manager_pin;
						system("cls");

						managerOptions(manager_pin);
						break;
					}
				}

				case 2:
				{
					if (custmr_signup_count < 1)
					{
						cout << "\t\t\t\t\tPlease Sign Up as a Customer first!\n";
						logIn = 3;
						break;
					}

					else
					{
						cout << "Enter your Pin: ";
						cin >> customer_pin;
						system("cls");

						customerOptions(customer_pin);
						break;
					}
				}

				case 3:
					system("cls");
					break;

				default:
					cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
					break;
				}

			} while (logIn != 3);
			break;
		}

		case 3:
			cout << "\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl;
			cout << "\t\t\t\t\t\tEXITED" << endl;
			cout << "\t\t\t----------------------------------------------------\n\n";
			break;

		default:
			cout << "\t\t\t\tIncorrect Key Entered!" << endl;
			cout << "\t\t\t\tTry Again!" << endl;
			break;
		}

	} while (signOrLog != 3);

	return 0;
}

//            --------------------------FUNCTIONS DEFINITIONS-----------------------

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
			managr[index].showCustomer();
			break;

		case 2:
			managr[index].editCustomer();
			break;

		case 3:
			managr[index].removeCustomer();
			break;

		case 4:
			managr[index].showAllCustomers();
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
			managr[index].displayManager();
			break;

		case 2:
			managr[index].modifyManagerInfo();
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

//            ----------------------------ALL CONTROLS FOR MANAGERS FUNCTION-----------------------
void managerOptions(string managr_pin)
{
	int manager_opt;
	for (int i = 0; i < 10; i++)
	{

		if (managr_pin == managr[i].getPin())
		{
			do
			{
				cout << "\n\n\t\t\t\tWelcome Mr '" << managr[i].getName() << "'\n";
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
					managerOptionsCustomer(i);
					break;

				case 3:
					viewAllAccountsInfo();
					break;

				case 4:
					viewAllTransactions();
					break;

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

//            ----------------------------ADVANCED ACCOUNT OPTIONS FUNCTION-----------------------

// make this in customer
void accountOperations()
{
	string acnum;
	int key;
	do
	{
		cout << "\n\n\t\t\t\tAdvanced Account Operations \n";
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
		{
			cout << "Enter Your Account Number: ";
			cin >> acnum;

			for (int i = 0; i < 25; i++)
			{
				if (acnum == accounts[i].getAccountNo())
				{
					accounts[i].depositAmount();
					break;
				}
			}
			break;
		}

		case 2:
		{
			cout << "Enter Your Account Number: ";
			cin >> acnum;

			for (int i = 0; i < 25; i++)
			{
				if (acnum == accounts[i].getAccountNo())
				{
					accounts[i].withdrawAmount();
					break;
				}
			}
			break;
		}

		case 3:
		{
			for (int i = 0; i < 30; i++)
			{
				if (trans[i].getTransactionStatus() == false)
				{
					trans[i].makeTransaction();
					break;
				}
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

	} while (key != 3);
}

//            ----------------------------ALL ACCOUNT OPTIONS FOR CUSTOMER FUNCTION-----------------------
void accountOptions(int index)
{
	int option;
	do
	{
		cout << "\n\n\t\t\t\tAccount Options\n";
		cout << "\t\t\t|------------------------------------" << endl;
		cout << "\t\t\t|  Choose an Option:                 " << endl;
		cout << "\t\t\t|  	 1. Open an Account             " << endl;
		cout << "\t\t\t|  	 2. Edit Account Info           " << endl;
		cout << "\t\t\t|  	 3. Display Account Info        " << endl;
		cout << "\t\t\t|  	 4. Close an Account            " << endl;
		cout << "\t\t\t|     5. Exit This Menu              " << endl;
		cout << "\t\t\t|------------------------------------" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> option;

		switch (option)
		{
		case 1:
			custmr[index].openAccount();
			accountOperations();
			break;

		case 2:
			custmr[index].editAccount();
			break;

		case 3:
			custmr[index].viewAccounts();
			break;

		case 4:
			custmr[index].closeAccount();
			break;

		case 5:
			system("cls");
			break;

		default:
			cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
			break;
		}

	} while (option != 5);
}
//            ----------------------------ALL CONTROLS FOR CUSTOMERS FUNCTION-----------------------
void customerOptions(string cust_pin)
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
					break;

				case 4:
					accountOptions(i);
					break;

				case 5:
					system("cls");
					break;

				default:
					cout << "\t\t\t\tIncorrect Key Entered!\n\t\t\t\tTry Again!" << endl;
					break;
				}

			} while (cust_opt != 6);
			break;
		}
	}
}
//           ------------------------------------------------------------------------

//            ----------------------------VIEW FUNCTIONS FOR MANAGERS-----------------------

void viewAllAccountsInfo()
{
	cout << "-------------------------Accounts List---------------------------" << endl;
	cout << "|Account Number --- Account Holder Name --- Account Balance|" << endl;
	for (int i = 0; i < 25; i++)
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
	cout << "---------------------------------------------Transactions List----------------------------------------------------" << endl;
	cout << "|Transaction Time --- Transaction Date --- Transferred By (AN) --- Transferred To (AN) --- Transaction Amount|" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (trans[i].getTransactionStatus() == true)
			trans[i].showTransaction();

		else
			cout << "                  ---                  ---                     ---                     ---                    " << endl;
	}
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
}

//           ------------------------------------------------------------------------