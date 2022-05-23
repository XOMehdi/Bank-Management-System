#ifndef Child_Manager_Class_hpp
#define Child_Manager_Class_hpp

#include "Parent_Human_Class.hpp"
#include "Child_Customer_Class.hpp"
#include <iostream>

using namespace std;

class Manager : public Human
{
private:
    string manager_id, cust_id;
    int no_of_customers;
    static int manager_count;

public:
    Manager() : Human()
    {
        no_of_customers = Customer::customerCount();
    }

    void readManager()
    {
        manager_count++;

        Human::readHuman();

        manager_id = "BkManagr" + to_string(manager_count);

        cout << "\nYou are now Registered as a Manager with the Manager ID: " << manager_id;
        cout << "\n----------------------------------------------------------------------------------------------" << endl;
    }

    void displayManager() const
    {
        Human::displayHuman();

        cout << "\nManager ID: " << manager_id;
        cout << "\nTotal number of Customers: " << no_of_customers;

        cout << "\n----------------------------------------------------------------------------------------------" << endl;
    }

    void modifyManagerInfo()
    {
        cout << "Manager ID cannot be changed! " << endl;
        cout << "\nManager ID: " << manager_id << endl;

        Human::modifyHumanInfo();

        cout << "\n----------------------------------------------------------------------------------------------" << endl;
    }

    void showCustomer()
    {
        cout << "Enter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < 20; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].displayCustomer();
            }
        }
    }

    void editCustomer()
    {
        cout << "Enter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < 20; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].modifyCustomerInfo();
            }
        }
    }

    void removeCustomer()
    {
        cout << "Enter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < 20; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].deleteCustomer();
                cout << "\nCustomer is Successfully Removed!";
            }
        }
    }

    void showAllCustomers()
    {
        for (int i = 0; i < 20; i++)
        {
            if (custmr[i].getStatus() == true)
                custmr[i].displayCustomer();
        }
    }
};

int Manager::manager_count = 0;

Manager managr[10];

#endif /* Child_Manager_Class_hpp */
