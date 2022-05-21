#ifndef Parent_Human_Class_hpp
#define Parent_Human_Class_hpp

#include <iostream>
using namespace std;

class Human
{
protected:
    string full_name, pin;
    static int obj_count;
    bool status;

public:
    Human();
    void readHuman();
    void displayHuman() const;
    void modifyHumanInfo();
    bool loginCheck(string) const;
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
}

void Human::modifyHumanInfo()
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cin.ignore();

    cout << "\nChange your Full Name: ";
    getline(cin, full_name);
    cin.ignore();

    cout << "\nChange Pin/Password (4 digits): ";
    cin >> pin;
}

void Human::displayHuman() const
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Name: " << full_name << endl;
    cout << "\nPin: " << pin << endl;
}

bool Human::loginCheck(string pin) const
{
    if (this->pin == pin)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int Human::obj_count = 0;

#endif /* Parent_Human_Class */