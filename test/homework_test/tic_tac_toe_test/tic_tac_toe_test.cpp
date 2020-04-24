#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
}

TEST_CASE("Test set first player X)") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test set first player O)") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test Mark Position accepts values from 1 to 9 only") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	REQUIRE_THROWS_AS(game->mark_board(0), Error);
	REQUIRE_THROWS_AS(game->mark_board(10), Error);
	REQUIRE_NOTHROW(game->mark_board(5));
}

TEST_CASE("Test game over if 9 slots are selected") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(3);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(8);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
}

/////////// Test Column Wins ////////////////////////
TEST_CASE("Test win by first column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by second column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by third column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

///////////// Test Row Wins //////////////////////
TEST_CASE("Test win by first row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(3);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by second row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by third row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

///////////// Test Diagonal Wins //////////////////////
TEST_CASE("Test win from top left") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}
TEST_CASE("Test win from bottom left") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(3);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test for no winner") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//X
	//no one wins
	REQUIRE(game->game_over() == true);
}

//-----------------------------------
//Tic Tac Toe 4 Tests
////////////////////////////////////
TEST_CASE("Test game over") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
}

TEST_CASE("Test set first player X)") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test set first player O)") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test Mark Position accepts values from 1 to 16 only") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE_THROWS_AS(game->mark_board(0), Error);
	REQUIRE_THROWS_AS(game->mark_board(17), Error);
	REQUIRE_NOTHROW(game->mark_board(10));
}

TEST_CASE("Test game over if 9 slots are selected") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(3);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(8);
	game->mark_board(9);
	game->mark_board(10);
	game->mark_board(11);
	game->mark_board(12);
	game->mark_board(13);
	game->mark_board(14);
	game->mark_board(15);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
}

/////////// Test Column Wins ////////////////////////
TEST_CASE("Test win by first column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(10);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(13);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by second column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(10);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(11);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(14);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by third column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(11);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(12);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(15);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by fourth column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(12);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(16);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

///////////// Test Row Wins //////////////////////
TEST_CASE("Test win by first row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(3);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by second row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(10);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(11);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by third row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(10);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(14);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(11);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(15);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(12);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by fourth row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(14);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(15);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(16);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

///////////// Test Diagonal Wins //////////////////////
TEST_CASE("Test win from top right") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(10);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(11);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(13);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win from top left") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	REQUIRE(game->game_over() == false);
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(11);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(10);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(16);//X
	//X Wins
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test for no winner") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(3);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(7);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(5);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(9);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(6);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(10);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(12);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(11);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(13);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(14);//O
	REQUIRE(game->game_over() == false);
	game->mark_board(15);//X
	REQUIRE(game->game_over() == false);
	game->mark_board(16);//O
	//no one wins
	REQUIRE(game->game_over() == true);
}
