#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"


int main()
{
	unique_ptr<TicTacToeManager> manager = std::make_unique<TicTacToeManager>();
	string cont;

	vector<unique_ptr<TicTacToeManager>>games;

	do
	{
		unique_ptr<TicTacToe> game;
		int game_type;
		cout << "\nTictactoe 3 or 4?";
		cin >> game_type;

		if (game_type == 3)
		{
			game = make_unique<TicTacToe3>();
			move(game);
		}
		else if (game_type == 4)
		{
			game = make_unique <TicTacToe4>();
			move(game);
		}

		string player = "Y";

		while (!(player == "O" || player == "X"))
		{
			try
			{
				cout << "Enter player: ";
				cin >> player;

				game->start_game(player);
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
		}

		int choice = 1;

		do
		{
			try
			{
				cin >> *game;
				cout << *game;
			}
			catch (Error e)
			{
				cout << e.get_message();
			}

		} while (!game->game_over());

		manager->save_game(game);

		cout << "\The Winner is: " << game->get_winner() << "\n";

		cout << "Enter Y to play again: ";
		cin >> cont;

	} while (cont == "Y");

	cout << *manager << "\n";

	return 0;
}