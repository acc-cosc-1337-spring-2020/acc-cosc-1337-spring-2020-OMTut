#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Can't call mark_board before start_game")
{
	TicTacToe game;
	REQUIRE_THROWS_AS(game.mark_board(10), Error);

}

TEST_CASE("Test start game accepts only X or O")
{
	TicTacToe game;
	REQUIRE_THROWS_AS(game.start_game("p"), Error);

}

TEST_CASE("Test setting the first player)") {
	
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");

	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}


/*
TEST_CASE(" Test BankAccount initial open depost < 25")
{
	BankAccount account;
	REQUIRE(account.get_balance() == 0);

	REQUIRE_THROWS_AS(account.open(24), Invalid);
}
*/