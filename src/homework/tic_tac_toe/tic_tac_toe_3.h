//h
#include "tic_tac_toe.h"

class TicTacToe3 : public TicTacToe {
public:
	//TicTacToe3() = default;
	explicit TicTacToe3():TicTacToe(3) {}
	//explicit BankAccount(int b) : balance{ b } {} // this is a constructor EX: BankAccount(int b, double r) : balance{b}, rate {r} {}
private:
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();

};

