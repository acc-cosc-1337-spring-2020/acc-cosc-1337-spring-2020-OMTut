//cpp
#include "tic_tac_toe.h"


//Start Game Function
void TicTacToe::start_game(string first_player)
{
	if (first_player == "X") { player = "X"; }
	else if (first_player == "O") { player = "O"; }
	else { throw Error("Player must be X or O"); }
	clear_board();
}

void TicTacToe::clear_board()
{
	string clear = " ";
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		pegs[i] = " ";
	}
}

//set next player function
void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		player = "O";
	}
	else
	{
		player = "X";
	}
}

//Mark the Board function
void TicTacToe::mark_board(int position)
{
	if (player == "")
	{
		throw Error("Must start game first.");
	}
	else if (position <1 || position > pegs.size()) {
		throw Error("Position must be 1 to 9");
	}
	int mark_position = position - 1;
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		if (i == mark_position)
		{
			pegs[i] = player;
		}
	}
	set_next_player();

}

/************** Check Winners ************************/
bool TicTacToe::check_column_win(){ return false; }
bool TicTacToe::check_row_win() { return false; }
bool TicTacToe::check_diagonal_win() { return false; }

bool TicTacToe::check_board_full()
{
	bool isfull = false;
	int counter{ 0 };
	int Tcounter{ 0 };
	for (int i{ 0 }; i < pegs.size(); ++i)
	{
		counter = counter + 1;
		if (pegs[i] == " ") {
			Tcounter = Tcounter + 1;
		}
		
		if ((counter == pegs.size()) && (Tcounter == 0)){ isfull = true; }
	}

	return isfull;
}

//Check for Game Over function
bool TicTacToe::game_over() 
{
	
	bool fullboard = check_board_full();
	bool column_win = check_column_win();
	bool row_win = check_row_win();
	bool diagonal_win = check_diagonal_win();

	if (column_win == true) { 
		set_winner();
		return true; 
	}
	else if (row_win == true) { 
		set_winner();
		return true; 
	}
	else if (diagonal_win == true) { 
		set_winner();
		return true; 
	}
	else if ((fullboard == true) && (column_win == false) && (row_win==false) && (diagonal_win == false)) {
		winner = "C";
		return true;
	}
	else { return false; }

}

void TicTacToe::set_winner()
{
	if (player == "X")
	{
		winner = "O";
	}
	else
	{
		winner = "X";
	}
}

string TicTacToe::get_winner()
{
	game_over();
	return winner;
}



istream & operator>>(istream & in, TicTacToe& game)
{
	int marker;
	string currentplayer = game.get_player();
	cout << "Player " << currentplayer << " Pick a square: ";
	in >> marker;
	game.mark_board(marker);

	return in;
}

ostream & operator<<(ostream & out, const TicTacToe & game)
{
	if (game.pegs.size() == 9) {
		for (int i{ 0 }; i < game.pegs.size(); ++i)
		{
			cout << "|" << game.pegs[i];
			if (i == 2 || i == 5 || i == 8)
			{
				cout << "|\n";
			}
		}
	}
	else {
		for (int i{ 0 }; i < game.pegs.size(); ++i)
		{
			cout << "|" << game.pegs[i];
			if (i == 3 || i == 7 || i == 11 || i == 15)
			{
				cout << "|\n";
			}
		}
	}
	return out;
}