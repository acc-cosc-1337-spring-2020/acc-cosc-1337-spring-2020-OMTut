#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"


int main()
{
	TicTacToeData data;
	//TicTacToeManager(data);//Figure out what is redefining this.
	//TicTacToeManager manager = TicTacToeManager(data);
	
	unique_ptr<TicTacToeManager> manager =  std::make_unique<TicTacToeManager>();
	//manager = std::move(TicTacToeData(data));
	
	string cont;

	do
	{
		unique_ptr<TicTacToe> game;
		int game_type;
		cout << "\nTictactoe 3 or 4?";
		cin >> game_type;

		if (game_type == 3)
		{
			game = make_unique<TicTacToe3>();
		}
		else if (game_type == 4)
		{
			game = make_unique <TicTacToe4>();
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

		cout << "\nThe Winner is: " << game->get_winner() << "\n";

		manager->save_game(game);

		cout << "Enter Y to play again: ";
		cin >> cont;

	} while (cont == "Y");

	cout << *manager << "\n";

	//TicTacToeData data;
	//TicTacToeManager(data);

	return 0;
}