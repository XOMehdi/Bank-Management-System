#ifndef Parent_Human_Class_hpp
#define Parent_Human_Class_hpp

#include <iostream>
using namespace std;

class Human
{
protected:
    string full_name, pin;
    bool status;

public:
    Human();
    void readHuman();
    void displayHuman() const;
    void modifyHumanInfo();

    // getter function
    string getPin() const;
    bool getStatus() const;
    string getName() const;
};

Human::Human()
{
    full_name = "  ";
    pin = "  ";
    status = false;
}

void Human::readHuman()
{
    status = true;

    cin.ignore();

    cout << "Please enter your Full Name: ";
    getline(cin, full_name);

    cout << "\nPlease set your Pin/Password (4 digits): ";
    cin >> pin;
}

void Human::modifyHumanInfo()
{
    cin.ignore();

    cout << "\nChange your Full Name: ";
    getline(cin, full_name);

    cout << "\nChange Pin/Password (4 digits): ";
    cin >> pin;
}

void Human::displayHuman() const
{
    cout << "Name: " << full_name << endl;
    cout << "\nPin: " << pin << endl;
}

string Human::getPin() const
{
    return pin;
}

bool Human::getStatus() const
{
    return status;
}

string Human::getName() const
{
    return full_name;
}

#endif /* Parent_Human_Class */