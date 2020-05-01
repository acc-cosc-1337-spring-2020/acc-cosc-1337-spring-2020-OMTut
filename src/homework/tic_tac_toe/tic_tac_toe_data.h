#include "tic_tac_toe.h"

#ifndef TICTACTOE_DATA
#define TICTACTOE_DATA

class TicTacToeData
{
public:
	void save_pegs(const vector<unique_ptr<TicTacToe>>& games);
	vector<unique_ptr<TicTacToe>> get_games();
private:
	const string file_name{ "tttgames.dat" };

};

#endif // !TICTACTOE_DATA