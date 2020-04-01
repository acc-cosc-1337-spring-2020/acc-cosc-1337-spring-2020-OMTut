//cpp
#include "tic_tac_toe.h"
#include <iostream>

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
	set_next_player();
}

//Display Board function
void TicTacToe::display_board() const
{
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		cout << pegs[i];
		if (i == 3 || i == 6 || i == 9)
		{
			cout << "\n";
		}
		//cout << provided[v] << " ";
	}
}

bool TicTacToe::check_board_full()
{
	bool isfull = false;
	int counter{ 0 };
	while (counter != 8 && isfull == false)
	{
		for (int i{ 0 }; i < pegs.size(); ++i)
		{
			if (pegs[i] == "")
			{
				isfull = false;
			}
			else
			{
				isfull = true;
			}
		}
		counter = counter + 1;
	}
	return isfull;
}

void TicTacToe::clear_board() const
{
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		pegs[i] = " ";
	}
}

//Check for Game Over function
bool TicTacToe::game_over()
{
	return false;
}

