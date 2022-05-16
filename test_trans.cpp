#include <iostream>
#include "User_Class.hpp"
#include "Transaction_class.hpp"

using namespace std;

void user_list(User user[], int size);

int main()
{
    user[0].set_Useraccountno("12345678");
    user[0].set_Userbalance(250000);

    user[5].set_Useraccountno("23456789");
    user[5].set_Userbalance(14000);

    Transaction t;
    t.makeTransaction();

    return 0;
}

// function for user list
void user_list(User user[], int size)
{
    cout << "|----------------------------------------------------User List----------------------------------------------------|" << endl;
    cout << "|User Name --- Account No --- User CNIC --- User Balance --- User Adress --- User Father Name --- User Phone Number|" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "|" << user[i].get_Username() << "|" << user[i].get_Useraccountno() << "|" << user[i].get_Usercnic();
        cout << "|" << user[i].get_balance() << "|" << user[i].get_Useraddress() << "|" << user[i].get_Userfathername();
        cout << "|" << user[i].get_Userphoneno() << "|" << endl;
    }
    cout << "|-----------------------------------------------------------------------------------------------------------------|" << endl;
}