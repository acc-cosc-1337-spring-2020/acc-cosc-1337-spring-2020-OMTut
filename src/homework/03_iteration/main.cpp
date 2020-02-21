//write include statements
#include <iostream>
#include <string>
#include "dna.h"
//write using statements
using std::string;
using std::cout;
using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int MenuChoice;
	//do
	//{
	//cout << "Please choose from the following:\n";
	//cout << "Press 1 to get GC Content\n";
	//cout << "Press 2 to get DNC Complement\n";
	//cout << "Enter your selection: ";
	//cin >> MenuChoice;

	do
	{
		cout << "Please choose from the following:\n";
		cout << "Press 1 to get GC Content\n";
		cout << "Press 2 to get DNC Complement\n";
		cout << "Press 3 to Exist\n";
		cout << "Enter your selection: ";
		cin >> MenuChoice;

		if (MenuChoice == 1)
		{
			string dnacontent;
			cout << "\n\nEnter DNA String: ";
			cin >> dnacontent;
			get_gc_content(dnacontent);
		}
		//Menu Choice for Get DNA Complement
		else if (MenuChoice == 2)
		{
			string dnacomplement;
			cout << "\n\nEnter DNA String: ";
			cin >> dnacomplement;
			get_dna_complement(dnacomplement);
		}

	} while (MenuChoice == 1 || MenuChoice==2);


	return 0;
}