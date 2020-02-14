#include "loops.h"
#include<iostream>
#include<vector>

using std::vector;
using std::cout; using std::cin;

//In file src/classwork loops.cpp, write the function code that returns the factorial of num.
int factorial(int num)
{
	int sum = 1;
	int counter = 1;

	while (counter <= num)
	{
		sum = sum * counter;
		//sum = sum + counter * counter;
		counter = counter + 1;
	}
	return sum;
}

void prompt_user()
{
	int choice;

	do
	{
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << "Factorial is: "<< factorial(num) << "\n\n";

		cout << "Continue? Enter 1 to continue: ";
		cin >> choice;

	} while (choice == 1);

}





