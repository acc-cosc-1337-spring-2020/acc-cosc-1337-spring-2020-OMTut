#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vectors.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test for get_max_from_vector") {

	std::vector<int> numbers{ 3, 8,1,99,1000 };
	std::vector<int> numbers2{ 15,12,11,99,88 };
	std::vector<int> numbers3{ 150,120,11,990,88888 };

	get_max_from_vector(numbers);
	get_max_from_vector(numbers2);
	get_max_from_vector(numbers3);

	REQUIRE(get_max_from_vector(numbers) == 1000);
	REQUIRE(get_max_from_vector(numbers2) == 99);
	REQUIRE(get_max_from_vector(numbers3) == 88888);
}

TEST_CASE("Test is_prime for prime numbers") {
	int number1 = 2;
	int number2 = 4;
	int number3 = 43;
	int number4 = 44;

	is_prime(number1);
	is_prime(number2);
	is_prime(number3);
	is_prime(number4);

	//REQUIRE(is_prime(number1) == true);
	REQUIRE(is_prime(number2) == false);
	REQUIRE(is_prime(number3) == true);
	REQUIRE(is_prime(number4) == false);
	REQUIRE(is_prime(number1) == true);
}