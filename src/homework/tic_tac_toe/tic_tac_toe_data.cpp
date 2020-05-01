#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

//cpp

void TicTacToeData::save_pegs(const vector<unique_ptr<TicTacToe>>& games)
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
	vector<unique_ptr<TicTacToe>> boards;  //g
	ifstream read_file(file_name);

	if (read_file.is_open())
	{
		vector<string> pegs;
		string line;

		while (getline(read_file, line))
		{

			for (int ch{ 0 }; ch < line.size() - 1; ch++)
			{
				string chstr(1, line[ch]);
				pegs.push_back(chstr);
			}

			string winner = pegs[-1];
			unique_ptr<TicTacToe>board;

			if (pegs.size() == 9)
			{
				board = make_unique<TicTacToe3>(pegs, winner);
			}
			else if (pegs.size() == 16)
			{
				board = make_unique<TicTacToe4>(pegs, winner);
			}

			boards.push_back(move(board));
		}
		read_file.close();
	}



	return boards;
}
