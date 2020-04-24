#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
	int r = 0, p = 0;
	int& ref_r = r; // this reference does not get its own address spot and modifies int r
	

	cout << "Address of r: " << &r << "\n";
	cout << "Value of r: " << r << "\n";
	cout << "Address of ref_r: " << &ref_r << "\n\n";

	int* ptr_p = &p;
	cout << "Address of p: " << &p << "\n"; //the & means to cout the address of p
	cout << "Value of p: " << p << "\n";
	cout << "Address of ptr_p: " << &ptr_p << "\n\n";

	cout << "Contents(address) of ptr_p: " << ptr_p << "\n";
	cout << "Value ptr_p points to: " << *ptr_p << "\n\n";

	//THis changes the pointer
	*ptr_p = 15;
	cout << "Value ptr_p points to: " << *ptr_p << "\n";
	cout << "Value of p: " << p << "\n\n";

	//creating Dynamic Memory....Pass By Pointer


	return 0;
}