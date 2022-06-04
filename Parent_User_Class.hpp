#ifndef Parent_User_Class_hpp
#define Parent_User_Class_hpp

#include <iostream>
using namespace std;

// -------------------------NAME CLASS WHOSE OBJECT IS dTO BE USED AS AN ATTRIBUTE IN USER CLASS FOR COMPOSITION--------------------------------
class Name
{
private:
    string first_name;
    string last_name;

public:
    void setFullName(string first_name, string last_name)
    {
        this->first_name = first_name;
        this->last_name = last_name;
    }

    string getFullName()
    {
        return first_name + " " + last_name;
    }
};
// -----------------------------------------------------------------------------

class User
{
protected:
    Name full_name;
    string pin;
    bool status;

public:
    User();
    void readUser();
    void displayUser();
    void modifyUserInfo();

    // pure virtual getter functions in order to implement polymorphism
    virtual string getFullName() = 0;
    virtual string getPin() const = 0;
    virtual bool getStatus() const = 0;
};

// all member functions definitions
User::User()
{
    full_name.setFullName("  ", "  ");
    pin = "  ";
    status = false;
}

void User::readUser()
{
    status = true;

    string fname, lname;

    cout << "Please enter your First Name: ";
    cin >> fname;

    cout << "\nPlease enter your Last Name: ";
    cin >> lname;

    full_name.setFullName(fname, lname);

    cout << "\nPlease set your Pin/Password (4 digits): ";
    cin >> pin;
}

void User::modifyUserInfo()
{
    string fname, lname;

    cout << "\nChange your First Name: ";
    cin >> fname;

    cout << "\nChange your Last Name: ";
    cin >> lname;

    full_name.setFullName(fname, lname);

    cout << "\nChange Pin/Password (4 digits): ";
    cin >> pin;
}

void User::displayUser()
{
    cout << "Name: " << full_name.getFullName() << endl;
    cout << "Pin: " << pin << endl;
}

#endif /* Parent_User_Class */