/**
G9. Uzrakstīt funkciju, kas pārbauda,
vai sarakstā ir  vismaz divi elementi ar vienādām vērtībām.

Ričards Nils Liberts, rl25036
13.03.2026.
**/
#include <list>
#include <iostream>
using namespace std;

/**
bool irDivi(list<int>& aa);
Funkcija irDivi(aa) - pārbauda, vai STL sarakstā aa ir vismaz
divi elementi ar vienādām vērtībām. Katrs elements tiek salīdzināts ar
visiem nākošajiem, izmantojot iteratorus.
Atgriež true, ja atrasts vismaz viens vienāds pāris, citādi false.
**/
bool irDivi(list<int> &aa) {
    for (auto i = aa.begin(); i != aa.end(); ++i) {
        for (auto j = next(i); j != aa.end(); ++j) {
            if (*i == *j) return true;
        };
    };
    return false;
}

int main(){
    int ok;
    do {
        list<int> aa;
        int n, num;
        cout << "Ievadi elementu skaitu: ";
        cin >> n;
        if (n < 2) {
            cout << "Sarakstam jābūt vismaz 2 elementiem." << endl;
        } else {
            cout << "Ievadi elementus: ";
            for (int i = 0; i < n; i++) {
                cin >> num;
                aa.push_back(num);
            };
        };

        cout << "Saraksts: ";
        for (auto &a : aa) {
            cout << a << " ";
        }
        cout << endl;

        if (irDivi(aa)) {
            cout << "Sarakstā ir vismaz divi elementi ar vienādām vērtībām." << endl;
        } else {
            cout << "Sarakstā nav divu elementu ar vienādām vērtībām." << endl;
        };

        cout << "Vai turpināt (1) vai beigt (0)? ";
        cin >> ok;
    }while (ok == 1);
    return 0;
}


/*******************************************
TESTA PLĀNS

Ievads              Vēlamā reakcija                        Rezultāts
-----------------------------------------------------------------------
n=5: 5 3 8 3 1       JĀ (3 atkārtojas)                        +
n=4: 10 20 30 40     NĒ (visi atšķirīgi)                      +
n=3: 7 7 7           JĀ (visi vienādi)                        +
n=1: 5               NĒ (viens elements, nevar būt pāris)     +
n=-1                 Elementu skaitam jābūt pozitīvam          +
n=2: 4 4             JĀ (abi vienādi)                         +
n=2: 4 5             NĒ (abi atšķirīgi)                       +
*******************************************/
