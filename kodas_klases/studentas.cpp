#include "Vec_funkcijos.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdexcept>

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

std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
    os << std::left << std::setw(16) << studentas.getPavarde()
       << std::setw(16) << studentas.getVardas()
       << std::setw(25) << std::fixed << std::setprecision(2) << studentas.getGalutinisVidurkis()
       << "   " << studentas.getGalutineMediana();
    return os;
}

int gautiPazymi(std::istream& is, const std::string& klausimas) {
    while (true) {
        std::string skaicius;
        std::cout << klausimas;
        is >> skaicius;

        if (skaicius == "-1") return -1; // End input

        try {
            int pazymys = std::stoi(skaicius);
            if (pazymys >= 0 && pazymys <= 10) {
                return pazymys;
            } else {
                std::cout << "Klaida: pazymys turi buti tarp 0 ir 10.\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Klaida: iveskite teisinga skaiciu.\n";
        }
    }
}

std::istream& operator>>(std::istream& is, Studentas& studentas) {
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminoPazymys;

    // Input fields
    std::cout << "Vardas: ";
    is >> vardas;

    std::cout << "Pavarde: ";
    is >> pavarde;

    std::cout << "Iveskite pazymius (iveskite -1, kad baigtumete):\n";
    while (true) {
        int pazymys = gautiPazymi(is, "Pazymys (arba -1, kad baigtumete): ");
        if (pazymys == -1) break;
        pazymiai.push_back(pazymys);
    }

    egzaminoPazymys = gautiPazymi(is, "Egzamino pazymys: ");
    if (egzaminoPazymys == -1) egzaminoPazymys = 0;

    // Set values in the Studentas object
    studentas.setVardas(vardas);
    studentas.setPavarde(pavarde);
    studentas.setPazymiai(pazymiai);
    studentas.setEgzaminoPazymys(egzaminoPazymys);
    studentas.skaiciuotiRezultatus();

    return is;
}