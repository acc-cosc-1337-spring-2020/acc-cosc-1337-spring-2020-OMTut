#include "tic_tac_toe.h"
#include <iostream>

using std::cin; using std::cout;

int main() 
{
	int choice{ 1 };
	do
	{
	//prompt user for first player
		string player;
		cout << "Ready Player One.\n";
		do
		{
			cout << "Choose X or O: ";
			cin >> player;
		} while ((player != "X") && (player != "O"));
	
	//start game
		
			TicTacToe game;
			game.start_game(player);

	//In a user-controlled loop, prompt the user for a position (int type) and call the mark_board class member function. Loop continues while user opts in.
	
		int marker;
		do
		{
			string currentplayer = game.get_player();
			cout << "Player " << currentplayer << " Pick a square: ";
			cin >> marker;
			game.mark_board(marker);
			game.display_board();
		} while (game.game_over() != true);
		cout << game.get_winner();
		cout << "\nPress 1 to play again.";
		cin >> choice;
		if (choice == 1) { system("cls"); }
	} while (choice == 1);
	

	//use a try catch block to check for an Error return when user enters incorrect data.


	return 0;
}