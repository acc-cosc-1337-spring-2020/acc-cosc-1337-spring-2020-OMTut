//cpp
#include "tic_tac_toe.h";
#include <iostream>

using std::string;
using std::cin, using std::cout;

//class Error
class Error
{
public:
	//string msg;
	Error(string msg) //constructor
	{
		msg = "Player must be X or O.";
	}

	string get_message()
	{
		return string();
	}


private:
	string message;
	message = "Player must be X or O.";
};

//class TicTacToe
class TicTacToe
{
public:

private:
	void set_next_player()
	{
	}
};

/*************************************
string Error(string msg)
{
	string playerside;
	if (playerside != "X" || playerside != "x" || playerside != "O" || playerside != "o" || ) {
		cout << "Player must be X or O.";
	}
	return string();
}
*************************************/
