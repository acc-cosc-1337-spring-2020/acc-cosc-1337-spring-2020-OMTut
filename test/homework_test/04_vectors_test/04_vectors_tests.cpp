#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vectors.h"
#include <vector>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test for get_max_from_vector") {

	std::vector<int> numbers{ 3, 8,1,99,1000 };
	std::vector<int> numbers2{ 15,12,11,99,88 };
	std::vector<int> numbers3{ 150,120,11,990,88888 };

	REQUIRE(get_max_from_vector(numbers) == 1000);
	REQUIRE(get_max_from_vector(numbers2) == 99);
	REQUIRE(get_max_from_vector(numbers3) == 88888);
}

TEST_CASE("Test is_prime for prime numbers") {
	
	REQUIRE(is_prime(2) == true);
	REQUIRE(is_prime(4) == false);
	REQUIRE(is_prime(43) == true);
	REQUIRE(is_prime(44) == false);
}

TEST_CASE("Testing the vector_of_primes") {
	std::vector<int> expected{ 2, 3, 5, 7 };
	std::vector<int> result = vector_of_primes(10);

	REQUIRE(result == expected);

	std::vector<int> expected2{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
	std::vector<int> result2 = vector_of_primes(50);

	REQUIRE(result2 == expected2);
}