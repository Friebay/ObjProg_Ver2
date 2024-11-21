#ifndef LIST_FUNKCIJOS_H
#define LIST_FUNKCIJOS_H
#include "List_Biblioteka.h"

class List_Studentas {
private:
    std::string vardas, pavarde;
    std::list<int> pazymiai;    
    int egzaminoPazymys = 0;
    float vidurkis = 0;
    float mediana = 0;
    float galutinisVidurkis = 0;
    float galutineMediana = 0;

public:
    // Constructors and Destructor
    List_Studentas();
    List_Studentas(const std::string& vardas, const std::string& pavarde, 
              const std::list<int>& pazymiai, int egzaminoPazymys);
    ~List_Studentas();

    // Getters
    std::string getVardas() const;
    std::string getPavarde() const;
    std::list<int> getPazymiai() const;
    int getEgzaminoPazymys() const;
    float getVidurkis() const;
    float getMediana() const;
    float getGalutinisVidurkis() const;
    float getGalutineMediana() const;

    // Setters
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setPazymiai(const std::list<int>& pazymiai);
    void setEgzaminoPazymys(int egzaminoPazymys);
    void setVidurkis(float vidurkis);
    void setMediana(float mediana);
    void setGalutinisVidurkis(float galutinisVidurkis);
    void setGalutineMediana(float galutineMediana);

    // Additional methods
    void pridetiPazymi(int pazymys);
    void skaiciuotiRezultatus();
};

// Function declarations
void List_programa();
void rusiuotiStudentus(std::list<Studentas>& studentai);
float List_skaiciuotiVidurki(std::list<int>& pazymiai);
float List_skaiciuotiMediana(std::list<int>& pazymiai);
void List_ivestiStudentoDuomenis(List_Studentas& studentas);
List_Studentas List_generuotiAtsitiktiniStudenta();
void rusiuotiStudentus(std::list<List_Studentas>& studentai);
#endif // LIST_FUNKCIJOS_H