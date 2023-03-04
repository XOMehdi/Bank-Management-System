#include "Parent_User_Class.hpp"

//                              ----------------------------------NAME-------------------------------------------
void Name::setFullName(std::string first_name, std::string last_name)
{
    this->first_name = first_name;
    this->last_name = last_name;
}

std::string Name::getFullName()
{
    return first_name + " " + last_name;
}

//                              ----------------------------------USER-------------------------------------------
User::User()
{
    full_name.setFullName("  ", "  ");
    pin = "  ";
    status = false;
}

void User::readUser()
{
    status = true;

    std::string fname, lname;

    std::cout << "Please enter your First Name: ";
    std::cin >> fname;

    std::cout << "\nPlease enter your Last Name: ";
    std::cin >> lname;

    full_name.setFullName(fname, lname);

    std::cout << "\nPlease set your Pin/Password (4 digits): ";
    std::cin >> pin;
}

void User::modifyUserInfo()
{
    std::string fname, lname;

    std::cout << "\nChange your First Name: ";
    std::cin >> fname;

    std::cout << "\nChange your Last Name: ";
    std::cin >> lname;

    full_name.setFullName(fname, lname);

    std::cout << "\nChange Pin/Password (4 digits): ";
    std::cin >> pin;
}

void User::displayUser()
{
    std::cout << "Name: " << full_name.getFullName() << std::endl;
    std::cout << "Pin: " << pin << std::endl;
}