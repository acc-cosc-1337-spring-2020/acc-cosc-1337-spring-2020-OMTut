#include "vectors.h"
#include<algorithm>
#include<iostream>
#include <conio.h>

using std::vector;
using std::string;
using std::cout; using std::cin;

/*
Write a value return function get_max_from_vector with a const reference 
vector of intsparameter that returns the max value in a vector

@param numbers is a const reference to a vector of integers
@return the max value in the vector
*/
int get_max_from_vector(const vector<int> &numbers)
{

	int maxnumber = *max_element(numbers.begin(), numbers.end());

	return maxnumber;
}


/*
Write a function named is_prime with an integer parameter that
given a number returns true if prime or false if not prime

@param number: Any whole number
@return: bool if prime False if not
*/
bool is_prime(int number)
{
	if (number <= 1) {
		return false;
	}
	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			return false;
		}
		
	}
	return true;
}

/*
Write a a function named vector_of_primes with an integer parameter
that given a number returns all the prime numbers up to the number

Example given number 10 returns a vector with elements 2,3,5,7,

@param int integer value
@return vector of ints containing prime values up to a value

Make sure to use the is_prime function to determine if current 
number is prime.
*/

vector<int> vector_of_primes(int prime)
{
	vector<int> primes;
	for (int p =1; p<= prime; p++)
	{
		is_prime(p);
		if (is_prime(p) == true) {
			primes.push_back(p);
		}
	}

	return primes;
}

//menu function
void menu() {
	int MenuChoice;
	do
	{
		cout << "Welcome.\nPress 1 for 'Get Max Vector'.\nPress 2 for 'Get Primes'.\nPress 3 to exit. ";
		cin >> MenuChoice;
		if (MenuChoice == 1) //get max
		{
			vector<int> provided;
			string another;
			cout << "\nEnter a series of numbers to find the max value. Let's get started!\n";
			do
			{
				int num;
				cout << "Enter a number: ";
				cin >> num;
				provided.push_back(num);

				//int result = get_max_from_vector(provided);
				cout << "You have entered the following numbers: ";
				for (int v = 0; v < provided.size(); ++v)
				{
					cout << provided[v] << " ";
				}
				cout << "\n";
				int max = get_max_from_vector(provided);
				cout << "The max value is " << max << "\n\n";
				cin.ignore();

				cout << "Press 1 to enter another number or Press 2 to exit...\n\n";
				char k = getch();
				if (k == '2') {
					another = "e";
				}


			} while (another != "e");

			//use a vector of int with values 8, 4, 20, 88, 66, 99
			//vector<int> provided{ 8, 4, 20, 88, 66, 99 };
			//int result = get_max_from_vector(provided);
			//cout << "\n\nThe max value is " << result << "\n\n";
		}
		
		else if (MenuChoice == 2) //vector of primes
		{
			int number;
			cout << "\nEnter a number: ";
			cin >> number;
			cout << "\n";
			vector<int> result = vector_of_primes(number);
			if (result.empty()) {
				cout << "There are no prime numbers contained within " << number << ".\n\n";

			}
			else
			{
				cout << "The prime numbers contained within " << number << " are: ";

				for (int i = 0; i < result.size(); ++i)
				{
					std::cout << result[i] << " ";
				}
				cout << "\n\n";
			}
		}
		else if (MenuChoice == 3) {
			cout << "\n\nThank you. Have a nice day.";
		}
		else {
			cout << "\n\nInvalid Option\n\n";
		}

	} while (MenuChoice != 3);

}
