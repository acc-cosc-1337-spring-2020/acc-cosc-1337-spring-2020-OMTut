#include "vector.h"
#include<iostream>

int main() 
{
	//lvalue-can reference or has an address that is accessible
	int num;
	int& num_ref = num;//right here accessible. Anything that has an address that we can access is an lvalue.

	//anything that does not have an address is an rvalue.
	int num = 5; //5 is an rvalue. We can not reference the number 5 directly.
	int&& num_5 = 5
	int a = 1, b = 5, c;
	c = a * b; //a*b is n r value

	//use_vector();
	Vector v1 = get_vector();
	return 0;
}

