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

public:
    Manager() : Human()
    {
        manager_id = "BkManger" + to_string(obj_count);
        no_of_customers = Customer::obj_count;
    }

    void readManager()
    {
        Human::readHuman();

        cout << "\nYou are now Registered as a Manager with the Manager ID: " << manager_id;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void displayManager() const
    {
        Human::displayHuman();

        cout << "\nManager ID: " << manager_id;
        cout << "\nTotal number of Customers: " << no_of_customers;

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void addCustomer()
    {
        for (int i = 0; i < 50; i++)
        {
            if (custmr[i].getStatus() == false)
            {
                custmr[i].readCustomer();
            }
        }
    }

    void removeCustomer()
    {
        cout << "Enter the Customer's ID: ";
        cin >> cust_id;

        for (int i = 0; i < 50; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].deleteCustomer();
                cout << "\nCustomer is Successfully Removed!";
            }
        }
    }

    void editCustomer()
    {
        for (int i = 0; i < 50; i++)
        {
            if (cust_id == custmr[i].getCustomerID())
            {
                custmr[i].modifyCustomerInfo();
            }
        }
    }

    void showCustomer()
    {
        for (int i = 0; i < 50; i++)
            custmr[i].displayCustomer();
    }
};

Manager managr[10];

#endif /* Child_Manager_Class_hpp */
