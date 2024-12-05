#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "Vec_Biblioteka.h"

// Abstract base class: Zmogus
class Zmogus {
protected:
    std::string vardas;
    std::string pavarde;

public:
    // Constructors and Destructor
    Zmogus();
    Zmogus(const std::string &vardas, const std::string &pavarde);
    virtual ~Zmogus();
    Zmogus(const Zmogus &other);             // Copy constructor
    Zmogus &operator=(const Zmogus &other);  // Copy assignment operator

    // Pure virtual function (makes Zmogus abstract)
    virtual void printInfo() const = 0;

    // Getters and Setters
    std::string getVardas() const;
    std::string getPavarde() const;
    void setVardas(const std::string &vardas);
    void setPavarde(const std::string &pavarde);
};

// Derived class: Studentas
class Studentas : public Zmogus {
private:
    std::vector<int> pazymiai;
    int egzaminoPazymys = 0;
    float vidurkis = 0;
    float mediana = 0;
    float galutinisVidurkis = 0;
    float galutineMediana = 0;

public:
    // Constructors, Destructor, and Rule of Three
    Studentas();
    Studentas(const std::string &vardas, const std::string &pavarde, const std::vector<int> &pazymiai, int egzaminoPazymys);
    ~Studentas();
    Studentas(const Studentas &other);            // Copy constructor
    Studentas &operator=(const Studentas &other); // Copy assignment operator

    // Getters and Setters
    std::vector<int> getPazymiai() const;
    int getEgzaminoPazymys() const;
    float getVidurkis() const;
    float getMediana() const;
    float getGalutinisVidurkis() const;
    float getGalutineMediana() const;

    void setPazymiai(const std::vector<int> &pazymiai);
    void setEgzaminoPazymys(int egzaminoPazymys);
    void setVidurkis(float vidurkis);
    void setMediana(float mediana);
    void setGalutineMediana(float galutineMediana);
    void setGalutinisVidurkis(float galutinisVidurkis);

    // Methods
    void skaiciuotiRezultatus();
    void pridetiPazymi(int pazymys);
    void printInfo() const override;

    friend std::ostream &operator<<(std::ostream &os, const Studentas &studentas);
    friend std::istream &operator>>(std::istream &is, Studentas &studentas);
};

// Other functions
void Vec_programa();
Studentas generuotiAtsitiktiniStudenta();
int gautiPazymi(const std::string &klausimas);
float skaiciuotiVidurki(const vector<int> &vidurkis);
float skaiciuotiMediana(const vector<int> &mediana);
int generuotiSkaiciu(int min, int max);
std::string generuotiVardaPavarde();
void generuotiFaila();
void generuotiAtsitiktiniusFailus();
void generuotiStudentuFaila(int studentuKiekis, const std::string &failoPavadinimas);
void vykdytiVisusZingsnius();

// Declare the operator>>
std::ifstream &operator>>(std::ifstream &failas, std::vector<Studentas> &studentai);

// Declare the file reading function
void skaitytiDuomenisIsFailo(
    const std::string &failoPavadinimas,
    std::vector<Studentas> &studentai,
    long long &trukmeSkaitymo,
    long long &trukmeVidurkio);

#endif
