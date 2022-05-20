#ifndef User_Class_hpp
#define User_Class_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class User
{
private:
    string account_no, name, father_name, address, cnic_number, Phone_number, pin, status;
    float balance;
    static int usercount; // to create acoount number

public:
    //    counstructor for no of users and to assingn account no;
    User()
    {
        ++usercount;
        status = "Not Active";
    }

    void addBalance(float transaction_amount)
    {
        this->balance += transaction_amount;
    }

    void subtractBalance(float transaction_amount)
    {
        this->balance -= transaction_amount;
    }

    //    setters for all objects
    void setUserAccountNo(string i)
    {
        account_no = i;
    }
    void setUsername(string i)
    {
        name = i;
    }
    void setUserAddress(string i)
    {
        address = i;
    }
    void setUserCnic(string i)
    {
        cnic_number = i;
    }
    void setUserFatherName(string i)
    {
        father_name = i;
    }
    void setUserPin(string i)
    {
        pin = i;
    }
    void setUserBalance(float i)
    {
        balance = i;
    }
    void setUserPhoneNo(string i)
    {
        Phone_number = i;
    }
    void setUserStatus(string i)
    {
        status = i;
    }

    //    getters for all objects
    string getUserAccNo()
    {
        return account_no;
    }

    string getUserName()
    {
        return name;
    }

    string getUserAddress()
    {
        return address;
    }

    string getUserCnic()
    {
        return cnic_number;
    }

    string getUserFatherName()
    {
        return father_name;
    }

    string getUserPhoneNo()
    {
        return Phone_number;
    }

    string getUserPin()
    {
        return pin;
    }

    float getBalance()
    {
        return balance;
    }

    int getUserCount()
    {
        return usercount;
    }

    string getStatus()
    {
        return status;
    }

    ~User()
    {
        --usercount;
    }
};
int User::usercount = 0;

User user[50];

#endif /* User_Class_hpp */
