#pragma once

#include <iostream>

//                              ----------------------------------NAME-------------------------------------------
class Name
{
private:
    std::string first_name;
    std::string last_name;

public:
    void setFullName(std::string first_name, std::string last_name);
    std::string getFullName();
};

//                              ----------------------------------USER-------------------------------------------
class User
{
protected:
    Name full_name;
    std::string pin;
    bool status;

public:
    User();
    void readUser();
    void displayUser();
    void modifyUserInfo();

    // pure virtual getter functions in order to implement polymorphism
    virtual std::string getFullName() = 0;
    virtual std::string getPin() const = 0;
    virtual bool getStatus() const = 0;
};