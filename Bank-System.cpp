#include <iostream>
using namespace std;

class User{
private:
    string name, account_num;
    double balance;
    int pin;
    
public:
	double viewBalance(){
		return balance;
	}
	void createAccount(User account){
		getline(cin, account.name);
		cin >> account.account_num;
		cin >> account.balance;
		cin >> account.pin;
	}
	void deposit(double addCash){
		balance += addCash;
	}
	void withdraw(double subCash){
		balance += subCash;
	}
};
int main(){
	user u1;
	u1.createAccount()
	u1.deposit(5000);
	return 0;
}
