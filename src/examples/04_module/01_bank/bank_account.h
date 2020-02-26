//bank_account.h
class BankAccount
{
public:
	BankAccount(int b) : balance{ b } {} // this is a constructor
	int get_balance()const { return balance; } //const keeps the entire function from being amended
	void deposit(int amount);
	void withdraw(int amount);
private:
	int balance;
};