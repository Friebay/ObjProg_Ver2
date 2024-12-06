#include "../include/List_funkcijos.h"
#include "../include/Vec_funkcijos.h"

// Constructors and Destructor
List_Studentas::List_Studentas() : Zmogus()
{
    // std::cout << "Default constructor called\n";
}

List_Studentas::List_Studentas(const std::string &vardas, const std::string &pavarde,
                               const std::list<int> &pazymiai, int egzaminoPazymys)
    : Zmogus(vardas, pavarde), pazymiai(pazymiai), egzaminoPazymys(egzaminoPazymys)
{
    // std::cout << "Parameterized constructor called\n";
    List_skaiciuotiRezultatus();
}

// Destructor
List_Studentas::~List_Studentas()
{
    // std::cout << "Destructor called\n";
}

// Copy Constructor
List_Studentas::List_Studentas(const List_Studentas &other)
    : Zmogus(other), pazymiai(other.pazymiai), egzaminoPazymys(other.egzaminoPazymys),
      vidurkis(other.vidurkis), mediana(other.mediana),
      galutinisVidurkis(other.galutinisVidurkis), galutineMediana(other.galutineMediana)
{
    // std::cout << "Copy constructor called\n";
}

// Copy Assignment Operator
List_Studentas &List_Studentas::operator=(const List_Studentas &other)
{
    if (this == &other)
    {
        return *this; // Handle self-assignment
    }

    // std::cout << "Copy assignment operator called\n";

    // Call base class assignment operator
    Zmogus::operator=(other);

    // Copy fields specific to List_Studentas
    pazymiai = other.pazymiai;
    egzaminoPazymys = other.egzaminoPazymys;
    vidurkis = other.vidurkis;
    mediana = other.mediana;
    galutinisVidurkis = other.galutinisVidurkis;
    galutineMediana = other.galutineMediana;

    return *this;
}

// Getters
std::list<int> List_Studentas::getPazymiai() const { return pazymiai; }
int List_Studentas::getEgzaminoPazymys() const { return egzaminoPazymys; }
float List_Studentas::getVidurkis() const { return vidurkis; }
float List_Studentas::getMediana() const { return mediana; }
float List_Studentas::getGalutinisVidurkis() const { return galutinisVidurkis; }
float List_Studentas::getGalutineMediana() const { return galutineMediana; }

// Setters
void List_Studentas::List_setPazymiai(const std::list<int> &pazymiai) { this->pazymiai = pazymiai; }
void List_Studentas::setVidurkis(float vidurkis) { this->vidurkis = vidurkis; }
void List_Studentas::setMediana(float mediana) { this->mediana = mediana; }
void List_Studentas::setEgzaminoPazymys(int egzaminoPazymys) { this->egzaminoPazymys = egzaminoPazymys; }
void List_Studentas::setGalutinisVidurkis(float galutinisVidurkis) { this->galutinisVidurkis = galutinisVidurkis; }
void List_Studentas::setGalutineMediana(float galutineMediana) { this->galutineMediana = galutineMediana; }

// Method to add a grade
void List_Studentas::pridetiPazymi(int pazymys)
{
    pazymiai.push_back(pazymys);
}

// Method to calculate results
void List_Studentas::List_skaiciuotiRezultatus()
{
    // Calculate average and median
    float vidurkis = List_skaiciuotiVidurki(pazymiai);
    float mediana = List_skaiciuotiMediana(pazymiai);

    setVidurkis(vidurkis);
    setMediana(mediana);

    // Calculate final grades
    const float egzaminoBalas = 0.6f * egzaminoPazymys;
    const float vidurkioBalas = 0.4f * vidurkis;
    const float medianosBalas = 0.4f * mediana;

    setGalutinisVidurkis(vidurkioBalas + egzaminoBalas);
    setGalutineMediana(medianosBalas + egzaminoBalas);
}

// Override Zmogus's pure virtual function
void List_Studentas::printInfo() const
{
    std::cout << "Studentas: " << getVardas() << " " << getPavarde() << "\n"
              << "Egzamino pazymys: " << egzaminoPazymys << "\n"
              << "Vidurkis: " << vidurkis << "\n"
              << "Mediana: " << mediana << "\n"
              << "Galutinis Vidurkis: " << galutinisVidurkis << "\n"
              << "Galutine Mediana: " << galutineMediana << "\n";
}
