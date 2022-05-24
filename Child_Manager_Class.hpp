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
    int total_customers;
    static int manager_count;

public:
    Manager() : Human()
    {
        total_customers = Customer::customerCount();
    }

    void readManager()
    {
        manager_count++;
        manager_id = "BkManagr" + to_string(manager_count);

        cout << "\n--------------------------------------------------------------------------------------------" << endl;
        Human::readHuman();

        cout << "\nYou are now Registered as a Manager with the Manager ID: " << manager_id << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void displayManager() const
    {
        cout << "\n--------------------------------------------------------------------------------------------" << endl;
        Human::displayHuman();

        cout << "\nManager ID: " << manager_id << endl;
        cout << "\nTotal number of Customers: " << total_customers << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void modifyManagerInfo()
    {
        cout << "\n--------------------------------------------------------------------------------------------" << endl;
        cout << "Manager ID cannot be changed! " << endl;
        cout << "Manager ID: " << manager_id << endl;

        Human::modifyHumanInfo();

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    // functions for integration of customer class
    void showCustomer()
    {
        cout << "Enter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < total_customers; i++)
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

        for (int i = 0; i < total_customers; i++)
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

        for (int i = 0; i < total_customers; i++)
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
        for (int i = 0; i < total_customers; i++)
        {
            if (custmr[i].getStatus() == true)
                custmr[i].displayCustomer();
        }
    }

    static int managerCount()
    {
        return manager_count;
    }
};

int Manager::manager_count = 0;

Manager managr[10];

#endif /* Child_Manager_Class_hpp */
