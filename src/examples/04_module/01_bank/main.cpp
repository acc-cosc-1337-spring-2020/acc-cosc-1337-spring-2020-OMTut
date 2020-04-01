#include "bank_account.h"
#include <iostream>
#include <vector>

using std::cout; using std::cin;

int main()
{
	CheckingAccount checking{ 100 };
	CheckingAccount checking(90);
	

	//BankAccount a;
	//cout << a.get_balance();

	/*std::vector<BankAccount> accounts{ BankAccount(100), BankAccount(200) };

	for (auto act : accounts)
	{
		cout << act.get_balance() << "\n";
	}*/

	BankAccount account(500); //creates an instance of BankAccount
	cin >> account;
	cout << account;
	display_balance(account);

	auto balance = account.get_balance();
	cout << "Balance is: " << account.get_balance() << "\n";

	auto amount{ 0 };
	cout << "Enter deposit amount: ";
	cin >> amount;

	try {
		account.deposit(amount);
		cout << "Balance is: " << account.get_balance();
	}
	catch (Invalid e)
	{
		cout << e.get_error() << "\n";
	}
	

	return 0;
}