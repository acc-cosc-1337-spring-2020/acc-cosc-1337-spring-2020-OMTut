//bank_account.h
#include <string>
#include <iostream>

class BankAccount
{
public:
	BankAccount() = default;
	explicit BankAccount(int b) : balance{ b } {} // this is a constructor EX: BankAccount(int b, double r) : balance{b}, rate {r} {}
	virtual int get_balance()const = 0; //pure virtual function. this makes this class an abstract class (virtual function = 0)
	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);
	double get_rate() const { return rate; }
	friend void display_balance(const BankAccount& b);
	friend std::ostream& operator<<(std::ostream& out, const BankAccount& b);
	friend std::istream& operator>>(std::istream& in, BankAccount& b);

protected:
	int balance{ 0 };

private:
	const int min_balance_to_open{ 25 };
	static double rate;
	static double init_rate() { return .025; }
};

class Invalid {
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }
private:
	std::string message;
};