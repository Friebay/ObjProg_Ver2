#include "Vec_funkcijos.h"
#include <iostream>
#include <algorithm>
#include <numeric>

// Constructors and Destructor
Studentas::Studentas() {}
Studentas::Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminoPazymys)
    : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egzaminoPazymys(egzaminoPazymys) {
    skaiciuotiRezultatus();
}
Studentas::~Studentas() {}

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