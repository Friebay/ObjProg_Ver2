#include "Vec_funkcijos.h"
#include <iostream>
#include <algorithm>
#include <numeric>

// Default Constructor
Studentas::Studentas() {}

// Parameterized Constructor
Studentas::Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminoPazymys)
    : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egzaminoPazymys(egzaminoPazymys) {
    skaiciuotiRezultatus();
}

// Destructor
Studentas::~Studentas() {
    // Clear the vector to release its memory
    pazymiai.clear();
    // Reset other members to default values
    vardas = "";
    pavarde = "";
    egzaminoPazymys = 0;
    vidurkis = 0.0f;
    mediana = 0.0f;
    galutinisVidurkis = 0.0f;
    galutineMediana = 0.0f;

    // Optional debug message to indicate destruction
    std::cout << "Destructor called: Studentas object cleaned up.\n";
}


// Copy Constructor
Studentas::Studentas(const Studentas& other) 
    : vardas(other.vardas), pavarde(other.pavarde), pazymiai(other.pazymiai),
      egzaminoPazymys(other.egzaminoPazymys), vidurkis(other.vidurkis),
      mediana(other.mediana), galutinisVidurkis(other.galutinisVidurkis),
      galutineMediana(other.galutineMediana) {
    // Explicit copy of all members
    std::cout << "Copy constructor called.\n";
}

// Copy Assignment Operator
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) { // Check for self-assignment
        vardas = other.vardas;
        pavarde = other.pavarde;
        pazymiai = other.pazymiai;
        egzaminoPazymys = other.egzaminoPazymys;
        vidurkis = other.vidurkis;
        mediana = other.mediana;
        galutinisVidurkis = other.galutinisVidurkis;
        galutineMediana = other.galutineMediana;
    }
    std::cout << "Copy assignment operator called.\n";
    return *this;
}

// Other methods (unchanged)
void Studentas::skaiciuotiRezultatus() {
    if (!pazymiai.empty()) {
        vidurkis = skaiciuotiVidurki(pazymiai);
        mediana = skaiciuotiMediana(pazymiai);
        galutinisVidurkis = 0.4 * vidurkis + 0.6 * egzaminoPazymys;
        galutineMediana = 0.4 * mediana + 0.6 * egzaminoPazymys;
    }
}

void Studentas::pridetiPazymi(int pazymys) {
    pazymiai.push_back(pazymys);
}
