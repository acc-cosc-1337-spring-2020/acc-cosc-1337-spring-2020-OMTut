#include "bank_account.h"
#include <iostream>

using std::cout; using std::cin;

int main()
{

	BankAccount account(500);

	auto balance = account.get_balance();
	cout << "Balance is: " << account.get_balance() << "\n";

	auto amount{ 0 };
	cout << "Enter deposit amount: ";
	cin >> amount;

	account.deposit(amount);
	cout << "Balance is: " << account.get_balance();

	return 0;
}