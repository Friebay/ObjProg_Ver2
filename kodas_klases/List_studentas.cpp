#include "List_funkcijos.h"
#include <iostream>
#include <algorithm>
#include <numeric>

// Constructors and Destructor
List_Studentas::List_Studentas() {}

List_Studentas::List_Studentas(const std::string &vardas, const std::string &pavarde,
                               const std::list<int> &pazymiai, int egzaminoPazymys)
    : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai),
      egzaminoPazymys(egzaminoPazymys)
{
    List_skaiciuotiRezultatus();
}

List_Studentas::~List_Studentas() {}

// Getters
std::string List_Studentas::getVardas() const { return vardas; }
std::string List_Studentas::getPavarde() const { return pavarde; }
std::list<int> List_Studentas::getPazymiai() const { return pazymiai; }
int List_Studentas::getEgzaminoPazymys() const { return egzaminoPazymys; }
float List_Studentas::getVidurkis() const { return vidurkis; }
float List_Studentas::getMediana() const { return mediana; }
float List_Studentas::getGalutinisVidurkis() const { return galutinisVidurkis; }
float List_Studentas::getGalutineMediana() const { return galutineMediana; }

// Setters
void List_Studentas::setVardas(const std::string &vardas) { this->vardas = vardas; }
void List_Studentas::setPavarde(const std::string &pavarde) { this->pavarde = pavarde; }
void List_Studentas::List_setPazymiai(const std::list<int> &pazymiai) { this->pazymiai = pazymiai; }
void List_Studentas::setVidurkis(float vidurkis) { this->vidurkis = vidurkis; }
void List_Studentas::setMediana(float mediana) { this->mediana = mediana; }
void List_Studentas::setEgzaminoPazymys(int egzaminoPazymys) { this->egzaminoPazymys = egzaminoPazymys; }
void List_Studentas::setGalutinisVidurkis(float galutinisVidurkis) { this->galutinisVidurkis = galutinisVidurkis; }
void List_Studentas::setGalutineMediana(float galutineMediana) { this->galutineMediana = galutineMediana; }

void List_Studentas::pridetiPazymi(int pazymys)
{
    pazymiai.push_back(pazymys);
}

void List_Studentas::List_skaiciuotiRezultatus()
{
    // Apskaičiuojami vidurkį ir mediana
    float vidurkis = List_skaiciuotiVidurki(pazymiai);
    float mediana = List_skaiciuotiMediana(pazymiai);

    setVidurkis(vidurkis);
    setMediana(mediana);

    // Apskaičiuojami galutiniai įvertinimai
    const float egzaminoBalas = 0.6 * egzaminoPazymys;
    const float vidurkioBalas = 0.4 * vidurkis;
    const float medianosBalas = 0.4 * mediana;

    setGalutinisVidurkis(vidurkioBalas + egzaminoBalas);
    setGalutineMediana(medianosBalas + egzaminoBalas);
}