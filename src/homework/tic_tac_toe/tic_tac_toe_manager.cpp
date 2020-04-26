#include "tic_tac_toe_manager.h"


void TicTacToeManager::save_game(unique_ptr<TicTacToe> & game)
{
	update_winner_count(game->get_winner());
	games.push_back(std::move(game));
}

void TicTacToeManager::update_winner_count(string winner)
{

	if (winner == "X") { x_win++; }
	if (winner == "O") { o_win++; }
	if (winner == "C") { ties++; }
}

void TicTacToeManager::get_winner_total(int & o, int & x, int & c)
{
	x = x_win;
	o = o_win;
	c = ties;

}


ostream & operator<<(ostream & out, const TicTacToeManager & manager)
{

	for (auto &game : manager.games)
	{
		out << &game;
	}

	out << "\nX Win Count: " << manager.x_win << "\n";
	out << "O Win Count: " << manager.o_win << "\n";
	out << "Tie Count: " << manager.ties << "\n";

	return out;
}




