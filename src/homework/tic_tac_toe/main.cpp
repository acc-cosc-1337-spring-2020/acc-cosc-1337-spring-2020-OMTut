#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

int main() 
{
	
	TicTacToeManager* manager = new TicTacToeManager();

	int choice{ 1 };
	int gametype{ 0 };
	do
	{
		cout << "Do you want to play Tic Tac Toe 3 or Tic Tac Toe 4?\n";
		cout << "Type 3 or 4: ";
		cin >> gametype;
		
		unique_ptr<TicTacToe> game;

		if (gametype == 3)
		{ 
			game = make_unique<TicTacToe3>(); 
		}
		else {
			game = make_unique<TicTacToe4>();
		}

		//prompt user for first player
		string player;
		cout << "Ready Player One.\n";

		do
		{
			cout << "Choose X or O: ";
			cin >> player;
		} while ((player != "X") && (player != "O"));


		//start game
	
		game->start_game(player);

		do
		{
			cin >> *game;
			cout << *game;
		} while (game->game_over() != true);

		manager->save_game(game);

		cout << "\n";


		cout << "\nPress 1 to play again."; //menu choice
		cin >> choice;
		if (choice == 1) { system("cls"); } //system("cls"); clears the screen

	} while (choice == 1);
	cout << *manager;


	return 0;
}