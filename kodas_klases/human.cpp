#include "Vec_funkcijos.h"
#include <iostream>

// Default Constructor
Human::Human() : vardas(""), pavarde("") {}

// Parameterized Constructor
Human::Human(const std::string &vardas, const std::string &pavarde) 
    : vardas(vardas), pavarde(pavarde) {}

// Destructor
Human::~Human() {}

// Copy Constructor
Human::Human(const Human &other) : vardas(other.vardas), pavarde(other.pavarde) {}

// Copy Assignment Operator
Human &Human::operator=(const Human &other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
    }
    return *this;
}

// Getters and Setters
std::string Human::getVardas() const { return vardas; }
std::string Human::getPavarde() const { return pavarde; }
void Human::setVardas(const std::string &vardas) { this->vardas = vardas; }
void Human::setPavarde(const std::string &pavarde) { this->pavarde = pavarde; }
