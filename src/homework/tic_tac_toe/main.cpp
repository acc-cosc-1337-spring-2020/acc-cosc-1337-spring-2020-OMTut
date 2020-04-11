#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

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

			//int marker;
		do
		{
			cin >> game;
			cout << game;
		} while (game.game_over() != true);
		cout << game.get_winner();
		TicTacToeManager savegame;
		//savegame.get_winner_total();
		//savegame.get_winner_total(game.get_winner());
		cout << "\n";
		savegame.save_game(game);

		cout << "\nPress 1 to play again."; //menu choice
		cin >> choice;
		if (choice == 1) { system("cls"); }
	} while (choice == 1);
	

	//use a try catch block to check for an Error return when user enters incorrect data.


	return 0;
}