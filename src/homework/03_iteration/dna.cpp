#include "dna.h"
#include <iostream>
#include<string>
using std::string;


/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const std::string &dnacontent)
{
	double totalstrcount = dnacontent.size();
	double cgcounter = 0;
	for (int i = 0; i < dnacontent.length(); ++i)
	{

		if (dnacontent[i] == 'G' || dnacontent[i] == 'C') {
			cgcounter = cgcounter + 1;
		}

	}
	double gc_percent = cgcounter / totalstrcount;

	std::cout << dnacontent << "\n" << gc_percent << "\n\n";
	std::cout << "The GC-content of " << dnacontent << " is " << gc_percent << "%.\n\n";

	return gc_percent;
}


/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string reverse_string(std::string dnareverse)
{
	int len = dnareverse.size() - 1;
	string dnatemp = dnareverse;
	for (int i =len; i >= 0; i--)
	{
		dnatemp[len-i] = dnareverse[i];
	}
	return dnatemp;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
string get_dna_complement(string dnacomplement)
{
	string dnareverse = reverse_string(dnacomplement);

	for (int i = 0; i < dnareverse.length(); ++i)
	{
		if (dnareverse[i] == 'A') {
			dnareverse[i] = 'T';

		}
		else if (dnareverse[i] == 'T')
		{
			dnareverse[i] = 'A';
		}
		else if (dnareverse[i] == 'C')
		{
			dnareverse[i] = 'G';

			
		}
		else if (dnareverse[i] == 'G')
		{
			dnareverse[i] = 'C';
			
		}
		
	}

	std::cout << dnacomplement << "\n" << dnareverse << "\n\n";
	std::cout << "The DNA Complement of " << dnacomplement << " is " << dnareverse << "\n\n";

	return dnareverse;
}
