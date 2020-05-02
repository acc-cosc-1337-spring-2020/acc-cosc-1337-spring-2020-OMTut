#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

//cpp

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
	ofstream file_out(file_name, ios_base::trunc);

	for (auto& game : games) 
	{
		for (auto peg : game->get_pegs())
		{
			file_out << peg;
		}
		file_out << game->get_winner();
		file_out << "\n";

	}

	file_out.close();

}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
	vector<unique_ptr<TicTacToe>> games;
	ifstream read_file(file_name);

	//vector<string> pegs;
	//string line;

	if (read_file.is_open())
	{
		vector<string> pegs;
		string line;

		while (getline(read_file, line))
		{

			for (int i{ 0 }; i < line.size() - 1; i++)
			{
				string chstr(1, line[i]);
				pegs.push_back(chstr);
			}

			string winner = pegs[-1];
			unique_ptr<TicTacToe>game;

			if (pegs.size() == 9)
			{
				game = make_unique<TicTacToe3>(pegs, winner);
			}
			else if (pegs.size() == 16)
			{
				game = make_unique<TicTacToe4>(pegs, winner);
			}

			games.push_back(move(game));
		}
		read_file.close();
	}



	return games;
}
