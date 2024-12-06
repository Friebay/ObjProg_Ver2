#ifndef LIST_FUNKCIJOS_H
#define LIST_FUNKCIJOS_H

#include "List_Biblioteka.h"
#include "Vec_funkcijos.h"

/**
 * @file List_funkcijos.h
 * @brief Antraštinis failas, kuriame apibrėžiama klasė List_Studentas ir su sąrašais susijusios funkcijos.
 */

/**
 * @class List_Studentas
 * @brief Klasė, paveldėta iš Zmogus, skirta studentų duomenims valdyti naudojant `std::list`.
 */
class List_Studentas : public Zmogus {
private:
    std::list<int> pazymiai;   ///< Pažymių sąrašas.
    int egzaminoPazymys = 0;   ///< Egzamino pažymys.
    float vidurkis = 0;        ///< Pažymių vidurkis.
    float mediana = 0;         ///< Pažymių mediana.
    float galutinisVidurkis = 0; ///< Galutinis rezultatas pagal vidurkį.
    float galutineMediana = 0; ///< Galutinis rezultatas pagal medianą.

public:
    /**
     * @brief Numatytasis konstruktorius.
     */
    List_Studentas();

    /**
     * @brief Konstruktorius su parametrais.
     * @param vardas Studentų vardas.
     * @param pavarde Studentų pavardė.
     * @param pazymiai Pažymių sąrašas.
     * @param egzaminoPazymys Egzamino pažymys.
     */
    List_Studentas(const std::string &vardas, const std::string &pavarde,
                   const std::list<int> &pazymiai, int egzaminoPazymys);

    /**
     * @brief Destruktorius.
     */
    ~List_Studentas();

    /**
     * @brief Kopijavimo konstruktorius.
     * @param other Kitas List_Studentas objektas, iš kurio kopijuojama.
     */
    List_Studentas(const List_Studentas &other);

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param other Kitas List_Studentas objektas, kuris priskiriamas.
     * @return Nuoroda į esamą objektą.
     */
    List_Studentas &operator=(const List_Studentas &other);

    // Getteriai
    /**
     * @brief Grąžina pažymių sąrašą.
     * @return Pažymių sąrašas.
     */
    std::list<int> getPazymiai() const;

    /**
     * @brief Grąžina egzamino pažymį.
     * @return Egzamino pažymys.
     */
    int getEgzaminoPazymys() const;

    /**
     * @brief Grąžina pažymių vidurkį.
     * @return Vidurkis.
     */
    float getVidurkis() const;

    /**
     * @brief Grąžina pažymių medianą.
     * @return Mediana.
     */
    float getMediana() const;

    /**
     * @brief Grąžina galutinį rezultatą pagal vidurkį.
     * @return Galutinis rezultatas pagal vidurkį.
     */
    float getGalutinisVidurkis() const;

    /**
     * @brief Grąžina galutinį rezultatą pagal medianą.
     * @return Galutinis rezultatas pagal medianą.
     */
    float getGalutineMediana() const;

    // Setteriai
    /**
     * @brief Nustato pažymių sąrašą.
     * @param pazymiai Sąrašas, kuris bus nustatytas.
     */
    void List_setPazymiai(const std::list<int> &pazymiai);

    /**
     * @brief Nustato egzamino pažymį.
     * @param egzaminoPazymys Pažymys, kuris bus nustatytas.
     */
    void setEgzaminoPazymys(int egzaminoPazymys);

    /**
     * @brief Nustato pažymių vidurkį.
     * @param vidurkis Vidurkis, kuris bus nustatytas.
     */
    void setVidurkis(float vidurkis);

    /**
     * @brief Nustato pažymių medianą.
     * @param mediana Mediana, kuri bus nustatyta.
     */
    void setMediana(float mediana);

    /**
     * @brief Nustato galutinį rezultatą pagal vidurkį.
     * @param galutinisVidurkis Galutinis rezultatas, kuris bus nustatytas.
     */
    void setGalutinisVidurkis(float galutinisVidurkis);

    /**
     * @brief Nustato galutinį rezultatą pagal medianą.
     * @param galutineMediana Galutinis rezultatas, kuris bus nustatytas.
     */
    void setGalutineMediana(float galutineMediana);

    /**
     * @brief Spausdina informaciją apie studentą.
     */
    void printInfo() const override;

    // Papildomi metodai
    /**
     * @brief Prideda pažymį į sąrašą.
     * @param pazymys Pridedamas pažymys.
     */
    void pridetiPazymi(int pazymys);

    /**
     * @brief Apskaičiuoja rezultatus, tokius kaip vidurkis ir mediana.
     */
    void List_skaiciuotiRezultatus();

    /**
     * @brief Perkrautas operatorius `<<` išvedimui.
     * @param os Išvesties srautas.
     * @param studentas Studentas, kurio duomenys spausdinami.
     * @return Išvesties srautas.
     */
    friend std::ostream &operator<<(std::ostream &os, const List_Studentas &studentas);

    /**
     * @brief Perkrautas operatorius `>>` įvedimui.
     * @param is Įvesties srautas.
     * @param studentas Studentas, kurio duomenys skaitomi.
     * @return Įvesties srautas.
     */
    friend std::istream &operator>>(std::istream &is, List_Studentas &studentas);
};

// Funkcijų deklaracijos
/**
 * @brief Vykdo programos funkcionalumą su sąrašais.
 */
void List_programa();

/**
 * @brief Apskaičiuoja pažymių vidurkį.
 * @param pazymiai Pažymių sąrašas.
 * @return Apskaičiuotas vidurkis.
 */
float List_skaiciuotiVidurki(std::list<int> &pazymiai);

/**
 * @brief Apskaičiuoja pažymių medianą.
 * @param pazymiai Pažymių sąrašas.
 * @return Apskaičiuota mediana.
 */
float List_skaiciuotiMediana(std::list<int> &pazymiai);

/**
 * @brief Įveda studento duomenis.
 * @param studentas Studentas, kurio duomenys įvedami.
 */
void List_ivestiStudentoDuomenis(List_Studentas &studentas);

/**
 * @brief Generuoja atsitiktinį studentą.
 * @return Atsitiktinis studentas su sugeneruotais duomenimis.
 */
List_Studentas List_generuotiAtsitiktiniStudenta();

/**
 * @brief Rūšiuoja studentų sąrašą.
 * @param studentai Sąrašas, kuris bus rūšiuojamas.
 */
void List_rusiuotiStudentus(std::list<List_Studentas> &studentai);

/**
 * @brief Skaito studentų duomenis iš failo.
 * @param failoPavadinimas Failo pavadinimas.
 * @param studentai Sąrašas, kuriame bus saugomi studentų duomenys.
 * @param trukmeSkaitymo Skaitymo trukmė milisekundėmis.
 * @param trukmeVidurkio Vidurkių skaičiavimo trukmė milisekundėmis.
 */
void List_skaitytiDuomenisIsFailo(
    const std::string &failoPavadinimas,
    std::list<List_Studentas> &studentai,
    long long &trukmeSkaitymo,
    long long &trukmeVidurkio);

#endif // LIST_FUNKCIJOS_H
