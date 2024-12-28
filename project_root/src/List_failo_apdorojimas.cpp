#include "../include/List_failo_apdorojimas.h"
#include "../include/List_funkcijos.h"
#include "../include/Vec_funkcijos_papildomos.h"

void List_skaiciuotiIsFailo(List_Studentas &studentas, bool tinkamiPazymiai, std::list<List_Studentas> &studentai)
{
    if (tinkamiPazymiai && !studentas.getPazymiai().empty())
    {
        std::list<int> pazymiai = studentas.getPazymiai();

        // Paskutinis pažymys - egzaminas
        studentas.setEgzaminoPazymys(pazymiai.back());
        pazymiai.pop_back();

        float vidurkis = List_skaiciuotiVidurki(pazymiai);
        float mediana = List_skaiciuotiMediana(pazymiai);

        studentas.setVidurkis(vidurkis);
        studentas.setMediana(mediana);

        const float egzaminoBalas = 0.6 * studentas.getEgzaminoPazymys();
        const float vidurkioBalas = 0.4 * vidurkis;
        const float medianosBalas = 0.4 * mediana;

        studentas.setGalutinisVidurkis(vidurkioBalas + egzaminoBalas);
        studentas.setGalutineMediana(medianosBalas + egzaminoBalas);

        studentai.push_back(studentas);
    }
    else
    {
        std::cout << "Klaida: truksta pazymiu studentui "
                  << studentas.getVardas() << " "
                  << studentas.getPavarde() << "\n";
    }
}

void List_skaitytiDuomenisIsFailo(const std::string &failoPavadinimas,
                                  std::list<List_Studentas> &studentai,
                                  long long &trukmeSkaitymo,
                                  long long &trukmeVidurkio)
{
    auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();

    std::ifstream failas(failoPavadinimas, std::ios::in | std::ios::binary);
    if (!failas)
    {
        throw std::runtime_error("Failo " + failoPavadinimas + " nera.");
    }

    std::string buffer;
    buffer.reserve(1048576); // Buferio dydis baitais

    // Praleidžia antraštę
    getline(failas, buffer);

    while (getline(failas, buffer))
    {
        if (buffer.length() < 52)
        { // Minimalaus ilgio patikrinimas
            throw std::runtime_error("Netinkamas eilutes ilgis");
        }

        List_Studentas studentas;

        // Skaito vardą ir pavardę
        studentas.setVardas(buffer.substr(0, 16));
        studentas.setPavarde(buffer.substr(16, 32));

        // Funkcija ištrinti whitespace iš string
        auto trim = [](std::string &str)
        {
            // Ištrinti pradžioję esantį whitespace
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
                                                { return !std::isspace(ch); }));
            // Ištrinti pabaigoje esantį whitespace
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
                                   { return !std::isspace(ch); })
                          .base(),
                      str.end());
        };

        std::string vardas = studentas.getVardas();
        trim(vardas);
        std::string pavarde = studentas.getPavarde();
        trim(pavarde);
        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);

        // Pažymiai prasideda nuo 52 simbolio
        size_t pozicija = 52;
        bool tinkamiPazymiai = true;
        std::list<int> pazymiai;

        while (pozicija < buffer.length())
        {
            // Praleidžia whitespace
            while (pozicija < buffer.length() && isspace(buffer[pozicija]))
                pozicija++;
            if (pozicija >= buffer.length())
                break;

            int grade = 0;
            bool tinkamas = true;

            // Patikrina ar skaičius
            if (isdigit(buffer[pozicija]))
            {
                while (pozicija < buffer.length() && isdigit(buffer[pozicija]))
                {
                    grade = grade * 10 + (buffer[pozicija] - '0');
                    pozicija++;
                }

                // Patikrina ar tarp 0 ir 10
                if (grade < 0 || grade > 10)
                {
                    tinkamas = false;
                }
            }
            else
            {
                // Jeigu ne skaičius:
                tinkamas = false; // Netinkamas
                pozicija++;       // Eina į kitą poziciją
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
            while (pozicija < buffer.length() && isspace(buffer[pozicija]))
                pozicija++;
        }

        // Nustatome pažymius
        studentas.List_setPazymiai(pazymiai);

        List_skaiciuotiIsFailo(studentas, tinkamiPazymiai, studentai);
    }

    auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
    trukmeSkaitymo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaSkaitymo - pradziaSkaitymo).count();
    trukmeVidurkio = 0;
}

void List_skaitytiIrIsvestiDuomenis(const std::string &ivestiesFailoPavadinimas,
                                    const std::string &irasymoFailoPavadinimas,
                                    long long &trukmeSkaitymo,
                                    long long &trukmeVidurkio,
                                    long long &trukmeIrasymo)
{
    std::list<List_Studentas> studentai;
    List_skaitytiDuomenisIsFailo(ivestiesFailoPavadinimas, studentai, trukmeSkaitymo, trukmeVidurkio);

    auto pradziaIrasimo = std::chrono::high_resolution_clock::now();

    // Naudoja stringstream buferiui
    std::ostringstream buffer;

    // Įrašo antraštę į buferį
    buffer << std::left << std::setw(16) << "Pavarde"
           << std::setw(16) << "Vardas"
           << std::setw(25) << "Galutinis Vidurkis"
           << "Galutine Mediana\n";
    buffer << std::string(70, '-') << "\n";

    // Sort students by surname
    studentai.sort([](const List_Studentas &a, const List_Studentas &b)
                   { return a.getPavarde() < b.getPavarde(); });

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
void List_padalintiRezultatuFaila(const std::string &ivestiesFailoPavadinimas,
                                  const std::string &islaikiusiuFailoPavadinimas,
                                  const std::string &neislaikiusiuFailoPavadinimas,
                                  long long &laikasSkaitymo,
                                  long long &rusiavimoLaikas,
                                  long long &laikasRasymo)
{
    auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();

    // Atidaro duomenis binariniu režimu
    std::ifstream ivestiesFailas(ivestiesFailoPavadinimas, std::ios::in | std::ios::binary);
    if (!ivestiesFailas)
    {
        throw std::runtime_error("Nepavyko atidaryti ivesties failo " + ivestiesFailoPavadinimas);
    }

    // Perskaito duomenis į buferį
    ivestiesFailas.seekg(0, std::ios::end);
    size_t failoDydis = ivestiesFailas.tellg();
    ivestiesFailas.seekg(0, std::ios::beg);
    std::string failoTurinys(failoDydis, '\0');
    ivestiesFailas.read(&failoTurinys[0], failoDydis);
    ivestiesFailas.close();

    std::ofstream islaikiusiuFailas(islaikiusiuFailoPavadinimas, std::ios::out | std::ios::binary);
    std::ofstream neislaikiusiuFailas(neislaikiusiuFailoPavadinimas, std::ios::out | std::ios::binary);
    if (!islaikiusiuFailas || !neislaikiusiuFailas)
    {
        throw std::runtime_error("Nepavyko atidaryti išvesties failų");
    }

    size_t pos = 0;
    size_t newline_pos = failoTurinys.find('\n');
    islaikiusiuFailas << failoTurinys.substr(0, newline_pos) << '\n';
    neislaikiusiuFailas << failoTurinys.substr(0, newline_pos) << '\n';
    pos = newline_pos + 1;

    newline_pos = failoTurinys.find('\n', pos);
    islaikiusiuFailas << failoTurinys.substr(pos, newline_pos - pos) << '\n';
    neislaikiusiuFailas << failoTurinys.substr(pos, newline_pos - pos) << '\n';
    pos = newline_pos + 1;

    // Naudojame list su List_Studentas struktūra
    std::list<List_Studentas> studentai;
    std::list<List_Studentas> vargsiukai;

    while (pos < failoTurinys.size())
    {
        newline_pos = failoTurinys.find('\n', pos);
        std::string_view line(failoTurinys.data() + pos, newline_pos - pos);
        pos = newline_pos + 1;

        List_Studentas student;
        size_t word_start = line.find_first_not_of(" \t");
        size_t word_end = line.find(' ', word_start);

        if (word_end != std::string_view::npos)
        {
            student.setPavarde(std::string(line.substr(word_start, word_end - word_start)));
            word_start = line.find_first_not_of(" \t", word_end);
            word_end = line.find(' ', word_start);

            if (word_end != std::string_view::npos)
            {
                student.setVardas(std::string(line.substr(word_start, word_end - word_start)));
                word_start = line.find_first_not_of(" \t", word_end);
                word_end = line.find(' ', word_start);

                if (word_end != std::string_view::npos)
                {
                    float galutinisVidurkis = std::stof(std::string(line.substr(word_start,
                                                                                word_end - word_start)));
                    word_start = line.find_first_not_of(" \t", word_end);
                    float galutineMediana = std::stof(std::string(line.substr(word_start)));

                    student.setGalutinisVidurkis(galutinisVidurkis);
                    student.setGalutineMediana(galutineMediana);

                    if (galutinisVidurkis >= 5.0f)
                    {
                        studentai.push_back(student);
                    }
                    else
                    {
                        vargsiukai.push_back(student);
                    }
                }
            }
        }
    }

    auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
    laikasSkaitymo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaSkaitymo - pradziaSkaitymo).count();
    std::cout << "Failo skaitymas uztruko " << laikasSkaitymo << " ms." << std::endl;

    auto pradetiRusiavima = std::chrono::high_resolution_clock::now();

    // Rūšiuojame abu sąrašus
    studentai.sort([](const List_Studentas &a, const List_Studentas &b)
                   { return a.getGalutinisVidurkis() > b.getGalutinisVidurkis(); });

    vargsiukai.sort([](const List_Studentas &a, const List_Studentas &b)
                    { return a.getGalutinisVidurkis() > b.getGalutinisVidurkis(); });

    auto pabaigaRusiavimo = std::chrono::high_resolution_clock::now();
    rusiavimoLaikas = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaRusiavimo - pradetiRusiavima).count();
    std::cout << "Rusiavimas uztruko " << rusiavimoLaikas << " ms." << std::endl;

    auto pradetiRasyma = std::chrono::high_resolution_clock::now();

    // Rašome kietiakus (likusius studentai konteineryje)
    for (const auto &studentas : studentai)
    {
        islaikiusiuFailas << std::left << std::setw(15) << studentas.getPavarde() << " "
                          << std::setw(15) << studentas.getVardas() << " "
                          << std::setw(24) << studentas.getGalutinisVidurkis() << " "
                          << studentas.getGalutineMediana() << "\n";
    }

    // Rašome vargšiukus
    for (const auto &studentas : vargsiukai)
    {
        neislaikiusiuFailas << std::left << std::setw(15) << studentas.getPavarde() << " "
                            << std::setw(15) << studentas.getVardas() << " "
                            << std::setw(24) << studentas.getGalutinisVidurkis() << " "
                            << studentas.getGalutineMediana() << "\n";
    }

    auto pabaigaRasymo = std::chrono::high_resolution_clock::now();
    laikasRasymo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaRasymo - pradetiRasyma).count();

    // Uždaryti failus
    islaikiusiuFailas.close();
    neislaikiusiuFailas.close();
}