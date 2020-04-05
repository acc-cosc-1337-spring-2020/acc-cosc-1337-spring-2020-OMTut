//cpp
#include "tic_tac_toe.h"
#include <iostream>
#include <vector>

using std::string; using std::vector;
using std::cin; using std::cout;

//Start Game Function
void TicTacToe::start_game(string first_player)
{
	if (first_player == "X") { player = "X"; }
	else if (first_player == "O") { player = "O"; }
	else { throw Error("Player must be X or O"); }
	clear_board();
}

void TicTacToe::clear_board()
{
	string clear = " ";
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		pegs[i] = " ";
	}
}

//set next player function
void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		player = "O";
	}
	else
	{
		player = "X";
	}
}

//Mark the Board function
void TicTacToe::mark_board(int position)
{
	if (player == "")
	{
		throw Error("Must start game first.");
	}
	else if (position < 1 || position > 9) {
		throw Error("Position must be 1 to 9");
	}
	int mark_position = position - 1;
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		if (i == mark_position)
		{
			pegs[i] = player;
		}
	}
	set_next_player();

}

//Display Board function
void TicTacToe::display_board() const
{

	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		cout << "|" << pegs[i];
		if (i == 2 || i == 5 || i == 8)
		{
			cout << "|\n";
		}
	}
}

/************** Check Winners ************************/
bool TicTacToe::check_column_win()
{
	if ((pegs.at(0) == "X") && (pegs.at(3) == "X") && (pegs.at(6)=="X")) { return true; }
	else if ((pegs.at(1) == "X") && (pegs.at(4) == "X") && (pegs.at(7) == "X")) { return true; }
	else if ((pegs.at(2) == "X") && (pegs.at(5) == "X") && (pegs.at(8) == "X")) { return true; }
	else if ((pegs.at(0) == "O") && (pegs.at(3) == "O") && (pegs.at(6) == "O")) { return true; }
	else if ((pegs.at(1) == "O") && (pegs.at(4) == "O") && (pegs.at(7) == "O")) { return true; }
	else if ((pegs.at(2) == "O") && (pegs.at(5) == "O") && (pegs.at(8) == "O")) { return true; }
	else { return false; }
}

bool TicTacToe::check_row_win()
{
	if ((pegs.at(0) == "X") && (pegs.at(1) == "X") && (pegs.at(2) == "X")) { return true; }
	else if ((pegs.at(3) == "X") && (pegs.at(4) == "X") && (pegs.at(5) == "X")) { return true; }
	else if ((pegs.at(6) == "X") && (pegs.at(7) == "X") && (pegs.at(8) == "X")) { return true; }
	else if ((pegs.at(0) == "O") && (pegs.at(1) == "O") && (pegs.at(2) == "O")) { return true; }
	else if ((pegs.at(3) == "O") && (pegs.at(4) == "O") && (pegs.at(5) == "O")) { return true; }
	else if ((pegs.at(6) == "O") && (pegs.at(7) == "O") && (pegs.at(8) == "O")) { return true; }
	else { return false; }
}

bool TicTacToe::check_diagonal_win()
{
	if ((pegs.at(0) == "X") && (pegs.at(4) == "X") && (pegs.at(8) == "X")) { return true; }
	else if ((pegs.at(2) == "X") && (pegs.at(4) == "X") && (pegs.at(6) == "X")) { return true; }
	else if ((pegs.at(0) == "O") && (pegs.at(4) == "O") && (pegs.at(5) == "O")) { return true; }
	else if ((pegs.at(2) == "O") && (pegs.at(4) == "O") && (pegs.at(6) == "O")) { return true; }
	else { return false; }
}

bool TicTacToe::check_board_full()
{
	bool isfull = false;
	int counter{ 0 };
	int Tcounter{ 0 };
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		counter = counter + 1;
		if (pegs[i] == " ") {
			Tcounter = Tcounter + 1;
		}
		
		if ((counter == 9) && (Tcounter == 0)){ isfull = true; }
	}

	return isfull;
}

//Check for Game Over function
bool TicTacToe::game_over() 
{
	
	bool fullboard = check_board_full();
	bool column_win = check_column_win();
	bool row_win = check_row_win();
	bool diagonal_win = check_diagonal_win();

	//if (fullboard == true) { 
	//	return true; 
	//}
	if (column_win == true) { 
		set_winner();
		return true; 
	}
	else if (row_win == true) { 
		set_winner();
		return true; 
	}
	else if (diagonal_win == true) { 
		set_winner();
		return true; 
	}
	else if ((fullboard == true) && (column_win == false) && (row_win==false) && (diagonal_win == false)) {
		winner = "C";
		return true;
	}
	else { return false; }

}

void TicTacToe::set_winner()
{
	if (player == "X")
	{
		winner = "O";
	}
	else
	{
		winner = "X";
	}
}

string TicTacToe::get_winner()
{
	game_over();
	cout << "The winner is: " << winner;
	return string();
}


