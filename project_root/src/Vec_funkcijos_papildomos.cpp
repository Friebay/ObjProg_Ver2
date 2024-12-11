#include "../include/Vec_funkcijos.h"
#include "../include/Vec_funkcijos_papildomos.h"
#include "../include/Vec_failo_apdorojimas.h"

// Gauna pažymį iš vartotojo įvesties
int gautiPazymi(const string &klausimas)
{
    while (true)
    {
        string skaicius;
        cout << klausimas;
        cin >> skaicius;

        if (skaicius == "-1")
            return -1; // Grąžina -1, jei vartotojas nori baigti įvestį

        try
        {
            int pazymys = stoi(skaicius);
            if (pazymys >= 0 && pazymys <= 10)
            {
                return pazymys;
            }
            else
            {
                cout << "Klaida: pazymys turi buti tarp 0 ir 10.\n";
            }
        }
        catch (const invalid_argument &)
        {
            cout << "Klaida: iveskite teisinga skaiciu.\n";
        }
    }
}

// Rūšiuoja studentus pagal pavardę, o jei pavardės vienodos - pagal vardą
void rusiuotiStudentusPagalPavarde(std::vector<Studentas> &studentai)
{
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
              {
                  if (a.getPavarde() == b.getPavarde())
                  {
                      return a.getVardas() < b.getVardas(); // Sort by `vardas` if `pavarde` is the same
                  }
                  return a.getPavarde() < b.getPavarde(); // Sort by `pavarde`
              });
}

// Rūšiuoja studentus pagal vardą, o jei vardai vienodos - pagal pavardę
void rusiuotiStudentusPagalVarda(std::vector<Studentas> &studentai)
{
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
              {
                  if (a.getVardas() == b.getVardas())
                  {
                      return a.getPavarde() < b.getPavarde(); // Sort by `pavarde` if `vardas` is the same
                  }
                  return a.getVardas() < b.getVardas(); // Sort by `vardas`
              });
}

// Rūšiuoja studentus pagal galutinį vidurkį nuo mažiausio iki didžiausio
void rusiuotiPagalVidurkiDidejanciai(std::vector<Studentas> &studentai)
{
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
              { return a.getGalutinisVidurkis() < b.getGalutinisVidurkis(); });
}

// Rūšiuoja studentus pagal galutinį vidurkį nuo didžiausio iki mažiausio
void rusiuotiPagalVidurkiMazejanciai(std::vector<Studentas> &studentai)
{
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
              { return a.getGalutinisVidurkis() > b.getGalutinisVidurkis(); });
}

// Skaičiuoja pažymių medianą
float skaiciuotiMediana(const std::vector<int> &pazymiai)
{
    if (pazymiai.empty())
        return 0;

    std::vector<int> tempPazymiai = pazymiai; // Create a copy to avoid modifying original
    size_t n = tempPazymiai.size();
    size_t middle = n / 2;

    if (n % 2 == 0)
    {
        std::nth_element(tempPazymiai.begin(), tempPazymiai.begin() + middle - 1, tempPazymiai.end());
        std::nth_element(tempPazymiai.begin() + middle - 1, tempPazymiai.begin() + middle, tempPazymiai.end());
        return (tempPazymiai[middle - 1] + tempPazymiai[middle]) / 2.0f;
    }
    else
    {
        std::nth_element(tempPazymiai.begin(), tempPazymiai.begin() + middle, tempPazymiai.end());
        return tempPazymiai[middle];
    }
}

// Skaičiuoja pažymių vidurkį
float skaiciuotiVidurki(const std::vector<int> &pazymiai)
{
    if (pazymiai.empty())
    {
        return 0.0f;
    }
    return std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0f) / pazymiai.size();
}

int generuotiSkaiciu(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}

// Generuoja atsitiktinį vardą arba pavardę
string generuotiVardaPavarde()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static const char raides[] = "abcdefghijklmnopqrstuvwxyz";
    std::uniform_int_distribution<int> raideDistrib(0, 25);
    string vardasPavarde(4, ' ');
    for (int i = 0; i < 4; ++i)
    {
        vardasPavarde[i] = raides[raideDistrib(gen)];
    }
    return vardasPavarde;
}

Studentas generuotiAtsitiktiniStudenta()
{
    Studentas studentas;

    // Set atsitiktinis vardas ir pavarde
    studentas.setVardas(generuotiVardaPavarde());
    studentas.setPavarde(generuotiVardaPavarde());

    // Pre-allocate space for pazymiai
    int pazymiuKiekis = generuotiSkaiciu(1, 20);
    std::vector<int> pazymiai;
    pazymiai.reserve(pazymiuKiekis);

    // Generuojami atsitiktiniai pažymiai
    for (int i = 0; i < pazymiuKiekis; i++)
    {
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
    studentas.setMediana(mediana);   // Set mediana

    // Apskaičiuojami galutiniai įvertinimai
    const double egzaminoBalas = 0.6 * egzaminoPazymys;
    const double vidurkioBalas = 0.4 * vidurkis;
    const double medianosBalas = 0.4 * mediana;

    studentas.setGalutinisVidurkis(vidurkioBalas + egzaminoBalas); // Set galutinis vidurkis
    studentas.setGalutineMediana(medianosBalas + egzaminoBalas);   // Set galutine mediana

    return studentas;
}

void generuotiAtsitiktiniusFailus()
{
    for (int i = 1; i <= 5; ++i)
    {
        int studentuKiekis = generuotiSkaiciu(1, 1000000);
        string failoPavadinimas = "src/txt_failai/studentai_random_" + to_string(i) + ".txt";
        generuotiStudentuFaila(studentuKiekis, failoPavadinimas);
        cout << "Sugeneruotas failas " << failoPavadinimas << " su " << studentuKiekis << " studentu.\n";
    }
}

void vykdytiVisusZingsnius()
{
    vector<int> studentuKiekiai = {1000000, 10000000};

    // Atidaryti CSV failą rašymui
    ofstream csvFile("performance_data.csv", std::ios::app);
    if (!csvFile.is_open())
    {
        throw runtime_error("Nepavyko atidaryti CSV failo");
    }

    // Įrašo CSV antraštę, jei failas tuščias
    csvFile.seekp(0, std::ios::end);
    if (csvFile.tellp() == 0)
    {
        csvFile << "Testavimo Laikas;Studentu Kiekis;Studentu generavimo laikas;Sugeneruotu duomenu skaitymo laikas;Rezultatu irasymo laikas;Rezultatu skaitymo laikas;Rezultatu skaidymo laikas;Skaidymo irasymas;Bendras Laikas\n";
    }

    for (int kiekis : studentuKiekiai)
    {
        cout << "Vykdomi zingsniai su " << kiekis << " studentu:\n";

        // Gauti dabartinį laiką
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        string timestamp = ss.str();

        // Generuoti studentų failą
        string studentuFailas = "src/txt_failai/studentai_" + to_string(kiekis) + ".txt";
        auto pradziaGeneravimo = std::chrono::high_resolution_clock::now();
        generuotiStudentuFaila(kiekis, studentuFailas);
        auto pabaigaGeneravimo = std::chrono::high_resolution_clock::now();
        auto trukmeGeneravimo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaGeneravimo - pradziaGeneravimo);
        cout << "Failo su " << kiekis << "studentais generavimas uztruko " << trukmeGeneravimo.count() << " ms.\n";

        // Skaitomas sugeneruotas failas, apskaičiuoja galutinius rezultatus ir išvedamas į rezultatų failą
        string rezultatuFailas = "src/txt_failai/rezultatai_" + to_string(kiekis) + ".txt";
        cout << "Skaitomi duomenys ir isvedami i " << rezultatuFailas << "...\n";
        long long trukmeSkaitymo, trukmeVidurkio, trukmeIrasymo;
        auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();
        skaitytiIrIsvestiDuomenis(studentuFailas, rezultatuFailas, trukmeSkaitymo, trukmeVidurkio, trukmeIrasymo);
        auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
        auto trukmeSkaitymoLaikas = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaSkaitymo - pradziaSkaitymo);

        cout << "Skaitymo laikas: " << trukmeSkaitymo << " ms.\n";
        cout << "Duomenu isvedimas i " << rezultatuFailas << " uztruko " << trukmeIrasymo << " ms.\n";

        // Rezultatų failo padalijimas į išlaikiusius ir neišlaikiusius
        string islaikeFailas = "src/txt_failai/rezultatai_" + to_string(kiekis) + "_islaike.txt";
        string neislaikeFailas = "src/txt_failai/rezultatai_" + to_string(kiekis) + "_neislaike.txt";
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

void ivestiDuomenisRanka(vector<Studentas> &studentai)
{
    int studentuKiekis;
    bool gerasPasirinkimas = false;

    cout << "Kiek studentu norite irasyti? ";

    // Studentų skaičiaus įvesties patvirtinimas
    while (!gerasPasirinkimas)
    {
        cin >> studentuKiekis;
        if (cin.fail() || studentuKiekis < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida: Ivestas neteisingas studentu skaicius. Prasome ivesti skaiciu didesni uz 0: ";
        }
        else
        {
            gerasPasirinkimas = true;
        }
    }
    studentai.resize(studentuKiekis);

    // Studentų duomenų įvedimas ir atminties adreso spausdinimas
    for (Studentas &studentas : studentai)
    {
        // Input student data
        std::cin >> studentas;

        // Output the entered data
        // std::cout << "Ivestas studentas:\n" << studentas << '\n';
        cout << "Studento vektoriaus objektas atmintyje saugomas adresu: " << &studentas << endl;
    }
}

void automatiskaiGeneruotiDuomenis(vector<Studentas> &studentai)
{
    int studentuKiekis;
    bool gerasPasirinkimas = false;

    cout << "Kiek studentu norite sugeneruoti? ";

    // Įvesties patvirtinimas
    while (!gerasPasirinkimas)
    {
        cin >> studentuKiekis;
        if (cin.fail() || studentuKiekis < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida: Ivestas neteisingas studentu skaicius. Prasome ivesti skaiciu didesni uz 0: ";
        }
        else
        {
            gerasPasirinkimas = true;
        }
    }

    // Sugeneruoti atsitiktinius studentus ir pridėti juos prie vektoriaus
    for (int i = 0; i < studentuKiekis; i++)
    {
        studentai.push_back(generuotiAtsitiktiniStudenta());
    }
}

void nuskaitytiDuomenisIsFailo(vector<Studentas> &studentai, long long &trukmeSkaitymo, long long &trukmeVidurkio)
{
    int failoPasirinkimas;
    bool gerasPasirinkimas = false;

    // Leisti vartotoją pasirinkti failą
    cout << "Pasirinkite faila (1. studentai10.txt, 2. studentai100.txt, 3. studentai10000.txt, 4. studentai100000.txt, 5. studentai1000000.txt, 6. studentai10_blog.txt, 7. tuscias.txt): ";

    // Įvesties patvirtinimas
    while (!gerasPasirinkimas)
    {
        cin >> failoPasirinkimas;
        if (cin.fail() || failoPasirinkimas < 1 || failoPasirinkimas > 7)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisingas pasirinkimas. Prasome ivesti skaiciu nuo 1 iki 7: ";
        }
        else
        {
            gerasPasirinkimas = true;
        }
    }

    string failoPavadinimas;
    switch (failoPasirinkimas)
    {
    case 1:
        failoPavadinimas = "src/txt_failai/studentai10.txt";
        break;
    case 2:
        failoPavadinimas = "src/txt_failai/studentai100.txt";
        break;
    case 3:
        failoPavadinimas = "src/txt_failai/studentai10000.txt";
        break;
    case 4:
        failoPavadinimas = "src/txt_failai/studentai100000.txt";
        break;
    case 5:
        failoPavadinimas = "src/txt_failai/studentai1000000.txt";
        break;
    case 6:
        failoPavadinimas = "src/txt_failai/studentai10_blog.txt";
        break;
    case 7:
        failoPavadinimas = "src/txt_failai/tuscias.txt";
        break;
    }

    skaitytiDuomenisIsFailo(failoPavadinimas, studentai, trukmeSkaitymo, trukmeVidurkio);

    cout << "Duomenys nuskaityti is " << failoPavadinimas << " per " << trukmeSkaitymo << " ms\n";
}

void skaiciuotiRezultatus(long long &trukmeSkaitymo, long long &trukmeVidurkio, long long &trukmeIrasymo)
{
    std::vector<std::string> studentuSkaicius = {
        "_1000", "_10000", "_100000", "_1000000", "_10000000",
        "1000", "10000", "100000", "1000000", "10000000"};

    std::cout << "Pasirinkite rezultatu faila:\n";
    std::cout << "Kodo generuoti duomenys\n1. studentai_1000.txt\n2. studentai_10000.txt\n3. studentai_100000.txt\n4. studentai_1000000.txt\n5. studentai_10000000.txt\n";
    std::cout << "Pavyzdiniai duomenys\n6. studentai1000.txt\n7. studentai10000.txt\n8. studentai100000.txt\n9. studentai1000000.txt\n10. studentai10000000.txt\n";
    std::cout << "Jusu pasirinkimas: ";

    // Įvesties patikrinimas
    int failoPasirinkimas;
    std::cin >> failoPasirinkimas;
    if (failoPasirinkimas < 1 || failoPasirinkimas > 10)
    {
        throw std::runtime_error("Neteisingas failo pasirinkimas.");
    }

    // Generuoti failų pavadinimus pagal pasirinkimą
    std::string duomenuFailas = "src/txt_failai/studentai" + studentuSkaicius[failoPasirinkimas - 1] + ".txt";
    std::string isvestiesFailoPavadinimas = "src/txt_failai/rezultatai" + studentuSkaicius[failoPasirinkimas - 1] + ".txt";

    skaitytiIrIsvestiDuomenis(duomenuFailas, isvestiesFailoPavadinimas, trukmeSkaitymo, trukmeVidurkio, trukmeIrasymo);
    std::cout << "Duomenys nuskaityti is " << duomenuFailas
              << " per " << trukmeSkaitymo << "ms ir isvesti i "
              << isvestiesFailoPavadinimas << " per " << trukmeIrasymo << " ms.\n";
}

void rusiuotiRezultatus(long long &trukmeRezultatuSkaitymo, long long &trukmeRezultatuSkaidymas, long long &trukmeSkaidymoIrasymas)
{
    vector<string> studentuSkaicius = {"_1000", "_10000", "_100000", "_1000000", "_10000000", "1000", "10000", "100000", "1000000", "10000000"};

    cout << "Pasirinkite rezultatu faila:\n";
    cout << "Kodo generuoti duomenys\n1. rezultatai_1000.txt\n2. rezultatai_10000.txt\n3. rezultatai_100000.txt\n4. rezultatai_1000000.txt\n5. rezultatai_10000000.txt\n";
    cout << "Pavyzdiniai duomenys\n6. rezultatai1000.txt\n7. rezultatai10000.txt\n8. rezultatai100000.txt\n9. rezultatai1000000.txt\n10. rezultatai10000000.txt\n";
    cout << "Jusu pasirinkimas: ";

    // Įvesties patikrinimas
    int failoPasirinkimas;
    cin >> failoPasirinkimas;
    if (failoPasirinkimas < 1 || failoPasirinkimas > 10)
    {
        throw runtime_error("Neteisingas failo pasirinkimas.");
    }

    // Generuoti failų pavadinimus pagal pasirinkimą
    string duomenuFailas = "src/txt_failai/rezultatai" + studentuSkaicius[failoPasirinkimas - 1] + ".txt";
    string islaikiusiuFailoPavadinimas = "src/txt_failai/rezultatai" + studentuSkaicius[failoPasirinkimas - 1] + "_islaike.txt";
    string neislaikiusiuFailoPavadinimas = "src/txt_failai/rezultatai" + studentuSkaicius[failoPasirinkimas - 1] + "_neislaike.txt";

    padalintiRezultatuFaila(duomenuFailas, islaikiusiuFailoPavadinimas, neislaikiusiuFailoPavadinimas, trukmeRezultatuSkaitymo, trukmeRezultatuSkaidymas, trukmeSkaidymoIrasymas);
    cout << "Rezultatu failas padalintas i " << islaikiusiuFailoPavadinimas << " ir " << neislaikiusiuFailoPavadinimas << '\n';
}

void vykdytiKeliskart(int &kartai)
{
    bool validInput = false;

    // Įvesties patikrinimas
    while (!validInput)
    {
        cout << "Kiek kartu norite paleisti funkcija 'vykdytiVisusZingsnius'? ";
        cin >> kartai;

        if (cin.fail() || kartai <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisingas skaicius. Prasome ivesti teigiama skaiciu.\n";
        }
        else
        {
            validInput = true;
        }
    }

    // Vykdo visus žingsnius i kartų
    for (int i = 0; i < kartai; i++)
    {
        cout << "Vykdoma " << i + 1 << " karta:\n";
        vykdytiVisusZingsnius();
    }
}
