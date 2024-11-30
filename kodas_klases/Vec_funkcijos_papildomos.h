#ifndef VEC_FUNKCIJOS_PAPILDOMOS_H
#define VEC_FUNKCIJOS_PAPILDOMOS_H

#include "Vec_Biblioteka.h"
#include "Vec_funkcijos.h"

void rusiuotiStudentusPagalPavarde(std::vector<Studentas> &studentai);
void rusiuotiStudentusPagalVarda(std::vector<Studentas> &studentai);
void rusiuotiPagalVidurkiDidejanciai(std::vector<Studentas> &studentai);
void rusiuotiPagalVidurkiMazejanciai(std::vector<Studentas> &studentai);
float skaiciuotiMediana(vector<int> &pazymiai);
float skaiciuotiVidurki(vector<int> &pazymiai);
int generuotiSkaiciu(int min, int max);
string generuotiVardaPavarde();
Studentas generuotiAtsitiktiniStudenta();
void generuotiAtsitiktiniusFailus();
void vykdytiVisusZingsnius();
void vykdytiKeliskart(int &kartai);
void rusiuotiRezultatus(long long &trukmeRezultatuSkaitymo, long long &trukmeRezultatuSkaidymas, long long &trukmeSkaidymoIrasymas);
void ivestiDuomenisRanka(vector<Studentas> &studentai);
void automatiskaiGeneruotiDuomenis(vector<Studentas> &studentai);
void nuskaitytiDuomenisIsFailo(vector<Studentas> &studentai, long long &trukmeSkaitymo, long long &trukmeVidurkio);
void skaiciuotiRezultatus(long long &trukmeSkaitymo, long long &trukmeVidurkio, long long &trukmeIrasymo);

#endif