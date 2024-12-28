#include "catch.hpp"
#include "List_funkcijos.h"

TEST_CASE("List_funkcijos: Calculate Average") {
    std::list<int> pazymiai = {8, 9, 10};
    REQUIRE(List_skaiciuotiVidurki(pazymiai) == Approx(9.0).epsilon(0.01));
}

TEST_CASE("List_funkcijos: Calculate Median") {
    std::list<int> pazymiai = {8, 9, 10};
    REQUIRE(List_skaiciuotiMediana(pazymiai) == Approx(9.0).epsilon(0.01));
}