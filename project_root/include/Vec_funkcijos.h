#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "Vec_Biblioteka.h"

/**
 * @file Funkcijos.h
 * @brief Antraštinis failas, kuriame apibrėžiamos klasės Zmogus ir Studentas bei susijusios funkcijos.
 */

/**
 * @class Zmogus
 * @brief Abstrakti bazinė klasė, reprezentuojanti asmenį su vardu ir pavarde.
 *
 * Ši klasė naudojama kaip bazinė klasė išvestinėms klasėms, tokioms kaip Studentas.
 */
class Zmogus {
protected:
    std::string vardas;  ///< Asmens vardas.
    std::string pavarde; ///< Asmens pavardė.

public:
    /**
     * @brief Numatytasis konstruktorius.
     */
    Zmogus();

    /**
     * @brief Konstruktorius su parametrais.
     * @param vardas Asmens vardas.
     * @param pavarde Asmens pavardė.
     */
    Zmogus(const std::string &vardas, const std::string &pavarde);

    /**
     * @brief Virtualus destruktorius.
     */
    virtual ~Zmogus();

    /**
     * @brief Kopijavimo konstruktorius.
     * @param other Kitas Zmogus objektas, iš kurio kopijuojama.
     */
    Zmogus(const Zmogus &other);

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param other Kitas Zmogus objektas, kuris priskiriamas.
     * @return Nuoroda į dabartinį objektą.
     */
    Zmogus &operator=(const Zmogus &other);

    /**
     * @brief Grynas virtualus metodas informacijai apie asmenį atspausdinti.
     */
    virtual void printInfo() const = 0;

    /**
     * @brief Grąžina asmens vardą.
     * @return Asmens vardas.
     */
    std::string getVardas() const;

    /**
     * @brief Grąžina asmens pavardę.
     * @return Asmens pavardė.
     */
    std::string getPavarde() const;

    /**
     * @brief Nustato asmens vardą.
     * @param vardas Naujasis vardas.
     */
    void setVardas(const std::string &vardas);

    /**
     * @brief Nustato asmens pavardę.
     * @param pavarde Naujasis pavardė.
     */
    void setPavarde(const std::string &pavarde);
};

/**
 * @class Studentas
 * @brief Išvestinė klasė, reprezentuojanti studentą su pažymiais ir rezultatais.
 */
class Studentas : public Zmogus {
private:
    std::vector<int> pazymiai; ///< Studentų pažymių sąrašas.
    int egzaminoPazymys = 0;   ///< Egzamino pažymys.
    float vidurkis = 0;        ///< Vidurkis.
    float mediana = 0;         ///< Mediana.
    float galutinisVidurkis = 0; ///< Galutinis rezultatas pagal vidurkį.
    float galutineMediana = 0; ///< Galutinis rezultatas pagal medianą.

public:
    /**
     * @brief Numatytasis konstruktorius.
     */
    Studentas();

    /**
     * @brief Konstruktorius su parametrais.
     * @param vardas Studentų vardas.
     * @param pavarde Studentų pavardė.
     * @param pazymiai Pažymių sąrašas.
     * @param egzaminoPazymys Egzamino pažymys.
     */
    Studentas(const std::string &vardas, const std::string &pavarde, const std::vector<int> &pazymiai, int egzaminoPazymys);

    /**
     * @brief Destruktorius.
     */
    ~Studentas();

    /**
     * @brief Kopijavimo konstruktorius.
     * @param other Kitas Studentas objektas, iš kurio kopijuojama.
     */
    Studentas(const Studentas &other);

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param other Kitas Studentas objektas, kuris priskiriamas.
     * @return Nuoroda į dabartinį objektą.
     */
    Studentas &operator=(const Studentas &other);

    // Getteriai ir setteriai (modeliuojama pagal visų funkcijų veikimo principą)
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

    /**
     * @brief Apskaičiuoja tokius rezultatus kaip vidurkis ir mediana.
     */
    void skaiciuotiRezultatus();

    /**
     * @brief Prideda pažymį į sąrašą.
     * @param pazymys Pridedamas pažymys.
     */
    void pridetiPazymi(int pazymys);

    /**
     * @brief Spausdina informaciją apie studentą.
     */
    void printInfo() const override;

    // Draugiškos funkcijos
    friend std::ostream &operator<<(std::ostream &os, const Studentas &studentas);
    friend std::istream &operator>>(std::istream &is, Studentas &studentas);
};

// Kitos funkcijos
/**
 * @brief Vykdo Vec programos funkcionalumą.
 */
void Vec_programa();

/**
 * @brief Generuoja atsitiktinį studentą.
 * @return Studentas su atsitiktiniais duomenimis.
 */
Studentas generuotiAtsitiktiniStudenta();

/**
 * @brief Grąžina pažymį, pagrįstą vartotojo įvestimi.
 * @param klausimas Klausimas, užduodamas vartotojui.
 * @return Įvestas pažymys.
 */
int gautiPazymi(const std::string &klausimas);

/**
 * @brief Apskaičiuoja pažymių vidurkį.
 * @param vidurkis Pažymių sąrašas.
 * @return Apskaičiuotas vidurkis.
 */
float skaiciuotiVidurki(const std::vector<int> &vidurkis);

/**
 * @brief Apskaičiuoja pažymių medianą.
 * @param mediana Pažymių sąrašas.
 * @return Apskaičiuota mediana.
 */
float skaiciuotiMediana(const std::vector<int> &mediana);

/**
 * @brief Generuoja atsitiktinį skaičių intervalo ribose.
 * @param min Mažiausia reikšmė.
 * @param max Didžiausia reikšmė.
 * @return Generuotas atsitiktinis skaičius.
 */
int generuotiSkaiciu(int min, int max);

/**
 * @brief Generuoja atsitiktinį vardą ir pavardę.
 * @return Sugeneruotas vardas ir pavardė.
 */
std::string generuotiVardaPavarde();

/**
 * @brief Generuoja studentų failą su atsitiktiniais duomenimis.
 */
void generuotiFaila();

/**
 * @brief Generuoja kelis atsitiktinius studentų failus.
 */
void generuotiAtsitiktiniusFailus();

/**
 * @brief Generuoja failą su tam tikru studentų skaičiumi.
 * @param studentuKiekis Kiekis studentų, kurie bus sugeneruoti.
 * @param failoPavadinimas Išvesties failo pavadinimas.
 */
void generuotiStudentuFaila(int studentuKiekis, const std::string &failoPavadinimas);

/**
 * @brief Vykdo visus programos žingsnius.
 */
void vykdytiVisusZingsnius();

/**
 * @brief Nuskaito studentų duomenis iš failo.
 * @param failoPavadinimas Įvesties failo pavadinimas.
 * @param studentai Vektorius, kuriame saugomi studentų duomenys.
 * @param trukmeSkaitymo Skaitymo trukmė milisekundėmis.
 * @param trukmeVidurkio Vidurkių skaičiavimo trukmė milisekundėmis.
 */
std::ifstream &operator>>(std::ifstream &failas, std::vector<Studentas> &studentai);

void skaitytiDuomenisIsFailo(
    const std::string &failoPavadinimas,
    std::vector<Studentas> &studentai,
    long long &trukmeSkaitymo,
    long long &trukmeVidurkio);

#endif
