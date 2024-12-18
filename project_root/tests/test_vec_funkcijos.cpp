#include "catch.hpp"
#include "Vec_funkcijos.h"
#include "Vec_funkcijos_papildomos.h"

TEST_CASE("Vec_funkcijos: Sort by Average Ascending") {
    std::vector<Studentas> studentai = {
        Studentas("Jonas", "Jonaitis", {8, 9, 10}, 9),
        Studentas("Petras", "Petraitis", {6, 7, 8}, 7),
        Studentas("Ona", "Onaitė", {9, 9, 9}, 9)
    };
    rusiuotiPagalVidurkiDidejanciai(studentai);
    REQUIRE(studentai[0].getVardas() == "Petras");
    REQUIRE(studentai[1].getVardas() == "Jonas");
    REQUIRE(studentai[2].getVardas() == "Ona");
}
