//
//  main.cpp
//  P21-8301_HassanSaqib_Project
//  Banking System
//  Created by Hassan Saqib on 10/04/2022.
//

#include <iostream>
#include "User_class.hpp"
#include "Employee.hpp"
#include "Manager.hpp"
#include "Owner.hpp"
#include <string>
#include <iomanip>

using namespace std;
int Manager::manager_cout;
// Function to set owner name and pin

//         functions for owner

// function for cheak balnce in bank
float cheak_balance_inbank(User user[], int size)
{

    float balance = 0.;

    for (int i = 0; size > i; i++)
    {
        balance = user[i].get_balance() + balance;
    }
    return balance;
}
// function for user list
void user_list(User user[], int size)
{
    cout << "|----------------------------------------------------User List----------------------------------------------------|" << endl;
    cout << "|User Name --- Account No --- User CNIC --- User Balance --- User Adress --- User Father Name --- User Phone Number|" << endl;
    for (int i = 0; size > i; i++)
    {
        cout << "|" << user[i].get_Username() << "" << user[i].get_Useraccountno() << user[i].get_Usercnic() << user[i].get_balance() << user[i].get_Useraddress() << user[i].get_Userfathername() << user[i].get_Userphoneno() << " |" << endl;
    }
    cout << "|-----------------------------------------------------------------------------------------------------------------|" << endl;
}

// function for manager list

void Manager_list(Manager manager[], int size)
{
    cout << "|--------------- Manager List ----------------|" << endl;
    cout << "|Manager Name ------- Manager CNNIC -------   |" << endl;
    for (int i = 0; size > i; i++)
    {
        cout << "|" << manager[i].get_Managername() << " " << manager[i].get_managercnic() << "|" << endl;
    }
    cout << "|---------------------------------------------|" << endl;
}

// function for empolyee list

void Employee_list(employee employee[], int size)
{
    cout << "|--------------- Employee List ----------------|" << endl;
    cout << "|Employee Name ------- Employee CNNIC -------   |" << endl;
    for (int i = 0; size > i; i++)
    {
        cout << "|" << employee[i].get_employee_name() << " " << employee[i].get_employee_cnic() << "|" << endl;
    }
    cout << "|---------------------------------------------|" << endl;
}

// function for creating Manager

void Create_Manager(class Manager m1[], int size)
{

    bool cheak_empyty_manager = false;
    int empty_Manager_array = 0;

    for (int i = 0; size > i; i++)
    {
        if (m1[i].get_Managerstatus() == "Not Active" && cheak_empyty_manager != true)
        {
            cheak_empyty_manager = true;
            empty_Manager_array = i;

            break;
        }
        else
        {
            cheak_empyty_manager = false;
        }
    }

    if (cheak_empyty_manager)
    {

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Creating              |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Manager               |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;

        string temp_name, temp_cnic, temp_pin, temp_pin2;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Manager                 |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Name                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_name;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Manager                 |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Cnic                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_cnic;

        do
        {

            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Enter                   |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Manager                 |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Pin                     |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin;

            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Confirm                 |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Manager                 |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Pin                     |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin2;

        } while (temp_pin != temp_pin2);

        m1[empty_Manager_array].set_managername(temp_name);
        m1[empty_Manager_array].set_managercnic(temp_cnic);
        m1[empty_Manager_array].set_managerpin(temp_pin);
        m1[empty_Manager_array].set_managerstatus("Active");
    }
    else
    {

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Manager               |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Full                  |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
    }
}
// function for creating employeee

void Create_Employee(class employee E1[], int size)
{

    bool cheak_empyty_employee = false;
    int empty_employee_array = 0;

    for (int i = 0; size > i; i++)
    {

        if (E1[i].get_employee_status() == "Not Active" && cheak_empyty_employee != true)
        {
            cheak_empyty_employee = true;
            empty_employee_array = i;

            break;
        }
        else
        {
            cheak_empyty_employee = false;
        }
    }

    if (cheak_empyty_employee)
    {

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Creating              |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Employee              |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;

        string temp_name, temp_cnic, temp_pin, temp_pin2;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Employee                |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Name                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_name;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Employee                |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Cnic                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_cnic;

        do
        {

            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Enter                   |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Employee                |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Pin                     |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin;

            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Confirm                 |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Employee                |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Pin                     |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin2;

        } while (temp_pin != temp_pin2);

        E1[empty_employee_array].set_employee_name(temp_name);
        E1[empty_employee_array].set_employee_cnic(temp_cnic);
        E1[empty_employee_array].set_employee_pin(temp_pin);
        E1[empty_employee_array].set_employee_status("Active");
    }
    else
    {

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Employee              |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Full                  |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
    }
}

// function for creating user

void Create_User(class User user[], int size)
{

    bool cheak_empyty_user = false;
    int empty_user_array = 0;

    for (int i = 0; size > i; i++)
    {
        if (user[i].get_status() == "Not Active" && cheak_empyty_user != true)
        {
            cheak_empyty_user = true;
            empty_user_array = i;

            break;
        }
        else
        {
            cheak_empyty_user = false;
        }
    }

    if (cheak_empyty_user)
    {

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Creating              |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              User                  |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;

        string temp_name, temp_cnic, temp_pin, temp_pin2, temp_address, temp_phonenumber, temp_acountno, temp_fathername, temp_status;

        float temp_balance = 0;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            User                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Name                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_name;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Employee                |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Cnic                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_cnic;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            User                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Address                 |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_address;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            User                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Phone Number            |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_phonenumber;

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Enter                   |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            User                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Father Name             |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>";
        cin >> temp_fathername;

        do
        {
            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Enter                   |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            User                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            pin                     |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin;

            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            Confirm                 |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            User                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|            pin                     |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin2;

            if (temp_pin != temp_pin2)
            {
                cout << "Please Enter pin again " << endl;
            }

        } while (temp_pin != temp_pin2);

        if (empty_user_array < 10)
        {
            temp_acountno = "Bank" + to_string(0) + to_string(empty_user_array);
        }
        else
        {
            temp_acountno = "Bank" + to_string(empty_user_array);
        }

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            User                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Account No :            |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "=>" << temp_acountno << endl;

        temp_status = "Active";

        user[empty_user_array].set_Username(temp_name);
        user[empty_user_array].set_Usercnic(temp_cnic);
        user[empty_user_array].set_Userpin(temp_pin);
        user[empty_user_array].set_Useradress(temp_address);
        user[empty_user_array].set_Userphoneno(temp_phonenumber);
        user[empty_user_array].set_Useraccountno(temp_acountno);
        user[empty_user_array].set_Userfathername(temp_fathername);
        user[empty_user_array].set_Userstatus(temp_status);
        user[empty_user_array].set_Userbalance(temp_balance);

        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            User                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Account                 |" << endl;
        cout << "|                                    |" << endl;
        cout << "|            Created                 |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
    }
    else
    {
        cout << "|------------------------------------|" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              User                  |" << endl;
        cout << "|                                    |" << endl;
        cout << "|              Full                  |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|                                    |" << endl;
        cout << "|------------------------------------|" << endl;
    }
}

// function for changing owner credentials

void change_owner_credentials(class owner owner1)
{

    string current_pin;

    cout << "|------------------------------------|" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|       Enter Currnet pin            |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "=>";
    cin >> current_pin;

    if (current_pin == owner1.get_ownerpin())
    {

        string temp_pin1, temp_pin2;

        do
        {

            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|       Enter new  pin               |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin1;

            cout << "|------------------------------------|" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|       Confirm  new  pin            |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "=>";
            cin >> temp_pin2;

            if (temp_pin2 != temp_pin1)
            {
                cout << "Please! Enter same pin." << endl;
            }
        } while (temp_pin1 != temp_pin2);
        owner1.set_ownerpin(temp_pin1);
    }
}

int main()
{

    //    ----------------class declaration-------------
    int size_Manager = 10;
    int size_employee = 20;
    int size_User = 100;

    class owner owner1;
    class Manager Manager[size_Manager];
    class employee employee[size_employee];
    class User User[size_User];

    //    Create_User(User, size_User);
    //    user_list(User,size_User);
    //    Manager_list(Manager,size_Manager);
    //    Employee_list(employee,size_employee);
    //   Create_Manager(Manager,size_Manager);
    //    Manager_list(Manager,size_Manager);
    //    Create_Employee(employee, size_employee);
    //    Employee_list(employee,size_employee);
    //    change_owner_credentials(owner1);
    //    ---------------class declaration end-------------

    cout << "|------------------------------------|" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|              Bank                  |" << endl;
    cout << "|                                    |" << endl;
    cout << "|            Managment               |" << endl;
    cout << "|                                    |" << endl;
    cout << "|             System                 |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|------------------------------------|" << endl;

    int condition1;
    string global_exit = "No exit";

    do
    {

        do
        {

            cout << "|------------------------------------|" << endl;
            cout << "|Enter:                              |" << endl;
            cout << "|    1.User                          |" << endl;
            cout << "|                                    |" << endl;
            cout << "|    2.Employee                      |" << endl;
            cout << "|                                    |" << endl;
            cout << "|    3.Manager                       |" << endl;
            cout << "|                                    |" << endl;
            cout << "|    4.Owner                         |" << endl;
            cout << "|                                    |" << endl;
            cout << "|    5.Exit                          |" << endl;
            cout << "|                                    |" << endl;
            cout << "|------------------------------------|" << endl;

            cout << "Enter :";
            cin >> condition1;

            switch (condition1)
            {
                //            ------------------User-------------------------
            case 1:
            {
                cout << "|------------------------------------|" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|           Welcome User             |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|------------------------------------|" << endl;

                cout << "|------------------------------------|" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|        Enter your Pin:             |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|------------------------------------|" << endl;

                break;
            }
                //            ------------------Employee-------------------
            case 2:
            {
                cout << "welcome Employee" << endl;
                cout << "|------------------------------------|" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|         Welcome Employee           |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|------------------------------------|" << endl;

                cout << "|------------------------------------|" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|         login                      |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|------------------------------------|" << endl;
                break;
            }

                //            ---------------Manager---------------------
            case 3:
            {
                cout << "|------------------------------------|" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|         Welcome Manager            |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|------------------------------------|" << endl;

                cout << "|------------------------------------|" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|             login                  |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|             Enter your cnic        |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|------------------------------------|" << endl;
                string login_manager_cheak;
                cout << "=>";
                cin >> login_manager_cheak;

                break;
            }

                //    ---------------Owner------------------
            case 4:
            {
                string pin_cheak;
                //           ------------------------------------
                do
                {
                    cout << "|----------------------------|" << endl;
                    cout << "|                            |" << endl;
                    cout << "|     welcome  " << owner1.get_ownername() << "        |" << endl;
                    cout << "|                            |" << endl;
                    cout << "|                            |" << endl;
                    cout << "|     Enter Pin              |" << endl;
                    cout << "|                            |" << endl;
                    cout << "|                            |" << endl;
                    cout << "|                            |" << endl;
                    cout << "|----------------------------|" << endl;
                    cout << "  Pin:";
                    cin >> pin_cheak;
                } while (!owner1.login_cheak(pin_cheak));

                //            --------------------------------------
                int condition2 = 0;

                do
                {

                    do
                    {

                        cout << "|------------------------------------|" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|      1.Cheak Balance in Bank       |" << endl;
                        cout << "|      2.Add Manager                 |" << endl;
                        cout << "|      3.Add Employee                |" << endl;
                        cout << "|      4.Add User                    |" << endl;
                        cout << "|      5.Manager List                |" << endl;
                        cout << "|      6.Employee List               |" << endl;
                        cout << "|      7.User list                   |" << endl;
                        cout << "|      8.Change Credentials          |" << endl;
                        cout << "|      9.Exit                        |" << endl;
                        cout << "|------------------------------------|" << endl;
                        cout << "Enter :";
                        cin >> condition2;
                        if (condition2 != 1 && condition2 != 2 && condition2 != 3 && condition2 != 4 &&
                            condition2 != 5 && condition2 != 6 && condition2 != 7 && condition2 != 8 && condition2 != 9)
                        {
                            cout << "you have entered an invalid input " << endl;
                            cout << "Please enter again" << endl;
                        }
                    } while (condition2 != 1 && condition2 != 2 && condition2 != 3 && condition2 != 4 &&
                             condition2 != 5 && condition2 != 6 && condition2 != 7 && condition2 != 8 && condition2 != 9);

                    if (condition2 == 1)
                    {
                        //                function for cheak balnce
                        cout << "|------------------------------------|" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|            Total                   |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|            Balance                 |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|            In Bank                 |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|------------------------------------|" << endl;
                        cout << "=>" << cheak_balance_inbank(User, size_User) << endl;
                    }
                    else if (condition2 == 2)
                    {
                        //                function for add manager
                        Create_Manager(Manager, size_Manager);
                    }
                    else if (condition2 == 3)
                    {
                        //                function for add employee
                        Create_Employee(employee, size_employee);
                    }

                    else if (condition2 == 4)
                    {
                        //                function for add user
                        Create_User(User, size_User);
                    }

                    else if (condition2 == 5)
                    {
                        //                function for manager list
                        Manager_list(Manager, size_Manager);
                    }

                    else if (condition2 == 6)
                    {
                        //                function for employee list
                        Employee_list(employee, size_employee);
                    }

                    else if (condition2 == 7)
                    {
                        //                function for User list
                        user_list(User, size_User);
                    }

                    else if (condition2 == 8)
                    {
                        //                function for change credentials
                        change_owner_credentials(owner1);
                    }

                    else if (condition2 == 9)
                    {
                        //                Exit
                        cout << "|------------------------------------|" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|             Good Bye               |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|     Project created By:Felions     |" << endl;
                        cout << "|                                    |" << endl;
                        cout << "|------------------------------------|" << endl;
                    }

                } while (condition2 != 9);
                break;
            }

            case 5:
            {
                global_exit = "Exit";

                cout << "|------------------------------------|" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|              Bank                  |" << endl;
                cout << "|                                    |" << endl;
                cout << "|        Managment   System          |" << endl;
                cout << "|                                    |" << endl;
                cout << "|              Exited                |" << endl;
                cout << "|                                    |" << endl;
                cout << "|                                    |" << endl;
                cout << "|------------------------------------|" << endl;

                break;
            }

            default:
            {
                cout << "you have entered a in valid input" << endl;
                break;
            }
            }
        } while (condition1 != 1 && condition1 != 2 && condition1 != 3 && condition1 != 4 && condition1 != 5);

    } while (global_exit != "Exit");

    return 0;
}
