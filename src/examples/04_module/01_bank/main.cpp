#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "customer.h"
#include "atm.h"
#include <iostream>
#include <vector>
#include <memory>

using std::cout; using std::cin;
using std::unique_ptr; using std::make_unique;
using std::reference_wrapper;

int main()

{
	//c++ 11
	//declare unique pointer       create the instance with make_unique
	unique_ptr<BankAccount> s = make_unique<SavingsAccount>(90 );
	unique_ptr<BankAccount> c = make_unique<CheckingAccount>(100);

	std::vector<unique_ptr<BankAccount>> accounts;
	accounts.push_back(std::move(s));
	accounts.push_back(std::move(c));
	Customer cust;
	cust.add_account(s);
	cust.add_account(c);

	ATM atm(cust);
	cout << atm;

	//BankAccount a;
	//cout << a.get_balance();

	/*std::vector<BankAccount> accounts{ BankAccount(100), BankAccount(200) };
	*/
	for (auto &account : acts)
	{
		cout << account->get_balance() << "\n";
	}
	
	
	/*
	
	TicTacToe game <----make sure this is inside the "do you want to play" loop so it saves a different object

	loop for mark board

	game ends
	call manager save game

	*/

	/*

	BankAccount account(500); //creates an instance of BankAccount
	Customer cust;
	cust.add_account(account);


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
	
	*/
	return 0;
}