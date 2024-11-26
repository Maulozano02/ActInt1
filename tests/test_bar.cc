#include <catch2/catch_test_macros.hpp>
#include "functions.h"

TEST_CASE("contieneCodigo") {
    std::string transmission = "abcdefg";
    std::string mcode = "bcd";
    size_t pos;

    REQUIRE(contieneCodigo(transmission, mcode, pos));
    REQUIRE(pos == 1);

    mcode = "xyz";
    REQUIRE(!contieneCodigo(transmission, mcode, pos));
}

TEST_CASE("esPalindromo") {
    REQUIRE(esPalindromo("abba", 0, 3));
    REQUIRE(esPalindromo("racecar", 0, 6));
    REQUIRE(!esPalindromo("hello", 0, 4));
    REQUIRE(esPalindromo("a", 0, 0)); // Single character is a palindrome
}

TEST_CASE("palindromoMasLargo") {
    std::string transmission = "babad";
    auto result = palindromoMasLargo(transmission);

    REQUIRE(result.second == "bab" || result.second == "aba"); // Both are valid
    REQUIRE(result.first.first == 1 || result.first.first == 2);
    REQUIRE(result.first.second == 3 || result.first.second == 4);
}

TEST_CASE("subsecuenciaComunMasLarga") {
    std::string transmission1 = "abcdefg";
    std::string transmission2 = "abxdxfg";
    auto result = subsecuenciaComunMasLarga(transmission1, transmission2);

    REQUIRE(result.second == "ab");
    REQUIRE(result.first.first == 1);
    REQUIRE(result.first.second == 2);

    transmission1 = "ABCDGH";
    transmission2 = "AEDFHR";
    result = subsecuenciaComunMasLarga(transmission1, transmission2);

    REQUIRE(result.second == "ADH");
    REQUIRE(result.first.first == 1);
    REQUIRE(result.first.second == 6);
}
