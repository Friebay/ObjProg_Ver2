#include "../include/Vec_funkcijos.h"
#include <iostream>

// Default Constructor
Zmogus::Zmogus() : vardas(""), pavarde("") {}

// Parameterized Constructor
Zmogus::Zmogus(const std::string &vardas, const std::string &pavarde) 
    : vardas(vardas), pavarde(pavarde) {}

// Destructor
Zmogus::~Zmogus() {}

// Copy Constructor
Zmogus::Zmogus(const Zmogus &other) : vardas(other.vardas), pavarde(other.pavarde) {}

// Copy Assignment Operator
Zmogus &Zmogus::operator=(const Zmogus &other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
    }
    return *this;
}

// Getters and Setters
std::string Zmogus::getVardas() const { return vardas; }
std::string Zmogus::getPavarde() const { return pavarde; }
void Zmogus::setVardas(const std::string &vardas) { this->vardas = vardas; }
void Zmogus::setPavarde(const std::string &pavarde) { this->pavarde = pavarde; }
