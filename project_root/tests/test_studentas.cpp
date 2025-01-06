#include "catch.hpp"
#include "Vec_funkcijos.h"

TEST_CASE("Studentas default constructor") {
    Studentas studentas;
    REQUIRE(studentas.getVardas() == "");
    REQUIRE(studentas.getPavarde() == "");
    REQUIRE(studentas.getPazymiai().empty());
    REQUIRE(studentas.getEgzaminoPazymys() == 0);
    REQUIRE(studentas.getVidurkis() == 0.0f);
    REQUIRE(studentas.getMediana() == 0.0f);
    REQUIRE(studentas.getGalutinisVidurkis() == 0.0f);
    REQUIRE(studentas.getGalutineMediana() == 0.0f);
}

TEST_CASE("Studentas parameterized constructor") {
    std::vector<int> pazymiai = {8, 9, 10};
    Studentas studentas("Jonas", "Jonaitis", pazymiai, 9);
    REQUIRE(studentas.getVardas() == "Jonas");
    REQUIRE(studentas.getPavarde() == "Jonaitis");
    REQUIRE(studentas.getPazymiai() == pazymiai);
    REQUIRE(studentas.getEgzaminoPazymys() == 9);
}

/*
TEST_CASE("Zmogus  constructor") {
    Zmogus zmogus("Jonas", "Jonaitis");
    REQUIRE(zmogus.getVardas() == "Jonas");
    REQUIRE(zmogus.getPavarde() == "Jonaitis");
}
*/

TEST_CASE("Studentas setters and getters") {
    Studentas studentas;
    studentas.setVardas("Petras");
    studentas.setPavarde("Petraitis");
    std::vector<int> pazymiai = {7, 8, 9};
    studentas.setPazymiai(pazymiai);
    studentas.setEgzaminoPazymys(10);
    studentas.setVidurkis(8.0f);
    studentas.setMediana(8.0f);
    studentas.setGalutinisVidurkis(8.4f);
    studentas.setGalutineMediana(8.4f);

    REQUIRE(studentas.getVardas() == "Petras");
    REQUIRE(studentas.getPavarde() == "Petraitis");
    REQUIRE(studentas.getPazymiai() == pazymiai);
    REQUIRE(studentas.getEgzaminoPazymys() == 10);
    REQUIRE(studentas.getVidurkis() == 8.0f);
    REQUIRE(studentas.getMediana() == 8.0f);
    REQUIRE(studentas.getGalutinisVidurkis() == 8.6f);
    REQUIRE(studentas.getGalutineMediana() == 8.4f);
}

TEST_CASE("Studentas result calculations") {
    std::vector<int> pazymiai = {6, 7, 8, 9, 10};
    Studentas studentas("Jonas", "Jonaitis", pazymiai, 9);
    studentas.skaiciuotiRezultatus();

    REQUIRE(studentas.getVidurkis() == Approx(8.0f).epsilon(0.01));
    REQUIRE(studentas.getMediana() == Approx(8.0f).epsilon(0.01));
    REQUIRE(studentas.getGalutinisVidurkis() == Approx(8.6f).epsilon(0.01));
    REQUIRE(studentas.getGalutineMediana() == Approx(8.6f).epsilon(0.01));
}

TEST_CASE("Studentas copy constructor") {
    std::vector<int> pazymiai = {8, 9, 2};
    Studentas original("Jonas", "Jonaitis", pazymiai, 9);
    Studentas copy = original;

    REQUIRE(copy.getVardas() == original.getVardas());
    REQUIRE(copy.getPavarde() == original.getPavarde());
    REQUIRE(copy.getPazymiai() == original.getPazymiai());
    REQUIRE(copy.getEgzaminoPazymys() == original.getEgzaminoPazymys());
    REQUIRE(copy.getVidurkis() == original.getVidurkis());
    REQUIRE(copy.getMediana() == original.getMediana());
    REQUIRE(copy.getGalutinisVidurkis() == original.getGalutinisVidurkis());
    REQUIRE(copy.getGalutineMediana() == original.getGalutineMediana());
}

TEST_CASE("Studentas copy assignment operator") {
    std::vector<int> pazymiai = {8, 9, 10};
    Studentas original("Jonas", "Jonaitis", pazymiai, 9);
    Studentas copy;
    copy = original;

    REQUIRE(copy.getVardas() == original.getVardas());
    REQUIRE(copy.getPavarde() == original.getPavarde());
    REQUIRE(copy.getPazymiai() == original.getPazymiai());
    REQUIRE(copy.getEgzaminoPazymys() == original.getEgzaminoPazymys());
    REQUIRE(copy.getVidurkis() == original.getVidurkis());
    REQUIRE(copy.getMediana() == original.getMediana());
    REQUIRE(copy.getGalutinisVidurkis() == original.getGalutinisVidurkis());
    REQUIRE(copy.getGalutineMediana() == original.getGalutineMediana());
}

TEST_CASE("Studentas destructor") {
    std::vector<int> pazymiai = {8, 9, 10};
    Studentas* studentas = new Studentas("Jonas", "Jonaitis", pazymiai, 9);
    delete studentas;

    SUCCEED("Destructor executed without issues.");
}