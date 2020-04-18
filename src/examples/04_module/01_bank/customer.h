//customer.h
#include <vector>
#include <iostream>
#include<memory>
#include "bank_account.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer //tic tac toe manager class
{
public:

	void add_account(std::unique_ptr<BankAccount>& act);
	//friend std::ostream& operator<<(std::ostream& out, const Customer& c);
private:
	std::vector<std::unique_ptr<BankAccount>> accounts; //rewatch Tuesday's lesson. He explains.

};

#endif // !CUSTOMER_H