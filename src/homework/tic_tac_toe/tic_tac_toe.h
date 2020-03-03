//h
#include <string>
using std::string;

//Error function
string Error(string msg);

string get_message();

//TicTacToe Public Functions
void start_game(string first_player);
void mark_board(int position);
string get_player()const;

//TicTacToe Private Functions
void set_next_player();
