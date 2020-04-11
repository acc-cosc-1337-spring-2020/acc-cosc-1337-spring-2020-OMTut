//h
#include "tic_tac_toe.h"
#include <string>
#include <iostream>

using std::string;
using std::cin; using std::cout;

#ifndef TICTACTOE_MANAGER
#define TICTACTOE_MANAGER

class TicTacToeManager {
public:
	void save_game(const TicTacToe b);

	void get_winner_total(int& o, int& x, int& t);
private:

	vector<unique_ptr<TicTacToe>> games;
	int x_win{ 0 };
	int o_win{ 0 };
	int ties{ 0 };
	void update_winner_count(string winner);

};

#endif //TICTACTOE_MANAGER