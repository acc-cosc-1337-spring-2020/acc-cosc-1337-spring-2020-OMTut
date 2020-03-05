//h
#include <string>
using std::string;

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


private:
	string player;
};
