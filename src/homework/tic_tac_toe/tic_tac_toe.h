//h
#include <string>
#include <vector>
#include <memory>
#include <iostream>
using std::string; using std::vector;
using std::ostream; using std::istream;
using std::cin; using std::cout;
using std::unique_ptr; using std::make_unique;


//Error class
#ifndef ERROR_H
#define ERROR_H
class Error {
public:
	Error(string msg) : message{ msg } {} //constructor
	string get_message()const { return message; } //const keeps the function from being amended
private:
	string message;
};
#endif

//TicTacToe Class
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
	TicTacToe(int s):pegs(s*s, " ") {}
	void start_game(string first_player);
	void mark_board(int position);
	string get_player()const { return player; }
	bool game_over();
	string get_winner();
	friend istream& operator>>(istream& in, TicTacToe& game);
	friend ostream& operator<<(ostream& out, const TicTacToe& game);

protected:
	vector<string>pegs;
	virtual bool check_column_win() = 0;
	virtual bool check_row_win() = 0;
	virtual bool check_diagonal_win() = 0;

private:
	void set_next_player();
	void set_winner();
	bool check_board_full();
	string player;
	void clear_board();
	string winner{ "P" };
};

#endif;
