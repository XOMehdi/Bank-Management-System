#ifndef Child_Manager_Class_hpp
#define Child_Manager_Class_hpp

#include "Parent_Human_Class.hpp"
#include "Child_Customer_Class.hpp"
#include <iostream>

using namespace std;

class Manager : public Human
{
private:
    string manager_id;
    int no_of_customers;

public:
    Manager() : Human()
    {
        manager_id = "BankManger" + to_string(obj_count);
        no_of_customers = Customer::obj_count;
    }

    void readManager()
    {
        Human::readHuman();

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

    void displayManager() const
    {
        Human::displayHuman();

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }
};

Manager managr[50];

#endif /* Child_Manager_Class_hpp */
