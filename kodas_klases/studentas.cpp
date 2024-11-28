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


// Getters (unchanged)
std::string Studentas::getVardas() const { return vardas; }
std::string Studentas::getPavarde() const { return pavarde; }
std::vector<int> Studentas::getPazymiai() const { return pazymiai; }
int Studentas::getEgzaminoPazymys() const { return egzaminoPazymys; }
float Studentas::getVidurkis() const { return vidurkis; }
float Studentas::getMediana() const { return mediana; }
float Studentas::getGalutinisVidurkis() const { return galutinisVidurkis; }
float Studentas::getGalutineMediana() const { return galutineMediana; }

// Corrected Setters
void Studentas::setVardas(const std::string& vardas) { this->vardas = vardas; }
void Studentas::setPavarde(const std::string& pavarde) { this->pavarde = pavarde; }
void Studentas::setPazymiai(const std::vector<int>& pazymiai) { this->pazymiai = pazymiai; }
void Studentas::setVidurkis(float vidurkis) { this->vidurkis = vidurkis; }
void Studentas::setMediana(float mediana) { this->mediana = mediana; }
void Studentas::setEgzaminoPazymys(int egzaminoPazymys) { this->egzaminoPazymys = egzaminoPazymys; }
void Studentas::setGalutinisVidurkis(float galutinisVidurkis) { this->galutinisVidurkis = galutinisVidurkis; }
void Studentas::setGalutineMediana(float galutineMediana) { this->galutineMediana = galutineMediana; }

void Studentas::skaiciuotiRezultatus() {
    // Implement calculation of vidurkis, mediana, galutinisVidurkis, galutineMediana
    if (!pazymiai.empty()) {
        vidurkis = skaiciuotiVidurki(pazymiai);
        mediana = skaiciuotiMediana(pazymiai);
        
        // Example calculation of final grades (adjust as needed)
        galutinisVidurkis = 0.4 * vidurkis + 0.6 * egzaminoPazymys;
        galutineMediana = 0.4 * mediana + 0.6 * egzaminoPazymys;
    }
}

void Studentas::pridetiPazymi(int pazymys) {
    pazymiai.push_back(pazymys);
}