#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over") {
	TicTacToe3 game;
	REQUIRE(game.game_over() == false);
}

TEST_CASE("Test set first player X)") {
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test set first player O)") {
	TicTacToe3 game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test Mark Position accepts values from 1 to 9 only") {
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE_THROWS_AS(game.mark_board(0), Error);
	REQUIRE_THROWS_AS(game.mark_board(10), Error);
	REQUIRE_NOTHROW(game.mark_board(5));
}

TEST_CASE("Test game over if 9 slots are selected") {
	TicTacToe3 game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(3);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(6);
	game.mark_board(7);
	game.mark_board(8);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}

/////////// Test Column Wins ////////////////////////
TEST_CASE("Test win by first column") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(1);
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second column") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(2);
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third column") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(3);
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

///////////// Test Row Wins //////////////////////
TEST_CASE("Test win by first row") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(1);
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second row") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(4);
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third row") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(7);
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

///////////// Test Diagonal Wins //////////////////////
TEST_CASE("Test win from top left") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(1);
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}
TEST_CASE("Test win from bottom left") {
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(7);
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test for no winner") {
	TicTacToe3 game;
	game.start_game("X");
	game.mark_board(1);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(9);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(4);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(6);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(8);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//X
	//no one wins
	REQUIRE(game.game_over() == true);
}

/**************************************************************
Tic Tac Toe 4 Tests
******************/
TEST_CASE("Test game over") {
	TicTacToe4 game;
	REQUIRE(game.game_over() == false);
}

TEST_CASE("Test set first player X)") {
	TicTacToe4 game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test set first player O)") {
	TicTacToe4 game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test Mark Position accepts values from 1 to 16 only") {
	TicTacToe4 game;
	game.start_game("X");
	REQUIRE_THROWS_AS(game.mark_board(0), Error);
	REQUIRE_THROWS_AS(game.mark_board(17), Error);
	REQUIRE_NOTHROW(game.mark_board(10));
}

TEST_CASE("Test game over if 9 slots are selected") {
	TicTacToe4 game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(3);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(6);
	game.mark_board(7);
	game.mark_board(8);
	game.mark_board(9);
	game.mark_board(10);
	game.mark_board(11);
	game.mark_board(12);
	game.mark_board(13);
	game.mark_board(14);
	game.mark_board(15);
	game.mark_board(16);
	REQUIRE(game.game_over() == true);
}

/////////// Test Column Wins ////////////////////////
TEST_CASE("Test win by first column") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(1);
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second column") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(2);
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third column") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(3);
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by fourth column") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(4);
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

///////////// Test Row Wins //////////////////////
TEST_CASE("Test win by first row") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(1);
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second row") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(5);
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third row") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(9);
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by fourth row") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(13);
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

///////////// Test Diagonal Wins //////////////////////
TEST_CASE("Test win from top right") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(4);
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win from top left") {
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);
	board.start_game("X");
	board.mark_board(1);
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X
	//X Wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test for no winner") {
	TicTacToe4 game;
	game.start_game("X");
	game.mark_board(1);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(4);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(9);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(6);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(10);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(8);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(12);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(11);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(13);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(14);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(15);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(16);//O
	//no one wins
	REQUIRE(game.game_over() == true);
}
