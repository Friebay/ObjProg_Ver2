#include "Vec_funkcijos.h"
#include "Vec_funkcijos_papildomos.h"
#include "Vec_failo_apdorojimas.h"

// Gauna pažymį iš vartotojo įvesties
int gautiPazymi(const string& klausimas) {
    while (true) {
        string skaicius;
        cout << klausimas;
        cin >> skaicius;

        if (skaicius == "-1") return -1; // Grąžina -1, jei vartotojas nori baigti įvestį

        try {
            int pazymys = stoi(skaicius);
            if (pazymys >= 0 && pazymys <= 10) {
                return pazymys;
            } else {
                cout << "Klaida: pazymys turi buti tarp 0 ir 10.\n";
            }
        } catch (const invalid_argument&) {
            cout << "Klaida: iveskite teisinga skaiciu.\n";
        }
    }
}

// Rūšiuoja studentus pagal pavardę, o jei pavardės vienodos - pagal vardą
void rusiuotiStudentusPagalPavarde(std::vector<Studentas>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        if (a.getPavarde() == b.getPavarde()) {
            return a.getVardas() < b.getVardas(); // Sort by `vardas` if `pavarde` is the same
        }
        return a.getPavarde() < b.getPavarde(); // Sort by `pavarde`
    });
}


// Rūšiuoja studentus pagal vardą, o jei vardai vienodos - pagal pavardę
void rusiuotiStudentusPagalVarda(std::vector<Studentas>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        if (a.getVardas() == b.getVardas()) {
            return a.getPavarde() < b.getPavarde(); // Sort by `pavarde` if `vardas` is the same
        }
        return a.getVardas() < b.getVardas(); // Sort by `vardas`
    });
}

// Rūšiuoja studentus pagal galutinį vidurkį nuo mažiausio iki didžiausio
void rusiuotiPagalVidurkiDidejanciai(std::vector<Studentas>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVidurkis() < b.getGalutinisVidurkis();
    });
}


// Rūšiuoja studentus pagal galutinį vidurkį nuo didžiausio iki mažiausio
void rusiuotiPagalVidurkiMazejanciai(std::vector<Studentas>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVidurkis() > b.getGalutinisVidurkis();
    });
}

void ivestiStudentoDuomenis(Studentas& studentas) {
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminoPazymys;

    std::cout << "Vardas: ";
    std::cin >> vardas;

    std::cout << "Pavarde: ";
    std::cin >> pavarde;

    std::cout << "Iveskite pazymius (iveskite -1, kad baigtumete):\n";
    while (true) {
        int pazymys = gautiPazymi("Pazymys (arba -1, kad baigtumete): ");
        if (pazymys == -1) break;
        pazymiai.push_back(pazymys);
    }

    egzaminoPazymys = gautiPazymi("Egzamino pazymys: ");
    if (egzaminoPazymys == -1) egzaminoPazymys = 0;

    studentas.setVardas(vardas);
    studentas.setPavarde(pavarde);
    studentas.setPazymiai(pazymiai);
    studentas.setEgzaminoPazymys(egzaminoPazymys);

    studentas.skaiciuotiRezultatus();
}

// Skaičiuoja pažymių medianą
float skaiciuotiMediana(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0;
   
    std::vector<int> tempPazymiai = pazymiai;  // Create a copy to avoid modifying original
    size_t n = tempPazymiai.size();
    size_t middle = n / 2;
   
    if (n % 2 == 0) {
        std::nth_element(tempPazymiai.begin(), tempPazymiai.begin() + middle - 1, tempPazymiai.end());
        std::nth_element(tempPazymiai.begin() + middle - 1, tempPazymiai.begin() + middle, tempPazymiai.end());
        return (tempPazymiai[middle-1] + tempPazymiai[middle]) / 2.0f;
    } else {
        std::nth_element(tempPazymiai.begin(), tempPazymiai.begin() + middle, tempPazymiai.end());
        return tempPazymiai[middle];
    }
}

// Skaičiuoja pažymių vidurkį
float skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) {
        return 0.0f;
    }
    return std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0f) / pazymiai.size();
}



int generuotiSkaiciu(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}


// Generuoja atsitiktinį vardą arba pavardę
string generuotiVardaPavarde() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static const char raides[] = "abcdefghijklmnopqrstuvwxyz";
    std::uniform_int_distribution<int> raideDistrib(0, 25);
    string vardasPavarde(4, ' ');
    for (int i = 0; i < 4; ++i) {
        vardasPavarde[i] = raides[raideDistrib(gen)];
    }
    return vardasPavarde;
}

Studentas generuotiAtsitiktiniStudenta() {
    Studentas studentas;

    // Set atsitiktinis vardas ir pavarde
    studentas.setVardas(generuotiVardaPavarde());
    studentas.setPavarde(generuotiVardaPavarde());

    // Pre-allocate space for pazymiai
    int pazymiuKiekis = generuotiSkaiciu(1, 20);
    std::vector<int> pazymiai;
    pazymiai.reserve(pazymiuKiekis);

    // Generuojami atsitiktiniai pažymiai
    for (int i = 0; i < pazymiuKiekis; i++) {
        pazymiai.push_back(generuotiSkaiciu(0, 10));
    }
    studentas.setPazymiai(pazymiai); // Set pazymiai

    // Generuojamas egzamino pažymys
    int egzaminoPazymys = generuotiSkaiciu(0, 10);
    studentas.setEgzaminoPazymys(egzaminoPazymys);

    // Apskaičiuojami vidurkis ir mediana
    float vidurkis = skaiciuotiVidurki(studentas.getPazymiai());
    float mediana = skaiciuotiMediana(studentas.getPazymiai());
    studentas.setVidurkis(vidurkis); // Set vidurkis
    studentas.setMediana(mediana);  // Set mediana

    // Apskaičiuojami galutiniai įvertinimai
    const double egzaminoBalas = 0.6 * egzaminoPazymys;
    const double vidurkioBalas = 0.4 * vidurkis;
    const double medianosBalas = 0.4 * mediana;

    studentas.setGalutinisVidurkis(vidurkioBalas + egzaminoBalas); // Set galutinis vidurkis
    studentas.setGalutineMediana(medianosBalas + egzaminoBalas);   // Set galutine mediana

    return studentas;
}

void generuotiAtsitiktiniusFailus() {
    for (int i = 1; i <= 5; ++i) {
        int studentuKiekis = generuotiSkaiciu(1, 1000000);
        string failoPavadinimas = "txt_failai/studentai_random_" + to_string(i) + ".txt";
        generuotiStudentuFaila(studentuKiekis, failoPavadinimas);
        cout << "Sugeneruotas failas " << failoPavadinimas << " su " << studentuKiekis << " studentu.\n";
    }
}


void vykdytiVisusZingsnius() {
    vector<int> studentuKiekiai = {1000000, 10000000};
    
    // Atidaryti CSV failą rašymui
    ofstream csvFile("performance_data.csv", std::ios::app);
    if (!csvFile.is_open()) {
        throw runtime_error("Nepavyko atidaryti CSV failo");
    }
    
    // Įrašo CSV antraštę, jei failas tuščias
    csvFile.seekp(0, std::ios::end);
    if (csvFile.tellp() == 0) {
        csvFile << "Testavimo Laikas;Studentu Kiekis;Studentu generavimo laikas;Sugeneruotu duomenu skaitymo laikas;Rezultatu irasymo laikas;Rezultatu skaitymo laikas;Rezultatu skaidymo laikas;Skaidymo irasymas;Bendras Laikas\n";
    }

    for (int kiekis : studentuKiekiai) {
        cout << "Vykdomi zingsniai su " << kiekis << " studentu:\n";
        
        // Gauti dabartinį laiką
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        string timestamp = ss.str();

        // Generuoti studentų failą
        string studentuFailas = "txt_failai/studentai_" + to_string(kiekis) + ".txt";
        auto pradziaGeneravimo = std::chrono::high_resolution_clock::now();
        generuotiStudentuFaila(kiekis, studentuFailas);
        auto pabaigaGeneravimo = std::chrono::high_resolution_clock::now();
        auto trukmeGeneravimo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaGeneravimo - pradziaGeneravimo);
        cout << "Failo su " << kiekis << "studentais generavimas uztruko " << trukmeGeneravimo.count() << " ms.\n";

        // Skaitomas sugeneruotas failas, apskaičiuoja galutinius rezultatus ir išvedamas į rezultatų failą
        string rezultatuFailas = "txt_failai/rezultatai_" + to_string(kiekis) + ".txt";
        cout << "Skaitomi duomenys ir isvedami i " << rezultatuFailas << "...\n";
        long long trukmeSkaitymo, trukmeVidurkio, trukmeIrasymo;
        auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();
        skaitytiIrIsvestiDuomenis(studentuFailas, rezultatuFailas, trukmeSkaitymo, trukmeVidurkio, trukmeIrasymo);
        auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
        auto trukmeSkaitymoLaikas = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaSkaitymo - pradziaSkaitymo);
        
        cout << "Skaitymo laikas: " << trukmeSkaitymo << " ms.\n";
        cout << "Duomenu isvedimas i " << rezultatuFailas << " uztruko " << trukmeIrasymo << " ms.\n";

        // Rezultatų failo padalijimas į išlaikiusius ir neišlaikiusius
        string islaikeFailas = "txt_failai/rezultatai_" + to_string(kiekis) + "_islaike.txt";
        string neislaikeFailas = "txt_failai/rezultatai_" + to_string(kiekis) + "_neislaike.txt";
        cout << "Dalinamas rezultatu failas i islaikiusius ir neislaikiusius...\n";
        long long trukmeRezultatuSkaitymo, trukmeRezultatuSkaidymas, trukmeSkaidymoIrasymas;
        padalintiRezultatuFaila(rezultatuFailas, islaikeFailas, neislaikeFailas, trukmeRezultatuSkaitymo, trukmeRezultatuSkaidymas, trukmeSkaidymoIrasymas);
        cout << "Rezultatu failo dalinimas uztruko " << trukmeRezultatuSkaitymo + trukmeRezultatuSkaidymas + trukmeSkaidymoIrasymas << " ms.\n";

        // Skaičuoti bendrą laiką
        long long bendrasLaikas = trukmeGeneravimo.count() + trukmeSkaitymo + trukmeIrasymo + trukmeRezultatuSkaitymo + trukmeRezultatuSkaidymas + trukmeSkaidymoIrasymas;
        cout << "Visi zingsniai su " << kiekis << " studentu baigti. Trukme: " << bendrasLaikas << " ms.\n\n";

        // Surašyti laikus į CSV failą
        csvFile << timestamp << ";"
                << kiekis << ";"
                << trukmeGeneravimo.count() << ";"
                << trukmeSkaitymo << ";"
                << trukmeIrasymo << ";"
                << trukmeRezultatuSkaitymo << ";"
                << trukmeRezultatuSkaidymas << ";"
                << trukmeSkaidymoIrasymas << ";"
                << bendrasLaikas << "\n";
    }

    csvFile.close();
    cout << "Visi zingsniai visiems studentu kiekiams baigti.\n";
    cout << "Duomenys issaugoti faile 'performance_data.csv'\n";
}
