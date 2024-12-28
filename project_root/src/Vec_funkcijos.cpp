// Pagalbinės funkcijos
#include "../include/Vec_funkcijos.h"
#include "../include/Vec_funkcijos_papildomos.h"
#include "../include/Vec_failo_apdorojimas.h"

// Pagrindinė vektoriaus programos funkcija
void Vec_programa()
{

    // Vėliau naudojami kintamieji
    int pasirinkimas;
    int failoPasirinkimas;
    int studentuKiekis;
    bool gerasPasirinkimas = false;

    // Meniu
    cout << "1. Ivesti duomenis ranka\n"
         << "2. Automatiskai generuoti duomenis\n"
         << "3. Nuskaityti duomenis is failo\n"
         << "4. Sukurti atsitiktiniu studentu failus\n"
         << "5. Suskaiciuoti rezultatus\n"
         << "6. Padalinti rezultatu faila i islaikius ir neislaikius\n"
         << "7. Sugeneruoti 5 atsitiktinius failus\n"
         << "8. Vykdyti visus zingsnius visiems studentu kiekiams\n"
         << "9. Abstrakti klases Zmogus, jos objektu kurimo neleidimo parodymas\n"
         << "Jusu pasirinkimas: ";

    // Vartotojo pasirinkimo tikrinimas
    while (!gerasPasirinkimas)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Iveskite pasirinkima (1-9): ";
        cin >> pasirinkimas;

        if (cin.fail() || pasirinkimas < 1 || pasirinkimas > 9)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisingas pasirinkimas. Prasome ivesti skaiciu nuo 1 iki 8.\n";
        }
        else
        {
            gerasPasirinkimas = true;
        }
    }

    vector<Studentas> studentai;
    try
    {
        long long trukmeSkaitymo = 0, trukmeVidurkio = 0, trukmeIrasymo = 0;
        switch (pasirinkimas)
        {
        case 1:
        {
            // Duomenų įvedimas ranka
            ivestiDuomenisRanka(studentai);
            break;
        }

        case 2:
        {
            // Automatinis duomenų generavimas
            automatiskaiGeneruotiDuomenis(studentai);
            break;
        }

        case 3:
        {
            // Duomenų nuskaitymas iš failo
            nuskaitytiDuomenisIsFailo(studentai, trukmeSkaitymo, trukmeVidurkio);
            break;
        }

        case 4:
        {
            // Atsitiktinių studentų failų kūrimas
            generuotiFaila();
            return;
        }
        case 5:
        {
            // Skaičiuoti rezultatus
            skaiciuotiRezultatus(trukmeSkaitymo, trukmeVidurkio, trukmeIrasymo);
            break;
        }
        case 6:
        {
            // Rūšiuoti į išlaikiusius ir neišlaikiusius
            long long trukmeRezultatuSkaitymo, trukmeRezultatuSkaidymas, trukmeSkaidymoIrasymas;
            rusiuotiRezultatus(trukmeRezultatuSkaitymo, trukmeRezultatuSkaidymas, trukmeSkaidymoIrasymas);
            break;
        }
        case 7:
        {
            // Generuoti 5 atsitiktinio dydžio studentų failus
            generuotiAtsitiktiniusFailus();
            return;
        }

        case 8:
        {
            // Kelius kartus sukamas kodas, kad sužinoti kiek laiko užtrunka kodas
            int kartai;
            vykdytiKeliskart(kartai);

            return;
        }
        case 9:
        {
            // Abstralčioji klasė Zmogus
            std::cout << "Parodysime, kad bandant sukurti abstrakcios klases Zmogus objekta ivyksta klaida:\n";

            try
            {
                // Zmogus *h = new Zmogus("John", "Doe");
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Caught an error: " << e.what() << "\n";
            }

            // Parodysime, kad 5manoma sukurti išvestinės klasės objektus
            Studentas studentas("Jonas", "Jonaitis", {10, 9, 8}, 9);
            std::cout << "Sekmingai sukurtas isvestines klases 'Studentas' objektas:\n";
            std::cout << "Vardas: " << studentas.getVardas() << ", Pavarde: " << studentas.getPavarde() << "\n";

            return;
        }
        }
        if (pasirinkimas != 5 && pasirinkimas != 6)
        {
            if (studentai.empty())
            {
                throw runtime_error("Nera studentu duomenu.");
            }
            else
            {
                cout << "Studentai: " << studentai.size() << endl;
            }

            int pasirinkimasRik;
            bool validInput = false;

            while (!validInput)
            {
                cout << "Jeigu norite rusiuoti pagal varda - 1, jeigu pagal pavarde - 2, pagal vidurki didejanciai - 3, pagal vidurki mazejanciai - 4: ";
                cin >> pasirinkimasRik;

                if (cin.fail() || (pasirinkimasRik < 1 || pasirinkimasRik > 4))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Blogas pasirinkimas. Prasome ivesti 1, 2, 3 arba 4.\n";
                }
                else
                {
                    validInput = true;
                }
            }

            // Rūšiuoja studentus
            if (pasirinkimasRik == 1)
            {
                rusiuotiStudentusPagalVarda(studentai);
            }
            else if (pasirinkimasRik == 2)
            {
                rusiuotiStudentusPagalPavarde(studentai);
            }
            else if (pasirinkimasRik == 3)
            {
                rusiuotiPagalVidurkiDidejanciai(studentai);
            }
            else if (pasirinkimasRik == 4)
            {
                rusiuotiPagalVidurkiMazejanciai(studentai);
            }
            else
            {
                cout << "Blogas pasirinkimas. Prasome ivesti 1, 2, 3 arba 4.\n";
            }

            // Spausdina rezultatus
            std::cout << std::left << std::setw(16) << "Pavarde"
                      << std::setw(16) << "Vardas"
                      << std::setw(25) << "Galutinis Vidurkis"
                      << " / " << "Galutine Mediana\n";
            std::cout << "-------------------------------------------------------------------------\n";
            std::cout << std::fixed << std::setprecision(2);

            for (const Studentas &studentas : studentai)
            {
                std::cout << studentas << '\n';
            }
        }
    }
    catch (const exception &e)
    {
        cout << "Vec_funkcijos.cpp faile ivyko klaida: " << e.what() << '\n';
    }
}