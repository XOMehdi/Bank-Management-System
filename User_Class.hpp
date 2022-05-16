#ifndef User_Class_hpp
#define User_Class_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class User
{
private:
    string account_no;
    string name;
    string address;
    string cnic_number;
    string Phone_number;
    string father_name;
    string pin;
    // float balance;
    string status;
    static int usercount; // to create acoount number

public:
    float balance;
    //    counstructor for no of users and to assingn account no;
    User()
    {
        ++usercount;
        status = "Not Active";
    }

    //    setters for all objects
    void set_Useraccountno(string i)
    {
        account_no = i;
    }
    void set_Username(string i)
    {
        name = i;
    }
    void set_Useradress(string i)
    {
        address = i;
    }
    void set_Usercnic(string i)
    {
        cnic_number = i;
    }
    void set_Userfathername(string i)
    {
        father_name = i;
    }
    void set_Userpin(string i)
    {
        pin = i;
    }
    void set_Userbalance(float i)
    {
        balance = i;
    }
    void set_Userphoneno(string i)
    {
        Phone_number = i;
    }
    void set_Userstatus(string i)
    {
        status = i;
    }

    //    getters for all objects
    string get_Useraccountno()
    {
        return account_no;
    }

    string get_Username()
    {
        return name;
    }

    string get_Useraddress()
    {
        return address;
    }

    string get_Usercnic()
    {
        return cnic_number;
    }

    string get_Userfathername()
    {
        return father_name;
    }

    string get_Userphoneno()
    {
        return Phone_number;
    }

    string get_Userpin()
    {
        return pin;
    }

    float get_balance()
    {
        return balance;
    }

    int get_usercount()
    {
        return usercount;
    }

    string get_status()
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
