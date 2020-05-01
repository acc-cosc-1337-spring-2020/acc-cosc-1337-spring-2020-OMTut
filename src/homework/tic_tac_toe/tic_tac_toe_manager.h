//h
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"

using std::string; using std::vector;
using std::cin; using std::cout;
using std::unique_ptr; using std::make_unique;

#ifndef TICTACTOE_MANAGER
#define TICTACTOE_MANAGER

class TicTacToeManager {
public:
	TicTacToeManager() = default;
	TicTacToeManager(TicTacToeData& data);
	void save_game(unique_ptr<TicTacToe> &game);
	void get_winner_total(int& o, int& x, int& t);
	friend std::ostream& operator<<(std::ostream & out, const TicTacToeManager &manager);
	~TicTacToeManager();
private:
	TicTacToeData data;
	vector<unique_ptr<TicTacToe>>games;
	//vector<unique_ptr<TicTacToeData>>data{};
	
	

	int x_win{ 0 };
	int o_win{ 0 };
	int ties{ 0 };
	void update_winner_count(string winner);

};

#endif // !TICTACTOE_MANAGER