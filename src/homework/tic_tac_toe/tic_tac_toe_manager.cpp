#include "tic_tac_toe_manager.h"

//cpp
void TicTacToeManager::save_game(TicTacToe b)
{
	games.push_back(b);
	update_winner_count(b.get_winner());
}

void TicTacToeManager::update_winner_count(string winner)
{
	if (winner == "X") { x_win++; }
	if (winner == "O") { o_win++; }
	if (winner == "C") { ties++; }
}

void TicTacToeManager::get_winner_total(int & o, int & x, int & t)
{
	cout << "X Wins: " << x_win << "\n";
	cout << "O Wins: " << o_win << "\n";
	cout << "Ties: " << ties << "\n";

}

std::ostream & operator<<(std::ostream & out, const TicTacToeManager & manager)
{
	for (auto game : manager.games) 
	{
		out<<game;
	}

	out << "X Win Count: " << manager.x_win << "\n";
	out << "O Win Count: " << manager.o_win << "\n";
	out << "Tie Count: " << manager.ties << "\n";
	return out;
}


