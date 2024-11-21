#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "Vec_Biblioteka.h"

class Studentas {
private:
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminoPazymys = 0;
    float vidurkis = 0;
    float mediana = 0;
    float galutinisVidurkis = 0;
    float galutineMediana = 0;

public:
    // Constructors and Destructor
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminoPazymys);
    ~Studentas();

    // Getters
    std::string getVardas() const;
    std::string getPavarde() const;
    std::vector<int> getPazymiai() const;
    int getEgzaminoPazymys() const;
    float getVidurkis() const;
    float getMediana() const;
    float getGalutinisVidurkis() const;
    float getGalutineMediana() const;

    // Setters
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setPazymiai(const std::vector<int>& pazymiai);
    void setEgzaminoPazymys(int egzaminoPazymys);

    // Methods
    void skaiciuotiRezultatus();
    void pridetiPazymi(int pazymys);
};

// Other functions
void Vec_programa();
Studentas generuotiAtsitiktiniStudenta();
int gautiPazymi(const std::string& klausimas);
float skaiciuotiMediana(std::vector<int>& pazymiai);
float skaiciuotiVidurki(std::vector<int>& pazymiai);
void rusiuotiStudentus(std::vector<Studentas>& studentai);
int generuotiSkaiciu(int min, int max);
std::string generuotiVardaPavarde();
void generuotiFaila();
void generuotiAtsitiktiniusFailus();
void generuotiStudentuFaila(int studentuKiekis, const std::string& failoPavadinimas);
void vykdytiVisusZingsnius();

#endif
