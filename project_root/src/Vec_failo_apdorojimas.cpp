#include "../include/Vec_failo_apdorojimas.h"

void skaiciuotiIsFailo(Studentas &studentas, bool tinkamiPazymiai, std::vector<Studentas> &studentai)
{
    if (tinkamiPazymiai && !studentas.getPazymiai().empty())
    {
        // Extract and set the exam score
        std::vector<int> pazymiai = studentas.getPazymiai();
        int egzaminoPazymys = pazymiai.back();
        pazymiai.pop_back();

        studentas.setEgzaminoPazymys(egzaminoPazymys);
        studentas.setPazymiai(pazymiai);

        // Calculate results
        studentas.skaiciuotiRezultatus();

        // Add the student to the vector
        studentai.push_back(std::move(studentas));
    }
    else
    {
        std::cout << "Klaida: truksta pazymiu studentui "
                  << studentas.getVardas() << " "
                  << studentas.getPavarde() << "\n";
    }
}

// Modified skaitytiDuomenisIsFailo function to use the new operator
void skaitytiDuomenisIsFailo(
    const std::string &failoPavadinimas,
    std::vector<Studentas> &studentai,
    long long &trukmeSkaitymo,
    long long &trukmeVidurkio)
{
    auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();

    std::ifstream failas(failoPavadinimas, std::ios::in | std::ios::binary);
    if (!failas)
    {
        throw std::runtime_error("Failo " + failoPavadinimas + " nera.");
    }

    failas >> studentai;

    auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
    trukmeSkaitymo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaSkaitymo - pradziaSkaitymo).count();
    trukmeVidurkio = 0;
}

void skaitytiIrIsvestiDuomenis(
    const std::string &ivestiesFailoPavadinimas,
    const std::string &irasymoFailoPavadinimas,
    long long &trukmeSkaitymo,
    long long &trukmeVidurkio,
    long long &trukmeIrasymo)
{
    std::vector<Studentas> studentai;

    // Skaitymas iš failo
    skaitytiDuomenisIsFailo(ivestiesFailoPavadinimas, studentai, trukmeSkaitymo, trukmeVidurkio);

    auto pradziaIrasimo = std::chrono::high_resolution_clock::now();

    // Naudoja stringstream buferiui
    std::ostringstream buffer;

    // Įrašo antraštę į buferį
    buffer << std::left << std::setw(16) << "Pavarde"
           << std::setw(16) << "Vardas"
           << std::setw(25) << "Galutinis Vidurkis"
           << "Galutine Mediana\n";
    buffer << std::string(70, '-') << "\n";

    for (const auto &studentas : studentai)
    {
        buffer << std::left << std::setw(16) << studentas.getPavarde()
               << std::setw(16) << studentas.getVardas()
               << std::setw(25) << std::fixed << std::setprecision(2) << studentas.getGalutinisVidurkis()
               << std::fixed << std::setprecision(2) << studentas.getGalutineMediana()
               << "\n";
    }

    // Atidaro failą įrašymui
    std::ofstream irasymoFailas(irasymoFailoPavadinimas, std::ios::out | std::ios::binary);
    if (!irasymoFailas)
    {
        throw std::runtime_error("Nepavyko atidaryti isvesties failo " + irasymoFailoPavadinimas);
    }

    // Įrašo visą buferį vienu metu
    irasymoFailas << buffer.str();
    irasymoFailas.close();

    auto pabaigaIrasimo = std::chrono::high_resolution_clock::now();
    trukmeIrasymo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaIrasimo - pradziaIrasimo).count();
}

void padalintiRezultatuFaila(const std::string &ivestiesFailoPavadinimas,
                             const std::string &islaikiusiuFailoPavadinimas,
                             const std::string &neislaikiusiuFailoPavadinimas,
                             long long &laikasSkaitymo,
                             long long &rusiavimoLaikas,
                             long long &laikasRasymo)
{
    auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();

    // Open input file with optimized flags
    std::ifstream ivestiesFailas(ivestiesFailoPavadinimas, std::ios::in | std::ios::binary | std::ios::ate);
    if (!ivestiesFailas)
    {
        throw std::runtime_error("Nepavyko atidaryti ivesties failo: " + ivestiesFailoPavadinimas);
    }

    // Read file content into string
    const auto failoDydis = ivestiesFailas.tellg();
    std::string failoTurinys(failoDydis, '\0');
    ivestiesFailas.seekg(0);
    ivestiesFailas.read(&failoTurinys[0], failoDydis);
    ivestiesFailas.close();

    // Prepare output files
    std::ofstream islaikiusiuFailas(islaikiusiuFailoPavadinimas, std::ios::out | std::ios::binary);
    std::ofstream neislaikiusiuFailas(neislaikiusiuFailoPavadinimas, std::ios::out | std::ios::binary);
    if (!islaikiusiuFailas || !neislaikiusiuFailas)
    {
        throw std::runtime_error("Nepavyko atidaryti išvesties failų");
    }

    // Read header
    std::istringstream inputStream(failoTurinys);
    std::string headerLine;
    std::getline(inputStream, headerLine);

    islaikiusiuFailas << headerLine << "\n";
    neislaikiusiuFailas << headerLine << "\n";

    std::vector<Studentas> studentai, vargsiukai;
    std::string line;

    // Parse student data
    while (std::getline(inputStream, line))
    {
        if (line.empty())
            continue;

        std::istringstream lineStream(line);
        Studentas studentas;

        std::string vardas, pavarde;
        float galutinisVidurkis, galutineMediana;

        lineStream >> pavarde >> vardas >> galutinisVidurkis >> galutineMediana;

        studentas.setPavarde(pavarde);
        studentas.setVardas(vardas);
        studentas.setGalutinisVidurkis(galutinisVidurkis);
        studentas.setGalutineMediana(galutineMediana);

        studentai.push_back(studentas);
    }

    auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
    laikasSkaitymo = std::chrono::duration_cast<std::chrono::milliseconds>(
                         pabaigaSkaitymo - pradziaSkaitymo)
                         .count();

    // Sort and partition students
    auto pradetiRusiavima = std::chrono::high_resolution_clock::now();

    auto partitionPoint = std::partition(studentai.begin(), studentai.end(),
                                         [](const Studentas &studentas)
                                         {
                                             return studentas.getGalutinisVidurkis() >= 5.0f;
                                         });

    vargsiukai.insert(vargsiukai.end(), partitionPoint, studentai.end());
    studentai.erase(partitionPoint, studentai.end());

    // Sort both groups
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
              { return a.getGalutinisVidurkis() > b.getGalutinisVidurkis(); });

    std::sort(vargsiukai.begin(), vargsiukai.end(), [](const Studentas &a, const Studentas &b)
              { return a.getGalutinisVidurkis() > b.getGalutinisVidurkis(); });

    auto pabaigaRusiavimo = std::chrono::high_resolution_clock::now();
    rusiavimoLaikas = std::chrono::duration_cast<std::chrono::milliseconds>(
                          pabaigaRusiavimo - pradetiRusiavima)
                          .count();

    // Write results to files
    auto pradetiRasyma = std::chrono::high_resolution_clock::now();

    for (const auto &studentas : studentai)
    {
        islaikiusiuFailas << studentas << std::endl;
    }

    for (const auto &studentas : vargsiukai)
    {
        neislaikiusiuFailas << studentas << std::endl;
    }

    auto pabaigaRasymo = std::chrono::high_resolution_clock::now();
    laikasRasymo = std::chrono::duration_cast<std::chrono::milliseconds>(
                       pabaigaRasymo - pradetiRasyma)
                       .count();

    islaikiusiuFailas.close();
    neislaikiusiuFailas.close();
}