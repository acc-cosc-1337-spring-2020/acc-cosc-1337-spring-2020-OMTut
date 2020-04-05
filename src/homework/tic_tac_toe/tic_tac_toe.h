//h
#include <string>
#include <vector>
using std::string; using std::vector;

//Error class

class Error {
public:
	Error(string msg) : message{ msg } {} //constructor
	string get_message()const { return message; } //const keeps the function from being amended
private:
	string message;
};

//TicTacToe Class
class TicTacToe {
public:
	void start_game(string first_player);
	void mark_board(int position);
	string get_player()const { return player; }
	void display_board()const;
	bool game_over();
	string get_winner();


private:
	void set_next_player();
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
	void set_winner();
	bool check_board_full();
	string player;
	void clear_board();
	vector<string> pegs{ " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string winner{ "P" };
};
