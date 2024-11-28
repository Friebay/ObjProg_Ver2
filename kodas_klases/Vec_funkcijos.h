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
    // Constructors, Destructor, and Rule of Three
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminoPazymys);
    ~Studentas();
    Studentas(const Studentas& other);             // Copy constructor
    Studentas& operator=(const Studentas& other);  // Copy assignment operator

    // Getters and Setters (unchanged)
    std::string getVardas() const;
    std::string getPavarde() const;
    std::vector<int> getPazymiai() const;
    int getEgzaminoPazymys() const;
    float getVidurkis() const;
    float getMediana() const;
    float getGalutinisVidurkis() const;
    float getGalutineMediana() const;

    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setPazymiai(const std::vector<int>& pazymiai);
    void setVidurkis(float vidurkis);
    void setMediana(float mediana);
    void setEgzaminoPazymys(int egzaminoPazymys);
    void setGalutinisVidurkis(float galutinisVidurkis);
    void setGalutineMediana(float galutineMediana);

    // Methods
    void skaiciuotiRezultatus();
    void pridetiPazymi(int pazymys);

    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas);
    friend std::istream& operator>>(std::istream& is, Studentas& studentas);

    
};

// Other functions
void Vec_programa();
Studentas generuotiAtsitiktiniStudenta();
int gautiPazymi(const std::string& klausimas);
float skaiciuotiVidurki(const vector<int>& vidurkis);
float skaiciuotiMediana(const vector<int>& mediana);
void rusiuotiStudentus(std::vector<Studentas>& studentai);
int generuotiSkaiciu(int min, int max);
std::string generuotiVardaPavarde();
void generuotiFaila();
void generuotiAtsitiktiniusFailus();
void generuotiStudentuFaila(int studentuKiekis, const std::string& failoPavadinimas);
void vykdytiVisusZingsnius();
int gautiPazymi(const std::string& klausimas);

// Declare the operator>>
std::ifstream& operator>>(std::ifstream& failas, std::vector<Studentas>& studentai);

// Declare the file reading function
void skaitytiDuomenisIsFailo(
    const std::string& failoPavadinimas,
    std::vector<Studentas>& studentai,
    long long& trukmeSkaitymo,
    long long& trukmeVidurkio
);

#endif
