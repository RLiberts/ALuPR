/**
Ričards Nils Liberts, rl25036
20.04.2026.

Ar faila komponenti tiek saprasts fiksēta garuma ieraksts.
H9. Doti divi faili bināri f1 un f2, kuru komponentes ir
patvaļīgas simbolu virknes (komponentes sakārtotas alfabētiski).
Uzrakstīt programmu, kas apvieno failus f1 un f2 failā f3 tā, lai
arī f3 komponentes būtu sakārtotas (failā f3 nedrīkst parādīties
divas komponentes ar vienādu vērtību). Programmu veidot tā, lai
pilns faila saturs netiktu ielādēts operatīvajā atmiņā.
Uzrakstīt arī palīgprogrammas, kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.
**/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//Definējam fiksēta garuma ierakstu
struct Ieraksts {
    char teksts[50];
};

//Funkciju prototipi
void izveidotFailus();
void ievaditFailu(const char* failaVards);
void drukatFailu(const char* failaVards);
void apvienotFailus(const char* faila1Vards, const char* faila2Vards, const char* faila3Vards);

/**
void izveidotFailus();

void izveidotFailus() - Palīgprogramma, kas izveido divus binārus failus f1.bin un f2.bin
ar sakārtotām simbolu virknēm.
**/
void izveidotFailus() {
    ofstream f1("f1.bin",ios::binary);
    ofstream f2("f2.bin",ios::binary);

    Ieraksts dati1[]={"abols", "citrons", "kalis"};
    Ieraksts dati2[]={"banans", "citrons", "datele", "zemene"};

    for (int i=0; i< 3; i++) f1.write((char*)&dati1[i], sizeof(Ieraksts));
    for (int i=0; i< 4; i++) f2.write((char*)&dati2[i], sizeof(Ieraksts));

    f1.close();
    f2.close();
    cout<<"Faili f1.bin un f2.bin jau doti."<<endl;
}

/**
void ievaditFailu(const char* failaVards);

void ievaditFailu(failaVards) - Ļauj lietotājam manuāli ievadīt ierakstus binārajā failā failaVards.
**/
void ievaditFailu(const char* failaVards) {
    ofstream f(failaVards,ios::binary);
    if(!f){
    cout<<"Nevar atvērt failu"<< failaVards<<endl;
    return;}
    int skaits;
    Ieraksts temp;

    cout<<"Ievade failam "<<failaVards<<endl;
    cout<<"Cik ierakstus ievadisi failā "<<failaVards<<"?";
    cin>>skaits;

    for (int i=0; i<skaits; i++) {
        cout<<i+1<<". ieraksts (ievadi tekstu): ";
        cin>>temp.teksts; // Lasām vienu vārdu
        f.write((char*)&temp, sizeof(Ieraksts));
    }

    f.close();
    cout <<"Fails "<<failaVards<<" saglabats."<<endl;
}

/**
void drukatFailu(const char* failaVards)

void drukatFailu(failaVards) - Palīgprogramma, kas nolasa bināro failu failaVards pa vienam ierakstam
un izvada tā saturu ekrānā.
**/
void drukatFailu(const char* failaVards) {
    ifstream f(failaVards, ios::binary);
    if (!f) {
        cout<<"Nevar atvert failu "<<failaVards<<endl;
        return;
    }

    cout<<"Fails "<<failaVards<<": ";
    Ieraksts temp;
    while(f.read((char*)&temp, sizeof(Ieraksts))) {
        cout<<temp.teksts<<" ";
    }
    cout<<endl;
    f.close();
}

/**
void apvienotFailus(const char* faila1Vards, const char* faila2Vards, const char* faila3Vards);

void apvienotFailus(faila1Vards, faila2Vards, faila3Vards) - Apvieno divus alfabētiski sakārtotus binārus failus faila1Vards, faila2Vards vienā binārā failā faila3Vards,
izmetot dublikātus un neielādējot visu faila saturu atmiņā.
**/
void apvienotFailus(const char* faila1Vards, const char* faila2Vards, const char* faila3Vards) {
    ifstream f1(faila1Vards, ios::binary);
    ifstream f2(faila2Vards, ios::binary);
    ofstream f3(faila3Vards, ios::binary);

    if (!f1 || !f2 || !f3) {
        cout << "nevar atvērt failus apvienošanai." << endl;
        return;
    }

    Ieraksts r1, r2, pedejais;
    pedejais.teksts[0] = '\0'; // Pēdējais ierakstītais f3 (sākumā tukšs)
    bool ir1 = (bool)f1.read((char*)&r1, sizeof(Ieraksts));
    bool ir2 = (bool)f2.read((char*)&r2, sizeof(Ieraksts));

    while (ir1 && ir2) {
        if (strcmp(r1.teksts, r2.teksts) <= 0) {
            if (strcmp(r1.teksts, pedejais.teksts) != 0) {
                f3.write((char*)&r1, sizeof(Ieraksts));
                strcpy(pedejais.teksts, r1.teksts);
            }
            ir1 = (bool)f1.read((char*)&r1, sizeof(Ieraksts));
        } else {
            if (strcmp(r2.teksts, pedejais.teksts) != 0) {
                f3.write((char*)&r2, sizeof(Ieraksts));
                strcpy(pedejais.teksts, r2.teksts);
            }
            ir2 = (bool)f2.read((char*)&r2, sizeof(Ieraksts));
        }
    }

    // Pieraksta atlikušos f1 ierakstus
    while (ir1) {
        if (strcmp(r1.teksts, pedejais.teksts) != 0) {
            f3.write((char*)&r1, sizeof(Ieraksts));
            strcpy(pedejais.teksts, r1.teksts);
        }
        ir1 = (bool)f1.read((char*)&r1, sizeof(Ieraksts));
    }

    // Pieraksta atlikušos f2 ierakstus
    while (ir2) {
        if (strcmp(r2.teksts, pedejais.teksts) != 0) {
            f3.write((char*)&r2, sizeof(Ieraksts));
            strcpy(pedejais.teksts, r2.teksts);
        }
        ir2 = (bool)f2.read((char*)&r2, sizeof(Ieraksts));
    }

    f1.close(); f2.close(); f3.close();
    cout << "Apvienošana pabeigta." << endl;
}

int main() {
    //izveidotFailus();
    //drukatFailu("f1.bin");
    //drukatFailu("f2.bin");


    cout << "Izveido failu f1.bin (Ievadi datus alfabeta seciba!)" << endl;
    ievaditFailu("f1.bin");

    cout << "Izveido failu f2.bin (Ievadi datus alfabeta seciba!)" << endl;
    ievaditFailu("f2.bin");

    cout << "Ievadito failu saturs" << endl;
    drukatFailu("f1.bin");
    drukatFailu("f2.bin");

    cout<<"Apvienosana" << endl;
    apvienotFailus("f1.bin", "f2.bin", "f3.bin");

    cout<<"Rezultats:" << endl;
    drukatFailu("f3.bin");
    return 0;
}


/******************************************
Ievads (failu saturs)                          Vēlamā reakcija (f3.bin saturs)       Rezultāts
----------------------------------------------------------------------------------------------
f1: abols, citrons                             abols, banans, citrons, datele           +
f2: banans, datele

f1: abols, citrons, kalis                      abols, banans, citrons, datele,          +
f2: banans, citrons, datele, zemene            kalis, zemene

f1: abols, banans                              abols, banans                            +
f2: (tukšs fails)

f1: (tukšs fails)                                                                       +
f2: (tukšs fails)

f1: a, b, c                                    a, b, c, d, e, f                         +
f2: d, e, f

f1: citrons                                    citrons                                  +
f2: citrons

f1: b, d                                       a, b, c, d                               +
f2: a, c
*******************************************/
