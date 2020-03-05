//cpp
#include "tic_tac_toe.h"
#include <iostream>

using std::string;
using std::cin; using std::cout;

//Start Game Function
void TicTacToe::start_game(string first_player)
{
	if (first_player == "X") { player = "X"; }
	else if (first_player == "O") { player = "O"; }
	else { throw Error("Player must be X or O"); }

}

//Mark the Board function
void TicTacToe::mark_board(int position)
{
	if (position < 1 || position > 9) {
		throw Error("Position must be 1 to 9");
	}
}

