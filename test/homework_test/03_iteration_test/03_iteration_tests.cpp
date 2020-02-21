#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Testing get_gc_content function") {
	const std::string &dnacontent1 = "AGCTATAG";
	REQUIRE(get_gc_content(dnacontent1) == .375);

	const std::string &dnacontent2 = "CGCTATAG";
	REQUIRE(get_gc_content(dnacontent2) == .50);
}

TEST_CASE("Testing reverse_string function") {
	std::string dnareverse1 = "AGCTATAG";
	REQUIRE(reverse_string(dnareverse1) == "GATATCGA");

	std::string dnareverse2 = "CGCTATAG";
	REQUIRE(reverse_string(dnareverse2) == "GATATCGC");

}

TEST_CASE("Testing get_dna_complement function") {
	std::string dnacomplement1 = "AAAACCCGGT";
	REQUIRE(get_dna_complement(dnacomplement1) == "ACCGGGTTTT");

	std::string dnacomplement2 = "CCCGGAAAAT";
	REQUIRE(get_dna_complement(dnacomplement2) == "ATTTTCCGGG");
}

