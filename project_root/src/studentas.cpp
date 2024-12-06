#include "../include/Vec_funkcijos.h"
#include "../include/Vec_failo_apdorojimas.h"

// Default Constructor
Studentas::Studentas() : Zmogus() {}

// Parameterized Constructor
Studentas::Studentas(const std::string &vardas, const std::string &pavarde, const std::vector<int> &pazymiai, int egzaminoPazymys)
    : Zmogus(vardas, pavarde), pazymiai(pazymiai), egzaminoPazymys(egzaminoPazymys) {
    // std::cout << "Parameterized constructor called\n";
    skaiciuotiRezultatus();
}

// Destructor
Studentas::~Studentas()
{
    // Clear the vector to release its memory
    pazymiai.clear();
    // Reset other members to default values
    vardas = "";
    pavarde = "";
    egzaminoPazymys = 0;
    vidurkis = 0.0f;
    mediana = 0.0f;
    galutinisVidurkis = 0.0f;
    galutineMediana = 0.0f;

    // Debug message to indicate destruction
    // std::cout << "Destructor called: Studentas object cleaned up.\n";
}

// Copy Constructor
Studentas::Studentas(const Studentas &other)
    : Zmogus(other), pazymiai(other.pazymiai), egzaminoPazymys(other.egzaminoPazymys),
      vidurkis(other.vidurkis), mediana(other.mediana),
      galutinisVidurkis(other.galutinisVidurkis), galutineMediana(other.galutineMediana)
{
    // Explicit copy of all members
    // std::cout << "Copy constructor called.\n";
}

// Copy Assignment Operator
Studentas &Studentas::operator=(const Studentas &other) {
    if (this != &other) {
        Zmogus::operator=(other);
        pazymiai = other.pazymiai;
        egzaminoPazymys = other.egzaminoPazymys;
        vidurkis = other.vidurkis;
        mediana = other.mediana;
        galutinisVidurkis = other.galutinisVidurkis;
        galutineMediana = other.galutineMediana;
    }
    // std::cout << "Copy assignment operator called.\n";
    return *this;
}

// Getters (unchanged)
std::vector<int> Studentas::getPazymiai() const { return pazymiai; }
int Studentas::getEgzaminoPazymys() const { return egzaminoPazymys; }
float Studentas::getVidurkis() const { return vidurkis; }
float Studentas::getMediana() const { return mediana; }
float Studentas::getGalutinisVidurkis() const { return galutinisVidurkis; }
float Studentas::getGalutineMediana() const { return galutineMediana; }

// Corrected Setters
void Studentas::setPazymiai(const std::vector<int> &pazymiai) { this->pazymiai = pazymiai; }
void Studentas::setVidurkis(float vidurkis) { this->vidurkis = vidurkis; }
void Studentas::setMediana(float mediana) { this->mediana = mediana; }
void Studentas::setEgzaminoPazymys(int egzaminoPazymys) { this->egzaminoPazymys = egzaminoPazymys; }
void Studentas::setGalutinisVidurkis(float galutinisVidurkis) { this->galutinisVidurkis = galutinisVidurkis; }
void Studentas::setGalutineMediana(float galutineMediana) { this->galutineMediana = galutineMediana; }

void Studentas::skaiciuotiRezultatus()
{
    // Implement calculation of vidurkis, mediana, galutinisVidurkis, galutineMediana
    if (!pazymiai.empty())
    {
        vidurkis = skaiciuotiVidurki(pazymiai);
        mediana = skaiciuotiMediana(pazymiai);

        // Example calculation of final grades (adjust as needed)
        galutinisVidurkis = 0.4 * vidurkis + 0.6 * egzaminoPazymys;
        galutineMediana = 0.4 * mediana + 0.6 * egzaminoPazymys;
    }
}

void Studentas::pridetiPazymi(int pazymys)
{
    pazymiai.push_back(pazymys);
}

std::ostream &operator<<(std::ostream &os, const Studentas &studentas)
{

    os << std::left << std::setw(16) << studentas.getPavarde()
       << std::setw(16) << studentas.getVardas()
       << std::setw(24) << std::fixed << std::setprecision(2)
       << studentas.getGalutinisVidurkis()
       << studentas.getGalutineMediana();
    return os;
}

int gautiPazymi(std::istream &is, const std::string &klausimas)
{
    while (true)
    {
        std::string skaicius;
        std::cout << klausimas;
        is >> skaicius;

        if (skaicius == "-1")
            return -1; // End input

        try
        {
            int pazymys = std::stoi(skaicius);
            if (pazymys >= 0 && pazymys <= 10)
            {
                return pazymys;
            }
            else
            {
                std::cout << "Klaida: pazymys turi buti tarp 0 ir 10.\n";
            }
        }
        catch (const std::invalid_argument &)
        {
            std::cout << "Klaida: iveskite teisinga skaiciu.\n";
        }
    }
}

std::istream &operator>>(std::istream &is, Studentas &studentas)
{
    if (is.rdbuf() == std::cin.rdbuf())
    {
        // Handle manual input
        std::string vardas, pavarde;
        std::vector<int> pazymiai;
        int egzaminoPazymys;

        std::cout << "Vardas: ";
        is >> vardas;
        std::cout << "Pavarde: ";
        is >> pavarde;

        std::cout << "Iveskite pazymius (iveskite -1, kad baigtumete):\n";
        while (true)
        {
            int pazymys;
            is >> pazymys;

            // Check if the input was successful
            if (is.fail())
            {
                // Clear the error state
                is.clear();
                // Ignore the invalid input
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Klaida: prasome ivesti skaiciu.\n";
                continue; // Retry the input
            }

            if (pazymys == -1)
                break;
            if (pazymys < 0 || pazymys > 10)
            {
                std::cout << "Klaida: pazymys turi buti tarp 0 ir 10.\n";
            }
            else
            {
                pazymiai.push_back(pazymys);
            }
        }

        std::cout << "Egzamino pazymys: ";
        while (true)
        {
            is >> egzaminoPazymys;

            // Check if the input was successful
            if (is.fail())
            {
                // Clear the error state
                is.clear();
                // Ignore the invalid input
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Klaida: prasome ivesti teisinga skaiciu egzamino pazymys.\n";
            }
            else
            {
                // Break the loop if input is valid
                break;
            }
        }

        // After getting a valid egzaminoPazymys, set values in the Studentas object
        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);
        studentas.setPazymiai(pazymiai);
        studentas.setEgzaminoPazymys(egzaminoPazymys);
        studentas.skaiciuotiRezultatus();
    }
    else
    {
        // Handle fixed-width file parsing (same as file input logic)
        std::string line;
        if (!std::getline(is, line))
        {
            return is; // Return early if no more lines
        }

        if (line.length() < 52)
        {
            throw std::runtime_error("Netinkamas eilutes ilgis");
        }

        // Extract fixed-width fields
        std::string vardas = line.substr(0, 16);
        std::string pavarde = line.substr(16, 32);
        auto trim = [](std::string &str)
        {
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
                                                { return !std::isspace(ch); }));
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
                                   { return !std::isspace(ch); })
                          .base(),
                      str.end());
        };
        trim(vardas);
        trim(pavarde);

        // Parse grades
        std::vector<int> pazymiai;
        size_t pozicija = 52;
        while (pozicija < line.length())
        {
            // Skip whitespace
            while (pozicija < line.length() && std::isspace(line[pozicija]))
                pozicija++;
            if (pozicija >= line.length())
                break;

            // Parse grade
            int grade = 0;
            bool tinkamas = true;
            while (pozicija < line.length() && std::isdigit(line[pozicija]))
            {
                grade = grade * 10 + (line[pozicija] - '0');
                pozicija++;
            }

            if (grade < 0 || grade > 10)
            {
                tinkamas = false;
                throw std::runtime_error("Netinkamas pazymys");
            }
            pazymiai.push_back(grade);
        }

        // Set values in the Studentas object
        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);
        studentas.setPazymiai(pazymiai);
        studentas.skaiciuotiRezultatus();

        return is;
    }

    return is;
}

// Global function to overload stream input operator for file reading
std::ifstream &operator>>(std::ifstream &failas, std::vector<Studentas> &studentai)
{
    if (!failas)
    {
        throw std::runtime_error("Failas negali būti atidarytas.");
    }

    std::string buffer;
    buffer.reserve(1048576); // Buferio dydis baitais

    // Praleidžia antraštę
    std::getline(failas, buffer);

    while (std::getline(failas, buffer))
    {
        if (buffer.length() < 52)
        {
            throw std::runtime_error("Netinkamas eilutes ilgis");
        }

        Studentas studentas;

        // Trim funkcija
        auto trim = [](std::string &str)
        {
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
                                                { return !std::isspace(ch); }));
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
                                   { return !std::isspace(ch); })
                          .base(),
                      str.end());
        };

        // Vardas ir pavardė
        std::string vardas = buffer.substr(0, 16);
        std::string pavarde = buffer.substr(16, 32);
        trim(vardas);
        trim(pavarde);

        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);

        // Pažymių skaitymas
        size_t pozicija = 52;
        bool tinkamiPazymiai = true;
        std::vector<int> pazymiai;

        while (pozicija < buffer.length())
        {
            // Praleidžia whitespace
            while (pozicija < buffer.length() && std::isspace(buffer[pozicija]))
                pozicija++;
            if (pozicija >= buffer.length())
                break;

            int grade = 0;
            bool tinkamas = true;

            if (std::isdigit(buffer[pozicija]))
            {
                while (pozicija < buffer.length() && std::isdigit(buffer[pozicija]))
                {
                    grade = grade * 10 + (buffer[pozicija] - '0');
                    pozicija++;
                }

                if (grade < 0 || grade > 10)
                {
                    tinkamas = false;
                }
            }
            else
            {
                tinkamas = false;
                pozicija++;
            }

            if (tinkamas)
            {
                pazymiai.push_back(grade);
            }
            else
            {
                tinkamiPazymiai = false;
                break;
            }

            // Praleidžia whitespace
            while (pozicija < buffer.length() && std::isspace(buffer[pozicija]))
                pozicija++;
        }

        studentas.setPazymiai(pazymiai);

        // Paskaičiuoja rezultatus
        skaiciuotiIsFailo(studentas, tinkamiPazymiai, studentai);
    }

    return failas;
}

void Studentas::printInfo() const {
    std::cout << "Vardas: " << vardas << ", Pavarde: " << pavarde << std::endl;
    std::cout << "Egzamino Pazymys: " << egzaminoPazymys << std::endl;
    std::cout << "Vidurkis: " << vidurkis << ", Mediana: " << mediana << std::endl;
    std::cout << "Galutinis Vidurkis: " << galutinisVidurkis << ", Galutine Mediana: " << galutineMediana << std::endl;
    std::cout << "Pazymiai: ";
    for (const auto &pazymys : pazymiai) {
        std::cout << pazymys << " ";
    }
    std::cout << std::endl;
}
