#include "Parent_Human_Class.hpp"
#include "Child_Manager_Class.hpp"
#include "Child_Customer_Class.hpp"
#include "Account_Class.hpp"
#include "Transaction_Class.hpp"

#include <iostream>
using namespace std;

void customer_data()
{
	cout << "\n\n\t\t\t\tcustomer info \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  1. Add Customer                   |" << endl;
	cout << "\t\t\t|  2. Remove customer                |" << endl;
	cout << "\t\t\t|  3. Edit customer                  |" << endl;
	cout << "\t\t\t|  4. Show Customer                  |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;
	int Customer_oper;
	switch (Customer_oper)
	{
	case 1:
	{
		for (int i = 0; i < 30; i++)
		{
			if (custmr[i].getStatus() == false)
			{
				custmr[i].readCustomer();
				break;
			}
		}
		break;
	}

	case 2:
	{
		for (int i = 0; i < 30; i++)
		{
			if (custmr[i].getStatus() == true)
			{
				custmr[i].deleteCustomer();
				break;
			}
		}
		break;
	}

	case 3:
	{
		for (int i = 0; i < 30; i++)
		{
			if (custmr[i].getStatus() == true)
			{
				custmr[i].modifyCustomerInfo();
				break;
			}
		}
		break;
	}

	case 4:
	{
		for (int i = 0; i < 30; i++)
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

void manager_data()
{
	cout << "\n\n\t\t\t\tmanager  \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  1. Read manager                   |" << endl;
	cout << "\t\t\t|  2. Display  manager               |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;
	int Customer_oper;
	switch (Customer_oper)
	{
	case 1:
	{
		for (int i = 0; i < 10; i++)
		{
			if (managr[i].getStatus() == false)
			{
				managr[i].readManager();
				break;
			}
		}
		break;
	}
	case 2:
	{
		string pp;
		cout << "Enter your Pin: ";
		cin >> pp;

		for (int i = 0; i < 10; i++)
		{
			if (pp == managr[i].getPin)
			{
				managr[i].displayManager();
				break;
			}
		}
		break;
	}
	}
}
	void transaction_plan()
	{
		cout << "\n\n\t\t\t\tmanager  \n";
		cout << "\t\t\t|------------------------------------|" << endl;
		cout << "\t\t\t|  1. Make transaction               |" << endl;
		cout << "\t\t\t|  2. Get transaction                |" << endl;
		cout << "\t\t\t|  2. show transaction               |" << endl;
		cout << "\t\t\t|------------------------------------|" << endl;
		int Customer_oper;
		switch (Customer_oper)
		{
		case 1:
		{
			makeTransaction();
			break;
		}
		case 2:
		{
			getTransactionStatus();
			break;
		}
		case 3:
		{
			showTransaction();
			break;
		}
		}
	}
	
void amount_setting(){
	cout << "\n\n\t\t\t\tAmount operations  \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  1. Withdram ammount               |" << endl;
	cout << "\t\t\t|  2. Deposit ammount                |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;
	int amount_oper;
	switch (amount_oper)
	{
	case 1:
	{
		withdrawAmount()
	break;
	}
	case 2{
		depositAmount()
		break;
	}	
}
}

void account_edit(){
	cout << "\n\n\t\t\t\taccount info \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  1. open Account                   |" << endl;
	cout << "\t\t\t|  2. close Account                  |" << endl;
	cout << "\t\t\t|  3. Edit Account                   |" << endl;
	cout << "\t\t\t|  4. read Account                   |" << endl;
	cout << "\t\t\t|  5. delete Account                 |" << endl;
	cout << "\t\t\t|  6. Display Account Info           |" << endl;
	cout << "\t\t\t|  7. Modify Account Info            |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;
	int account_oper;
	switch (account_oper)
	{
	case 1:
	{openAccount()
		break;
	}
	case 2:{
		closeAccount()
		break;
	}
	case 3:{
		 editAccount()
		break;
	}
	case 4:{
		readAccount()
		break;
	}
	case 5:{
		deleteAccount()
		break;
	}
	case 6:{
		displayAccountInfo()
		break;
	}
	case 7:{
		modifyAccountInfo()
		break;
	}
	}
}
void customer_edit(){
	cout << "\n\n\t\t\t\tcustomer info \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  1. Read customer                  |" << endl;
	cout << "\t\t\t|  2. Modify customer                |" << endl;
	cout << "\t\t\t|  3. Display customer               |" << endl;
	cout << "\t\t\t|  4. Delete customer                |" << endl;
	cout << "\t\t\t|------------------------------------|" << endl;
	int Customer_oper;
	switch (Customer_oper)
	{
	case 1:
	{
	readCustomer()
		break;
	}
	case 2:{
		modifyCustomerInfo()
		break;
	}
	case 3:{
		displayCustomer()
		break;
	}
	case 4:{
		deleteCustomer()
		break;
	}
	
}
}
	
void transaction_plan(){
	cout << "\n\n\t\t\t\tcustomer info \n";
	cout << "\t\t\t|------------------------------------|" << endl;
	cout << "\t\t\t|  1. Make transaction               |" << endl;
	cout << "\t\t\t|  2. Show transaction               |" << endl;
	cout << "\t\t\t|  3. Get transaction                |" << endl;
	cout << "\t\t\t|  4. Add transaction amount         |" << endl;
	cout << "\t\t\t|  4. sub transaction amount         |" << endl;	
	cout << "\t\t\t|------------------------------------|" << endl;
	int Customer_oper;
	switch (Customer_oper)
	{
	case 1:
	{
	makeTransaction()
		break;
	}
	case 2:{
		showTransaction()
		break;
	}
	case 3:{
		getTransactionStatus()
		break;
	}
	case 4:{
		addTransactionAmount
		break;
	}
	case 5:{
		subTransactionAmount
		break;
	}
}
}
	
	
int main()


{

	cout << "\t\t\t----------------------------------------------------";
	cout << "\n\t\t\t\t\tBANK MANAGEMENT SYSTEM" << endl;
	cout << "\t\t\t----------------------------------------------------\n\n";

	cout << "\t\t\tLog in as" << endl
		 << "\t\t\t  ------------------"
		 << "\t-----------------" << endl
		 << "\t\t\t  |  1 = Customer  |"
		 << " or"
		 << "\t|  2 = Manager  |" << endl
		 << "\t\t\t  ------------------"
		 << "\t-----------------" << endl;

	int logIn;
	cout << "\t\t\t\tEnter 1 or 2 = ";
	cin >> logIn;

	switch (logIn)
	{
	case 1:
	{
		cout << "\n\n\t\t\t\tWellcome Manager \n";
		cout << "\t\t\t|------------------------------------|" << endl;
		cout << "\t\t\t|  operation on :                    |" << endl;
		cout << "\t\t\t|                                    |" << endl;
		cout << "\t\t\t|       1. Manager                   |" << endl;
		cout << "\t\t\t|       2. Customer                  |" << endl;
		cout << "\t\t\t|       3. Transaction               |" << endl;
		cout << "\t\t\t|                                    |" << endl;
		cout << "\t\t\t|------------------------------------|" << endl;

		int choiceM;
		cout << "\t\t\t Enter = ";
		cin >> choiceM;
		switch (choiceM)
		{
		case 1:
		{
			manager_data();
			break;
		}
		case 2:
		{
			customer_data();
			break;
		}
		case 3:
		{
			transaction plan();
			break;
		}
		}

		break;
	}
	case 2:{
			cout<<"\n\n\t\t\t\tWellcome customer";
			cout<<"\t\t\t|------------------------------------|"<<endl;
        	cout<<"\t\t\t|  operation :                       |"<<endl;
        	cout<<"\t\t\t|       1. withdaraw/deposit         |"<<endl;
            cout<<"\t\t\t|       1. transaction               |"<<endl;
            cout<<"\t\t\t|       2. Account settings          |"<<endl;
            cout<<"\t\t\t|       3. customer  setting         |"<<endl;
            cout<<"\t\t\t|------------------------------------|"<<endl;
            
            //system("CLS");
            int choiceC;
            cout<<"\t\t\t Enter = ";
            cin>>choiceC;
            
            switch (choiceC){
            	case 1:{
            		amount_setting();
					break;
				}
				case 2:{
					transaction_plan();
					break;
				}
				case 3:{
					account_edit();
					break;
				}
				case 4:{
					customer_edit();
					break;
				}
			
			}
            
            
			break;
		}
	}
	return 0;
}
