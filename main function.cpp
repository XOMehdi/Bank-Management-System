
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

//            ----------------------------VIEW FUNCTIONS FOR MANAGERS-----------------------
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
//           ------------------------------------------------------------------------

//            ----------------------------SIGN UP FUNCTIONS-----------------------
void createManager()
{
	for (int i = 0; i < 10; i++)
	{
		if (managr[i].getStatus() == false)
		{
			managr[i].readManager();
			break;
		}
	}
}

void createCustomer()
{
	for (int i = 0; i < 20; i++)
	{
		if (custmr[i].getStatus() == false)
		{
			custmr[i].readCustomer();
			break;
		}
	}
}
//           ------------------------------------------------------------------------

//            ----------------------------CUSTOMER OPTIONS FOR MANAGER FUNCTION-----------------------
void managerOptionsCustomer()
{
	cout << "\n\n\t\t\t\tCustomer info \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t| Choose an Option:                  |" << endl;
	cout << "\t\t\t|  1. Edit a Customer                |" << endl;
	cout << "\t\t\t|  2. Remove a Customer              |" << endl;
	cout << "\t\t\t|  3. Show All Customers             |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;

	string cid;
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		cout << "Enter Customer's ID to edit its details: ";
		cin >> cid;

		for (int i = 0; i < 20; i++)
		{
			if (cid == custmr[i].getCustomerID())
			{
				custmr[i].modifyCustomerInfo();
				break;
			}
		}
		break;
	}

	case 2:
	{
		cout << "Enter Customer's ID to remove it: ";
		cin >> cid;

		for (int i = 0; i < 20; i++)
		{
			if (cid == custmr[i].getCustomerID())
			{
				custmr[i].deleteCustomer();
				break;
			}
		}
		break;
	}

	case 3:
	{
		for (int i = 0; i < 20; i++)
		{
			if (custmr[i].getStatus() == true)
			{
				custmr[i].displayCustomer();
				break;
			}
		}
		break;
	}
	}
}
//           ------------------------------------------------------------------------

//            ----------------------------MANAGER'S DATA VIEW/EDIT FUNCTION-----------------------
void managerData(string managr_pin)
{
	cout << "\n\n\t\t\t\tManager  \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t| Choose an Option:                  |" << endl;
	cout << "\t\t\t|  1. View Your Details              |" << endl;
	cout << "\t\t\t|  2. Edit Your Details              |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;

	int opt;
	cin >> opt;

	switch (opt)
	{
	case 1:
	{
		for (int i = 0; i < 10; i++)
		{
			if (managr_pin == managr[i].getPin())
			{
				managr[i].displayManager();
				break;
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < 10; i++)
		{
			if (managr_pin == managr[i].getPin())
			{
				managr[i].modifyManagerInfo();
				break;
			}
		}
		break;
	}
	}
}
//           ------------------------------------------------------------------------

//            ----------------------------ALL CONTROLS FOR MANAGERS FUNCTION-----------------------
void managerOptions(string managr_pin)
{
	for (int i = 0; i < 10; i++)
	{
		if (managr_pin == managr[i].getPin())
		{
			cout << "\n\n\t\t\t\tWelcome Mr" << managr[i].getName() << "\n";
			cout << "\t\t\t|------------------------------------|" << endl;
			cout << "\t\t\t|  Choose an Option:                 |" << endl;
			cout << "\t\t\t|       1. Self Operations           |" << endl;
			cout << "\t\t\t|       2. Customer Operations       |" << endl;
			cout << "\t\t\t|       3. View All Transactions     |" << endl;
			cout << "\t\t\t|       4. View All Accounts         |" << endl;
			cout << "\t\t\t|------------------------------------|" << endl;

			int manager_opt;
			cin >> manager_opt;

			switch (manager_opt)
			{
			case 1:
				managerData(managr_pin);
				break;

			case 2:
				managerOptionsCustomer();
				break;

			case 3:
				viewTransactions();
				break;

			case 4:
				viewAccountsInfo();
				break;
			}
		}
	}
}
//           ------------------------------------------------------------------------

//            ----------------------------ADVANCED ACCOUNT OPTIONS FOR CUSTOMER FUNCTION-----------------------
void accountOperations()
{
	for (int i = 0; i < 25; i++)
	{
		if (accounts[i].getStatus() == false)
		{
			accounts[i].readAccount();

			cout << "|Account Number --- Account Holder Name --- Account Balance|" << endl;
			accounts[i].displayAccountInfo();
			break;
		}
	}

	cout << "\n\n\t\t\t\tAdvanced Account Operations \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  Choose an Option:                 |" << endl;
	cout << "\t\t\t|  1. Deposit Amount                 |" << endl;
	cout << "\t\t\t|  2. Withdraw Amount                |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;

	string acnum;
	int key;
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
			}
		}
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
			}
		}
	}
	}
}

//            ----------------------------ALL ACCOUNT OPTIONS FOR CUSTOMER FUNCTION-----------------------
void accountOptions()
{
	cout << "\n\n\t\t\t\tAccount info \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  Choose an Option:                 |" << endl;
	cout << "\t\t\t|  1. Open an Account                |" << endl;
	cout << "\t\t\t|  2. Close an Account               |" << endl;
	cout << "\t\t\t|  3. Edit Account Info              |" << endl;
	cout << "\t\t\t|  4. Display Account Info           |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;

	string acc_no;
	int account_oper;

	cin >> account_oper;

	switch (account_oper)
	{
	case 1:
	{
		// make function

		break;
	}

	case 2:
	{
		cout << "Enter the Account Number: ";
		cin >> acc_no;

		for (int i = 0; i < 25; i++)
		{
			if (acc_no == accounts[i].getAccountNo())
			{
				accounts[i].deleteAccount();
				cout << "\nAccount is Successfully Closed!";
			}
		}
		break;
	}

	case 3:
	{
		cout << "Enter the Account Number: ";
		cin >> acc_no;

		for (int i = 0; i < 25; i++)
		{
			if (acc_no == accounts[i].getAccountNo())
			{
				accounts[i].modifyAccountInfo();
			}
		}
		break;
	}

	case 4:
	{
		viewAccountsInfo();
		break;
	}
	}
}
//            ----------------------------ALL CONTROLS FOR CUSTOMERS FUNCTION-----------------------
void customerOptions(string cust_pin)
{
	for (int i = 0; i < 20; i++)
	{
		if (cust_pin == custmr[i].getPin())
		{
			cout << "\n\n\t\t\t\tWelcome Mr" << custmr[i].getName() << "\n";
			cout << "\t\t\t|------------------------------------|" << endl;
			cout << "\t\t\t|  Choose an Option:                 |" << endl;
			cout << "\t\t\t|       1. Edit Your Details         |" << endl;
			cout << "\t\t\t|       2. Delete Your Details       |" << endl;
			cout << "\t\t\t|       3. Account Options           |" << endl;
			cout << "\t\t\t|       4. Make a Transaction        |" << endl;
			cout << "\t\t\t|------------------------------------|" << endl;

			int cust_opt;
			cin >> cust_opt;

			switch (cust_opt)
			{
			case 1:
			{
				for (int i = 0; i < 20; i++)
				{
					if (cust_pin == custmr[i].getPin())
					{
						custmr[i].modifyCustomerInfo();
					}
				}
				break;
			}

			case 2:
			{
				for (int i = 0; i < 20; i++)
				{
					if (cust_pin == custmr[i].getPin())
					{
						custmr[i].deleteCustomer();
					}
				}
				break;
			}

			case 3:
			{
				accountOptions();
				break;
			}

			case 4:
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
			}
		}
	}
}
//           ------------------------------------------------------------------------

//									MAIN FUNCTION
int main()
{
	string manager_pin, customer_pin;
	int signOrLog, signUp, logIn;

	do
	{
		cout << "\t\t\t----------------------------------------------------";
		cout << "\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl;
		cout << "\t\t\t----------------------------------------------------\n\n";

		cout << "\t\t\t|------------------------------------|" << endl;
		cout << "\t\t\t|  Choose an Option:                 |" << endl;
		cout << "\t\t\t|       1. Sign Up         			|" << endl;
		cout << "\t\t\t|       2. Log In                    |" << endl;
		cout << "\t\t\t|       3. Exit           			|" << endl;
		cout << "\t\t\t|------------------------------------|" << endl;

		cout << "\t\t\t\tEnter a number: ";
		cin >> signOrLog;

		switch (signOrLog)
		{
		case 1:
		{
			do
			{
				cout << "\t\t\t|------------------------------------|" << endl;
				cout << "\t\t\t|  Sign Up As:                       |" << endl;
				cout << "\t\t\t|       1. Manager         			|" << endl;
				cout << "\t\t\t|       2. Customer                  |" << endl;
				cout << "\t\t\t|       3. Exit Menu          		|" << endl;
				cout << "\t\t\t|------------------------------------|" << endl;

				cout << "\t\t\t\tEnter a number: ";
				cin >> signUp;

				switch (signUp)
				{
				case 1:
					createManager();
					break;

				case 2:
					createCustomer();
					break;

				case 3:
					system("cls");
					break;

				default:
					cout << "Incorrect Key Entered! \nTry Again!" << endl;
					break;
				}

			} while (signUp != 3);
		}

		case 2:
		{
			do
			{
				cout << "\t\t\t|------------------------------------|" << endl;
				cout << "\t\t\t|  Log In As:                        |" << endl;
				cout << "\t\t\t|       1. Manager         			|" << endl;
				cout << "\t\t\t|       2. Customer                  |" << endl;
				cout << "\t\t\t|       3. Exit Menu          		|" << endl;
				cout << "\t\t\t|------------------------------------|" << endl;

				cout << "\t\t\t\tEnter a number: ";
				cin >> logIn;

				switch (logIn)
				{
				case 1:
				{
					cout << "Enter your Pin: ";
					cin >> manager_pin;

					managerOptions(manager_pin);
					break;
				}

				case 2:
				{
					cout << "Enter your Pin: ";
					cin >> customer_pin;

					customerOptions(customer_pin);
					break;
				}

				default:
					cout << "Incorrect Key Entered! \nTry Again!" << endl;
					break;
				}

			} while (logIn != 3);
		}
		}
	} while (signOrLog != 3);

	return 0;
}