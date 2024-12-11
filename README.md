# Studentų pažymių skaičiuoklė

## Aprašymas

Ši programa skirta studentų galutinio įvertinimo (vidurkio ir medianos pagrindu) apskaičiavimui ir duomenų apdorojimui. Programa leidžia:

1. Rankiniu būdu įvesti studentų duomenis.
2. Automatiškai generuoti studentų duomenis.
3. Nuskaityti duomenis iš failo ir juos apdoroti.
4. Generuoti didelius studentų sąrašų failus.
5. Rūšiuoti studentus į dvi kategorijas pagal galutinį balą.
6. Atlikti programos veikimo spartos analizę.

## Funkcionalumas

- Skaičiuoja galutinį studento įvertinimą pagal pažymių vidurkį arba medianą ir egzamino pažymį.
- Leidžia pasirinkti duomenų įvedimo būdą: rankinis įvedimas, automatinė duomenų generacija arba duomenų nuskaitymas iš failo.
- Duomenų rūšiavimas pagal studentų pavardes ir vardus.
- Generuoja penkis atsitiktinius studentų sąrašų failus (1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų).
- Rūšiuoja studentus į dvi kategorijas: "neišlaikiusius" (galutinis balas < 5.0) ir "išlaikiusius" (galutinis balas >= 5.0).
- Išveda surūšiuotus studentus į du atskirus failus.
- Matuoja programos veikimo spartą, įskaitant failų kūrimą, duomenų nuskaitymą, rūšiavimą ir išvedimą.

## Reikalavimai

- C++11 arba naujesnė versija.
- Standartinė šablonų biblioteka (STL).

## Naudojimas

0. Susikompiliuokite programą arba atsisiųskite sukompiliuotą versiją iš Releases.

1. Paleidus programą, pirmiausia pasirinkite duomenų konteinerį:

   - `vector` – naudojant `std::vector` konteinerį.
   - `list` – naudojant `std::list` konteinerį.

2. Po konteinerio pasirinkimo, jums bus pateiktas meniu su aštuoniais pasirinkimais. Įveskite skaičių, atitinkantį norimą veiksmą, ir programa atliks atitinkamą funkciją.

   - 1. **Įvesti duomenis ranka** – leidžia vartotojui įvesti studentų vardus, pavardes ir pažymius rankiniu būdu.
   - 2. **Automatiškai generuoti duomenis** – sukuria studentų duomenis automatiškai.
   - 3. **Nuskaityti duomenis iš failo** – leidžia nuskaityti studentų informaciją iš iš anksto paruošto failo.
   - 4. **Sukurti atsitiktinių studentų failus** – sukuria atsitiktinius studentų failus, kuriuos galima panaudoti rezultatų analizei.
   - 5. **Suskaičiuoti rezultatus** – apskaičiuoja studentų galutinius rezultatus remiantis vidurkiu ir mediana.
   - 6. **Padalinti rezultatų failą į išlaikius ir neišlaikius** – skirsto studentų sąrašą į tuos, kurie išlaikė egzaminą ir tuos, kurie neišlaikė, įrašant rezultatus į atskirus failus.
   - 7. **Sugeneruoti 5 atsitiktinius failus** – automatiškai sukuria 5 failus su atsitiktiniais studentų duomenimis.
   - 8. **Vykdyti visus žingsnius visiems studentų kiekiams** – automatiškai atlieka visus aukščiau nurodytus veiksmus visiems nustatytiems studentų kiekiams, siekiant atlikti išsamią analizę.

3. Kiekvienas veiksmas gali reikalauti papildomų įvedimų arba sugeneruos reikiamus failus. Pvz., pasirinkus `3`, turėsite nurodyti failo pavadinimą, iš kurio norite nuskaityti duomenis.

# v0.1 versija

## 1. Duomenų įvedimas ir struktūrų naudojimas

- Programa naudoja struktūrą studentų duomenims saugoti. Namų darbų rezultatai saugomi `std::vector` konteineryje, kuris leidžia įvesti nežinomą rezultatų kiekį.

## 2. Galutinio balo skaičiavimas

- Galutinį balą galima skaičiuoti naudojant tiek vidurkį, tiek medianą. Abu rezultatai išvedami su dviem skaičiais po kablelio.

## 3. Atsitiktinių balų generavimas

- Pridėta funkcija, kuri gali automatiškai generuoti atsitiktinius namų darbų ir egzamino balus.

## 4. Kodo reorganizacija ir struktūrizavimas

- Programos kodas buvo refaktorizuotas – funkcijos ir struktūros perkelti į atskirus `.cpp` ir `.h` failus.
- Panaudotas išimčių valdymas (`exception handling`), kad būtų tvarkomi galimi įvedimo ar failo nuskaitymo klaidų atvejai.

## 5. GitHub versijų valdymas

- Programa buvo nuolat sinchronizuojama su GitHub sistema, sukuriant pradinę versiją (v.pradinė) ir atnaujintą versiją (v0.1) pagal iškeltus reikalavimus.

# v0.2 versija

## 1. Atsitiktinių studentų duomenų generavimas

- Generuoti penki atsitiktiniai studentų sąrašai su 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų.

## 2. Studentų rūšiavimas

- Studentai buvo suskirstyti į dvi kategorijas pagal jų galutinį balą:
  - **"Vargšiukai"**: studentai, kurių galutinis balas < 5.0.
  - **"Kietiakiai"**: studentai, kurių galutinis balas >= 5.0.
- Studentai buvo rūšiuojami pagal šį kriterijų ir išvedami į atskirus failus.

## 3. Failų kūrimas

- Failų kūrimo procesas buvo matuojamas ir analizuotas.

## 4. Spartumo analizė

- Matuota, kiek laiko užtruko atlikti šiuos žingsnius:
  - Duomenų nuskaitymas iš failų.
  - Studentų rūšiavimas į dvi grupes.
  - Surūšiuotų studentų išvedimas į naujus failus.
- Analizė buvo atlikta naudojant visus penkis skirtingo dydžio failus.

## 5. Programos optimizavimas

- Kodo našumui didinti buvo atliktos optimizacijos, siekiant sumažinti laiko sąnaudas dirbant su dideliais duomenų rinkiniais (iki 10 000 000 įrašų).

## 6. Testavimas

- Testavimas atliktas su visais penkiais sugeneruotais failais, ir pateikti kelių testų laikų vidurkiai, kad būtų patikrintas programos veikimo greitis skirtingo dydžio duomenų failams.

## 7. GitHub versijų valdymas

- Sukurta ir sinchronizuota v0.2 versija, kurioje buvo atlikti visi minėti pakeitimai ir patobulinimai.
- Programa buvo nuolat sinchronizuojama su GitHub, sukuriant atnaujintą šaką ir subrelizą.

# v0.3 versija

## Spartos analizė

Šioje versijoje (v0.3) atliktas testavimas, palyginant dviejų konteinerių `std::vector` ir `std::list` veikimo spartą.

### Pirmos sistemos parametrai

```
CPU: Intel i7-9750H 6C/12T 3.2 GHz
RAM: 1x32GB 2400MHz
HDD/SSD: Kingston SA2000M8500G, NVMe PCI, skaitymo greitis iki 2200 MB/s, įrašymo greitis iki 2000 MB/s.
```

### Testavimo rezultatai

#### Vector prieš List palyginimas

- 4 bandymų rezultatai

##### Studentų generavimo laikas (ms)

| Įrašų kiekis | std::vector | std::list | Skirtumas |
| ------------ | ----------- | --------- | --------- |
| 1,000        | 3.5         | 8         | 4.5       |
| 10,000       | 26.75       | 31.5      | 4.75      |
| 100,000      | 184.75      | 169.25    | -15.5     |
| 1,000,000    | 1803.75     | 1604.25   | -199.5    |
| 10,000,000   | 17392.75    | 17572.25  | 179.5     |

##### Sugeneruotu duomenu skaitymo laikas (ms)

| Įrašų kiekis | std::vector | std::list | Skirtumas |
| ------------ | ----------- | --------- | --------- |
| 1,000        | 11.25       | 25        | 13.75     |
| 10,000       | 31.5        | 44.25     | 12.75     |
| 100,000      | 211.75      | 306.75    | 95        |
| 1,000,000    | 2005.25     | 3212      | 1206.75   |
| 10,000,000   | 21035       | 35745.25  | 14710.25  |

##### Rezultatu irasymo laikas (ms)

| Įrašų kiekis | std::vector | std::list | Skirtumas |
| ------------ | ----------- | --------- | --------- |
| 1,000        | 2.75        | 4.25      | 1.5       |
| 10,000       | 22          | 24.75     | 2.75      |
| 100,000      | 197.5       | 204.5     | 7         |
| 1,000,000    | 1975.25     | 2090.25   | 115       |
| 10,000,000   | 20092       | 21063.5   | 971.5     |

##### Rezultatu skaitymo laikas (ms)

| Įrašų kiekis | std::vector | std::list | Skirtumas |
| ------------ | ----------- | --------- | --------- |
| 1,000        | 17.75       | 22        | 4.25      |
| 10,000       | 106         | 91.5      | -14.5     |
| 100,000      | 857.25      | 850       | -7.25     |
| 1,000,000    | 8315.25     | 8491.5    | 176.25    |
| 10,000,000   | 83565.75    | 87570.25  | 4004.5    |

##### Rezultatu skaidymo laikas (ms)

| Įrašų kiekis | std::vector | std::list | Skirtumas |
| ------------ | ----------- | --------- | --------- |
| 1,000        | 0           | 0         | 0         |
| 10,000       | 2.75        | 1.5       | -1.25     |
| 100,000      | 31.75       | 38.25     | 6.5       |
| 1,000,000    | 359.25      | 657       | 297.75    |
| 10,000,000   | 4385        | 10963.25  | 6578.25   |

##### Skaidymo irasymas (ms)

| Įrašų kiekis | std::vector | std::list | Skirtumas |
| ------------ | ----------- | --------- | --------- |
| 1,000        | 2.5         | 4.5       | 2         |
| 10,000       | 24.75       | 25.75     | 1         |
| 100,000      | 216.5       | 236.25    | 19.75     |
| 1,000,000    | 2182        | 2330      | 148       |
| 10,000,000   | 21501.25    | 23156     | 1654.75   |

![i7_9750_greitis.png](https://github.com/Friebay/ObjProg_Ver1/blob/v0.3/greicio_duomenys/i7_9750h_greiciai.png?raw=true)

### Antros sistemos parametrai

```
CPU: AMD Ryzen 9 3900X, 8C/12T, 3.9 GHz
RAM: 2x8 GB 3200 MHz
HDD/SSD: Patriot PCIe M.2 P300 512 GB, skaitymo greitis iki 1700 MB/s, įrašymo greitis iki 1100 MB/s
```

### Testavimo rezultatai

#### Vector prieš List palyginimas

- 3 bandymų rezultatai

##### Studentų generavimo laikas (ms)

| Įrašų kiekis | std::vector      | std::list        | Skirtumas        |
| ------------ | ---------------- | ---------------- | ---------------- |
| 1,000        | 1.66666666666667 | 1.66666666666667 | 0                |
| 10,000       | 13.3333333333333 | 15.3333333333333 | 2                |
| 100,000      | 131              | 135.666666666667 | 4.66666666666666 |
| 1,000,000    | 1282             | 1301.33333333333 | 19.3333333333333 |
| 10,000,000   | 13312            | 13408            | 96               |

##### Sugeneruotu duomenu skaitymo laikas (ms)

| Įrašų kiekis | std::vector      | std::list        | Skirtumas         |
| ------------ | ---------------- | ---------------- | ----------------- |
| 1,000        | 1                | 1.66666666666667 | 0.666666666666667 |
| 10,000       | 13               | 19.3333333333333 | 6.33333333333333s |
| 100,000      | 138.666666666667 | 192              | 53.3333333333333  |
| 1,000,000    | 1349.33333333333 | 2162             | 812.666666666667  |
| 10,000,000   | 14011.3333333333 | 20688.3333333333 | 6677              |

##### Rezultatu irasymo laikas (ms)

| Įrašų kiekis | std::vector      | std::list        | Skirtumas         |
| ------------ | ---------------- | ---------------- | ----------------- |
| 1,000        | 1                | 1.33333333333333 | 0.333333333333333 |
| 10,000       | 14.3333333333333 | 15.3333333333333 | 1                 |
| 100,000      | 142.666666666667 | 151              | 8.33333333333334  |
| 1,000,000    | 1457             | 1523.66666666667 | 66.6666666666667  |
| 10,000,000   | 14534.3333333333 | 15345.3333333333 | 811               |

##### Rezultatu skaitymo laikas (ms)

| Įrašų kiekis | std::vector      | std::list        | Skirtumas        |
| ------------ | ---------------- | ---------------- | ---------------- |
| 1,000        | 6.66666666666667 | 6.66666666666667 | 0                |
| 10,000       | 63               | 68.6666666666667 | 5.66666666666667 |
| 100,000      | 629              | 626              | -3               |
| 1,000,000    | 6270             | 6296             | 26               |
| 10,000,000   | 62649.6666666667 | 63260.6666666667 | 611              |

##### Rezultatu skaidymo laikas (ms)

| Įrašų kiekis | std::vector      | std::list        | Skirtumas        |
| ------------ | ---------------- | ---------------- | ---------------- |
| 1,000        | 0                | 0                | 0                |
| 10,000       | 1                | 1                | 0                |
| 100,000      | 17.6666666666667 | 19.3333333333333 | 1.66666666666666 |
| 1,000,000    | 219.333333333333 | 462.666666666667 | 243.333333333333 |
| 10,000,000   | 2723.33333333333 | 7969.66666666667 | 5246.33333333333 |

##### Skaidymo irasymas (ms)

| Įrašų kiekis | std::vector      | std::list        | Skirtumas         |
| ------------ | ---------------- | ---------------- | ----------------- |
| 1,000        | 1                | 1.33333333333333 | 0.333333333333333 |
| 10,000       | 16               | 16               | 0                 |
| 100,000      | 161              | 170              | 9                 |
| 1,000,000    | 1616.66666666667 | 1727.33333333333 | 110.666666666667  |
| 10,000,000   | 16331            | 17653.6666666667 | 1322.66666666667  |

![3900x_greiciai.png.png](https://github.com/Friebay/ObjProg_Ver1/blob/v0.3/greicio_duomenys/3900x_greiciai.png?raw=true)

### Išvados

Vektorius yra pranašesnis skaičiuojant medianas, vidurkius, o tai leidžia programai veikti 10-15% sparčiau.

# v1.0 versija

## Kompiliavimo failai

Projektui sukompiliuoti naudojami šie .cmd failai:

- `compile_gpp.cmd` – naudoja g++ kompiliatorių.
- `compile_cmake.cmd` – naudoja cmake kompiliatorių.

## Įdiegimo instrukcija

- Atsisiųskite jau sukompiliuotas programos versijas iš [Releases](https://github.com/Friebay/ObjProg_Ver1/releases) puslapio:

  - **GCC versija** sukompiliuota naudojant `g++`
  - **CMake versija** sukompiliuota naudojant `cmake`

- Jei norite sukompiliuoti patys, programos kataloge rasite šiuos `.cmd` failus:
  - **compile_gpp.cmd** – šį failą paleidus, programa bus sukompiliuota naudojant `g++`.
  - **compile_cmake.cmd** – paleidus šį failą, programa bus sukompiliuota naudojant `CMake`.

##### Pradiniai greičiai, prieš sprendimus

![pradiniai.png](https://github.com/Friebay/ObjProg_Ver1/blob/v1.0/greicio_duomenys/pradiniai.png?raw=true)

##### 1 sprendimas

![1sprendimas.png](https://github.com/Friebay/ObjProg_Ver1/blob/v1.0/greicio_duomenys/1sprendimas.png?raw=true)

##### 2 sprendimas

![2sprendimas.png](https://github.com/Friebay/ObjProg_Ver1/blob/v1.0/greicio_duomenys/2sprendimas.png?raw=true)

##### 3 sprendimas

![3sprendimas.png](https://github.com/Friebay/ObjProg_Ver1/blob/v1.0/greicio_duomenys/3sprendimas.png?raw=true)

# v1.1 versija

- Šioje versijoje buvo pridėta Studento klasė

## Klasė

### Vektorius, CMake, O1

- Failo dydis diske: 417 792 bytes
- Greitis:
  ![classO1.png](https://github.com/Friebay/ObjProg_Ver2/blob/v1.1/greicio_duomenys/classO1.png?raw=true)

### Vektorius, CMake, O2

- Failo dydis diske: 471 040 bytes
- Greitis:
  ![classO2.png](https://github.com/Friebay/ObjProg_Ver2/blob/v1.1/greicio_duomenys/classO2.png?raw=true)

### Vektorius, CMake, O3

- Failo dydis diske: 409 600 bytes
- Greitis:
  ![classO3.png](https://github.com/Friebay/ObjProg_Ver2/blob/v1.1/greicio_duomenys/classO3.png?raw=true)

## Struct

### Vektorius, CMake, O1

- Failo dydis diske: 417 792 bytes
- Greitis:
  ![structO1.png](https://github.com/Friebay/ObjProg_Ver2/blob/v1.1/greicio_duomenys/structO1.png?raw=true)

### Vektorius, CMake, O2

- Failo dydis diske: 462 848 bytes
- Greitis:
  ![structO2.png](https://github.com/Friebay/ObjProg_Ver2/blob/v1.1/greicio_duomenys/structO2.png?raw=true)

### Vektorius, CMake, O3

- Failo dydis diske: 524 288 bytes
- Greitis:
  ![structO3.png](https://github.com/Friebay/ObjProg_Ver2/blob/v1.1/greicio_duomenys/structO3.png?raw=true)

# v1.2 versija

## Naujos funkcijos

Šioje versijoje buvo pridėta:

- „Rule of Three“: užtikrina taisyklingą objektų kopijavimo ir naikinimo logiką.
- Įvesties/išvesties funkcijų perdengimas: pagerinta vartotojo įvesties tikrinimo ir išvesties formatavimo sistema.

## „Rule of Three“

„Rule of Three“ taikoma tvarkant „Studentas“ klasę. Ši taisyklė reikalauja:

- Destruktoriaus – atminties išvalymui.
- Kopijavimo konstruktoriaus – saugiam objektų kopijavimui.
- Priskyrimo operatoriaus – tvarkant priskyrimus.

„Studentas“ klasėje šios funkcijos užtikrina:

- Visi objektai tvarkingai sunaikinami, o jų atmintis išvaloma.
- Taisyklingas objektų kopijavimas, išvengiant atminties nutekėjimų ar neteisingo duomenų kopijavimo.

```C++
Studentas student1;
Studentas student2(student1); // Naudojamas kopijavimo konstruktorius
student2 = student1;          // Naudojamas priskyrimo operatorius
```

## Įvesties/išvesties perdengimas

1.  Įvestis:

- Apibrėžta funkcija **operator>>** ir pagalbinė funkcija **gautiPazymi** užtikrina, kad vartotojas įves teisingus duomenis. Sistema tikrina:

  - Ar pažymiai yra tarp 0 ir 10.
  - Ar egzaminų pažymiai yra sveiki skaičiai.

- Pavyzdys:
  ```C++
  Studentas student;
  std::cin >> student; // Įvedamas vardas, pavardė, pažymiai ir egzaminų rezultatai
  ```

2. Įvestis:
   - Funkcija operator<< užtikrina aiškiai suformatuotą išvestį, naudojant fiksuotą plotį bei tiksliai pateikiant rezultatus.
   - Pavyzdys:
     ```C++
     std::cout << student; // Atvaizduojami suformatuoti rezultatai
     ```

## Kompiliavimo failai

Projektui sukompiliuoti naudojami šie .cmd failai:

- compile_gpp.cmd – naudoja g++ kompiliatorių.
- compile_cmake.cmd – naudoja cmake kompiliatorių.

## Įdiegimo instrukcija

1. Atsisiųskite jau sukompiliuotas programos versijas iš Releases puslapio:
   - GCC versija sukompiliuota naudojant g++
   - CMake versija sukompiliuota naudojant cmake
2. Jei norite susikompiliuokite patys,

# v1.5 versija
 - Šioje versijoje programa patobulinta pridedant abstrakčią bazinę klasę Zmogus, kuri turi tik vardą ir pavardę.
 - Pridėtas kodas, kuris demonstruoja, kad bandant sukurti abstrakčios klases Zmogus objekta ivyksta klaida
```C++
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
```

# v2.0 versija
 - Šioje versijoje pridėta Doxygen dokumentacija, kurią galite peržiūrėti faile doxy_html/index.html
 - Pridėtas unit testų kodas aplankale project_root/tests, kuriame galima išbandyti Žmogaus ir Studento klases.