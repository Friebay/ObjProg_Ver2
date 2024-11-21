#include "Vec_failo_apdorojimas.h"

void skaiciuotiIsFailo(Studentas& studentas, bool tinkamiPazymiai, vector<Studentas>& studentai) {
    if (tinkamiPazymiai && !studentas.pazymiai.empty()) {
        studentas.egzaminoPazymys = studentas.pazymiai.back();
        studentas.pazymiai.pop_back();

        studentas.vidurkis = skaiciuotiVidurki(studentas.pazymiai);
        studentas.mediana = skaiciuotiMediana(studentas.pazymiai);

        const double egzaminoBalas = 0.6 * studentas.egzaminoPazymys;
        const double vidurkioBalas = 0.4 * studentas.vidurkis;
        const double medianosBalas = 0.4 * studentas.mediana;

        studentas.galutinisVidurkis = vidurkioBalas + egzaminoBalas;
        studentas.galutineMediana = medianosBalas + egzaminoBalas;

        studentai.push_back(move(studentas));
    } else {
        cout << "Klaida: truksta pazymiu studentui " << studentas.vardas << " " << studentas.pavarde << "\n";
    }
}

void skaitytiDuomenisIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai, long long& trukmeSkaitymo, long long& trukmeVidurkio) {
    auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();

    ifstream failas(failoPavadinimas, std::ios::in | std::ios::binary);
    if (!failas) {
        throw runtime_error("Failo " + failoPavadinimas + " nera.");
    }

    string buffer;
    buffer.reserve(1048576); // Buferio dydis baitais

    // Praleidžia antraštę
    getline(failas, buffer);

    while (getline(failas, buffer)) {
        if (buffer.length() < 52) { // Minimalaus ilgio patikrinimas
            throw runtime_error("Netinkamas eilutes ilgis");
        }

        Studentas studentas;
        
        // Skaito vardą ir pavardę
        studentas.vardas = buffer.substr(0, 16);
        studentas.pavarde = buffer.substr(16, 32);

        // Funkcija ištrinti whitespace iš string
        auto trim = [](std::string &str) {
            // Ištrinti pradžioję esantį whitespace
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
            // Ištrinti pabaigoje esantį whitespace
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), str.end());
        };

        trim(studentas.pavarde);

        // Pažymiai prasideda nuo 52 simbolio
        size_t pozicija = 52;
        bool tinkamiPazymiai = true;
        
        while (pozicija < buffer.length()) {
            // Praleidžia whitespace
            while (pozicija < buffer.length() && isspace(buffer[pozicija])) pozicija++;
            if (pozicija >= buffer.length()) break;

            int grade = 0;
            bool tinkamas = true;
            
            // Patikrina ar skaičius
            if (isdigit(buffer[pozicija])) {
                while (pozicija < buffer.length() && isdigit(buffer[pozicija])) {
                    grade = grade * 10 + (buffer[pozicija] - '0');
                    pozicija++;
                }

                // Patikrina ar tarp 0 ir 10
                if (grade < 0 || grade > 10) {
                    tinkamas = false;
                }
            } else {
                // Jeigu ne skaičius:
                tinkamas = false; // Netinkamas
                pozicija++; // Eina į kitą poziciją
            }

            if (tinkamas) {
                studentas.pazymiai.push_back(grade);
            } else {
                tinkamiPazymiai = false;
                break;
            }
            
            // Praleidžia whitespace
            while (pozicija < buffer.length() && isspace(buffer[pozicija])) pozicija++;
        }

        // Paskaičiuoja rezultatus
        skaiciuotiIsFailo(studentas, tinkamiPazymiai, studentai);
    }

    auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
    trukmeSkaitymo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaSkaitymo - pradziaSkaitymo).count();
    trukmeVidurkio = 0;
}

void skaitytiIrIsvestiDuomenis(const string& ivestiesFailoPavadinimas, const string& irasymoFailoPavadinimas, long long& trukmeSkaitymo, long long& trukmeVidurkio, long long& trukmeIrasymo) {
    vector<Studentas> studentai;
    skaitytiDuomenisIsFailo(ivestiesFailoPavadinimas, studentai, trukmeSkaitymo, trukmeVidurkio);

    auto pradziaIrasimo = std::chrono::high_resolution_clock::now();
    
    // Naudoja stringstream buferiui
    ostringstream buffer;

    // Įrašo antraštę į buferį
    buffer << left << setw(16) << "Pavarde" 
           << setw(16) << "Vardas" 
           << setw(25) << "Galutinis Vidurkis" 
           << "Galutine Mediana\n";
    buffer << string(70, '-') << "\n";

    for (const auto& studentas : studentai) {
        buffer << left << setw(16) << studentas.pavarde
               << setw(16) << studentas.vardas
               << setw(25) << fixed << setprecision(2) << studentas.galutinisVidurkis
               << fixed << setprecision(2) << studentas.galutineMediana
               << "\n";
    }

    // Atidaro failą įrašymui
    ofstream irasymoFailas(irasymoFailoPavadinimas, std::ios::out | std::ios::binary);
    if (!irasymoFailas) {
        throw runtime_error("Nepavyko atidaryti isvesties failo " + irasymoFailoPavadinimas);
    }

    // Įrašo visą buferį vienu metu
    irasymoFailas << buffer.str();
    irasymoFailas.close();

    auto pabaigaIrasimo = std::chrono::high_resolution_clock::now();
    trukmeIrasymo = std::chrono::duration_cast<std::chrono::milliseconds>(pabaigaIrasimo - pradziaIrasimo).count();
}

void padalintiRezultatuFaila(const string& ivestiesFailoPavadinimas, 
                            const string& islaikiusiuFailoPavadinimas, 
                            const string& neislaikiusiuFailoPavadinimas, 
                            long long& laikasSkaitymo, 
                            long long& rusiavimoLaikas, 
                            long long& laikasRasymo) {
    auto pradziaSkaitymo = std::chrono::high_resolution_clock::now();
    
    // Open file with optimized flags
    ifstream ivestiesFailas(ivestiesFailoPavadinimas, 
                           std::ios::in | std::ios::binary | std::ios::ate);
    if (!ivestiesFailas) {
        throw runtime_error("Nepavyko atidaryti ivesties failo " + ivestiesFailoPavadinimas);
    }

    // Get file size and prepare string buffer
    const auto failoDydis = ivestiesFailas.tellg();
    string failoTurinys;
    failoTurinys.reserve(failoDydis);
    ivestiesFailas.seekg(0);
    
    // Read file directly into string
    failoTurinys.assign((std::istreambuf_iterator<char>(ivestiesFailas)),
                        std::istreambuf_iterator<char>());
    ivestiesFailas.close();

    ofstream islaikiusiuFailas(islaikiusiuFailoPavadinimas, ios::out | ios::binary);
    ofstream neislaikiusiuFailas(neislaikiusiuFailoPavadinimas, ios::out | ios::binary);
    if (!islaikiusiuFailas || !neislaikiusiuFailas) {
        throw runtime_error("Nepavyko atidaryti išvesties failų");
    }

    // Process content using std::string_view for better performance
    std::string_view content(failoTurinys);
    size_t pos = 0;
    size_t newline_pos;

    // Handle headers
    for (int i = 0; i < 2; ++i) {
        newline_pos = content.find('\n', pos);
        if (newline_pos == std::string_view::npos) break;
        
        std::string_view line = content.substr(pos, newline_pos - pos);
        islaikiusiuFailas << line << '\n';
        neislaikiusiuFailas << line << '\n';
        pos = newline_pos + 1;
    }

    // Estimate student count for better memory allocation
    size_t estimatedStudentCount = std::count(failoTurinys.begin() + pos, 
                                             failoTurinys.end(), '\n');
    
    vector<Studentas> studentai;
    vector<Studentas> vargsiukai;
    studentai.reserve(estimatedStudentCount);
    
    // Process student data
    while ((newline_pos = content.find('\n', pos)) != std::string_view::npos) {
        std::string_view line = content.substr(pos, newline_pos - pos);
        if (line.empty()) {
            pos = newline_pos + 1;
            continue;
        }
        
        Studentas student;
        size_t word_start = line.find_first_not_of(" \t");
        size_t word_end = line.find(' ', word_start);
        
        // Parse fields using std::string_view
        if (word_end != std::string_view::npos) {
            student.pavarde = string(line.substr(word_start, word_end - word_start));
            word_start = line.find_first_not_of(" \t", word_end);
            word_end = line.find(' ', word_start);
            
            if (word_end != std::string_view::npos) {
                student.vardas = string(line.substr(word_start, word_end - word_start));
                word_start = line.find_first_not_of(" \t", word_end);
                word_end = line.find(' ', word_start);
                
                if (word_end != std::string_view::npos) {
                    // Parse numbers
                    student.galutinisVidurkis = std::stof(string(line.substr(word_start, 
                                                          word_end - word_start)));
                    word_start = line.find_first_not_of(" \t", word_end);
                    student.galutineMediana = std::stof(string(line.substr(word_start)));
                    
                    studentai.push_back(student);
                }
            }
        }
        pos = newline_pos + 1;
    }

    auto pabaigaSkaitymo = std::chrono::high_resolution_clock::now();
    laikasSkaitymo = std::chrono::duration_cast<std::chrono::milliseconds>
                     (pabaigaSkaitymo - pradziaSkaitymo).count();
    cout << "Failo skaitymas uztruko " << laikasSkaitymo << " ms." << endl;

    auto pradetiRusiavima = std::chrono::high_resolution_clock::now();

    vargsiukai.reserve(studentai.size() / 2);
    
    // Use partition and remove_if together
    auto partition_point = std::partition(studentai.begin(), studentai.end(),
                           [](const Studentas& s) { return s.galutinisVidurkis >= 5.0f; });

    std::remove_copy_if(studentai.begin(), studentai.end(),
        std::back_inserter(vargsiukai),
        [](const Studentas& s) { return s.galutinisVidurkis >= 5.0f; });
    
    studentai.erase(partition_point, studentai.end());

    sort(studentai.begin(), studentai.end(),
         [](const Studentas& a, const Studentas& b) {
             return a.galutinisVidurkis > b.galutinisVidurkis;
         });
    
    sort(vargsiukai.begin(), vargsiukai.end(),
         [](const Studentas& a, const Studentas& b) {
             return a.galutinisVidurkis > b.galutinisVidurkis;
         });

    auto pabaigaRusiavimo = std::chrono::high_resolution_clock::now();
    rusiavimoLaikas = std::chrono::duration_cast<std::chrono::milliseconds>
                      (pabaigaRusiavimo - pradetiRusiavima).count();
    cout << "Rusiavimas uztruko " << rusiavimoLaikas << " ms." << endl;

    auto pradetiRasyma = std::chrono::high_resolution_clock::now();

    // Optimize file writing with buffered operations
    islaikiusiuFailas.rdbuf()->pubsetbuf(nullptr, 65536);  // 64KB buffer
    neislaikiusiuFailas.rdbuf()->pubsetbuf(nullptr, 65536);

    std::for_each(studentai.begin(), studentai.end(),
        [&islaikiusiuFailas](const Studentas& s) {
            islaikiusiuFailas << left << setw(15) << s.pavarde << " " 
                             << setw(15) << s.vardas << " " 
                             << setw(24) << s.galutinisVidurkis << " " 
                             << s.galutineMediana << "\n";
        });
    
    std::for_each(vargsiukai.begin(), vargsiukai.end(),
        [&neislaikiusiuFailas](const Studentas& s) {
            neislaikiusiuFailas << left << setw(15) << s.pavarde << " " 
                               << setw(15) << s.vardas << " " 
                               << setw(24) << s.galutinisVidurkis << " " 
                               << s.galutineMediana << "\n";
        });

    auto pabaigaRasymo = std::chrono::high_resolution_clock::now();
    laikasRasymo = std::chrono::duration_cast<std::chrono::milliseconds>
                   (pabaigaRasymo - pradetiRasyma).count();
    cout << "Rasymas uztruko " << laikasRasymo << " ms." << endl;

    islaikiusiuFailas.close();
    neislaikiusiuFailas.close();
}