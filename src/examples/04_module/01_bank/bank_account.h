//bank_account.h
#include <string>

class BankAccount
{
public:
	BankAccount() = default;
	explicit BankAccount(int b) : balance{ b } {} // this is a constructor EX: BankAccount(int b, double r) : balance{b}, rate {r} {}
	int get_balance()const { return balance; } //const keeps the entire function from being amended
	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);
private:
	int balance{ 0 };
	const int min_balance_to_open{ 25 };
};

class Invalid {
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }
private:
	std::string message;
};