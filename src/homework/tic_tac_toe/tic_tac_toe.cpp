//cpp
#include "tic_tac_toe.h";
#include <iostream>

using std::string;
using std::cin, using std::cout;

//error function
string Error(string msg)
{
	string playerside;
	if (playerside != "X" || playerside != "x" || playerside != "O" || playerside != "o" || ) {
		cout << "Player must be X or O.";
	}
	return string();
}
