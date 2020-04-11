#include "tic_tac_toe_manager.h"

//cpp
void TicTacToeManager::save_game(TicTacToe b)
{
	//cout << "\n" << b << "\n" << b.get_winner();
	games.push_back(make_unique<TicTacToe>(b));
	//update_winner_count(b.get_winner());
	//games.push_back(b, b.get_winner());
	//get_winner_total(int& o, o, t);
	for (const auto& TicTacToe : games)
	{
		//cout << games;
	}
	cout << "\nThis is the Totals from Manager:\n";
	cout << "X Wins: " << x_win;
	cout << "\nO Wins: " << o_win;
	cout << "\nTies: " << ties;
}

void TicTacToeManager::update_winner_count(string winner)
{
	if (winner == "X") { x_win++; }
	if (winner == "O") { o_win++; }
	if (winner == "C") { ties++; }
}

void TicTacToeManager::get_winner_total(int & o, int & x, int & t)
{
	for (const auto& TicTacToe : games)
	{

	}
	cout << "X Wins: " << x_win << "\n";
	cout << "O Wins: " << o_win << "\n";
	cout << "Ties: " << ties << "\n";

}

