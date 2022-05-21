#ifndef Human_Class_hpp
#define Human_Class_hpp

#include <iostream>
using namespace std;

class Human
{
protected:
    string full_name, pin, cnic_number, phone_number;
    static int obj_count;
    bool status;

public:
    Human();
    void readHuman();
    void displayHuman() const;
};

Human::Human()
{
    obj_count++;
    status = false;
}
void Human::readHuman()
{
    status = true;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    cin.ignore();

    cout << "Please enter your Full Name: ";
    getline(cin, full_name);
    cin.ignore();

    cout << "Please set your Pin/Password (4 digits): ";
    cin >> pin;

    cout << "Please enter your CNIC Number: ";
    cin >> cnic_number;

    cout << "Please enter your Phone Number: ";
    cin >> phone_number;
}

void Human::displayHuman() const
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Name: " << full_name << endl;
    cout << "\nCNIC Number: " << cnic_number << endl;
    cout << "\nPhone Number: " << phone_number << endl;
}

#endif /* Human_Class */
