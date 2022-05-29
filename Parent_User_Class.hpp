#ifndef Parent_User_Class_hpp
#define Parent_User_Class_hpp

#include <iostream>
using namespace std;

class User
{
protected:
    string full_name, pin;
    bool status;

public:
    User();
    void readUser();
    void displayUser() const;
    void modifyUserInfo();

    // getter function
    string getPin() const;
    bool getStatus() const;
    string getName() const;
};

// all member functions definitions
User::User()
{
    full_name = "  ";
    pin = "  ";
    status = false;
}

void User::readUser()
{
    status = true;

    cin.ignore();

    cout << "Please enter your Full Name: ";
    getline(cin, full_name);

    cout << "\nPlease set your Pin/Password (4 digits): ";
    cin >> pin;
}

void User::modifyUserInfo()
{
    cin.ignore();

    cout << "\nChange your Full Name: ";
    getline(cin, full_name);

    cout << "\nChange Pin/Password (4 digits): ";
    cin >> pin;
}

void User::displayUser() const
{
    cout << "Name: " << full_name << endl;
    cout << "Pin: " << pin << endl;
}

string User::getPin() const
{
    return pin;
}

bool User::getStatus() const
{
    return status;
}

string User::getName() const
{
    return full_name;
}

#endif /* Parent_User_Class */