#ifndef LIST_FUNKCIJOS_H
#define LIST_FUNKCIJOS_H

#include "List_Biblioteka.h"


class List_Studentas : public Human {
private:
    std::list<int> pazymiai;
    int egzaminoPazymys = 0;
    float vidurkis = 0;
    float mediana = 0;
    float galutinisVidurkis = 0;
    float galutineMediana = 0;

public:
    // Constructors and Destructor
    List_Studentas();
    List_Studentas(const std::string &vardas, const std::string &pavarde,
                   const std::list<int> &pazymiai, int egzaminoPazymys);
    ~List_Studentas();
    List_Studentas(const List_Studentas &other);            // Copy constructor
    List_Studentas &operator=(const List_Studentas &other); // Copy assignment operator

    // Getters
    std::list<int> getPazymiai() const;
    int getEgzaminoPazymys() const;
    float getVidurkis() const;
    float getMediana() const;
    float getGalutinisVidurkis() const;
    float getGalutineMediana() const;

    // Setters
    void List_setPazymiai(const std::list<int> &pazymiai);
    void setEgzaminoPazymys(int egzaminoPazymys);
    void setVidurkis(float vidurkis);
    void setMediana(float mediana);
    void setGalutinisVidurkis(float galutinisVidurkis);
    void setGalutineMediana(float galutineMediana);

    // Required override for Human's pure virtual function
    void printInfo() const override;

    // Additional methods
    void pridetiPazymi(int pazymys);
    void List_skaiciuotiRezultatus();

    friend std::ostream &operator<<(std::ostream &os, const List_Studentas &studentas);
    friend std::istream &operator>>(std::istream &is, List_Studentas &studentas);
};


// Function declarations
void List_programa();
float List_skaiciuotiVidurki(std::list<int> &pazymiai);
float List_skaiciuotiMediana(std::list<int> &pazymiai);
void List_ivestiStudentoDuomenis(List_Studentas &studentas);
List_Studentas List_generuotiAtsitiktiniStudenta();
void List_rusiuotiStudentus(std::list<List_Studentas> &studentai);

int gautiPazymi(const std::string &klausimas);
int generuotiSkaiciu(int min, int max);
std::string generuotiVardaPavarde();
void generuotiFaila();
void generuotiAtsitiktiniusFailus();
void generuotiStudentuFaila(int studentuKiekis, const std::string &failoPavadinimas);
void List_vykdytiVisusZingsnius();

// Declare the operator>>
std::ifstream &operator>>(std::ifstream &failas, std::list<List_Studentas> &studentai);


void List_skaitytiDuomenisIsFailo(
    const std::string &failoPavadinimas,
    std::list<List_Studentas> &studentai,
    long long &trukmeSkaitymo,
    long long &trukmeVidurkio);

#endif // LIST_FUNKCIJOS_H