/**
GG
G9. Uzrakstīt funkciju, kas pārbauda,
vai sarakstā ir  vismaz divi elementi ar vienādām vērtībām.

Ričards Nils Liberts, rl25036
20.05.2026.
**/
#include <iostream>
#include "func.h"
using namespace std;

int main() {
int ok;
do{
    elem* first = NULL, *last = NULL;
    int n, num;
    cout << "Ievadi elementu skaitu: ";
    cin >> n;

    try{
        if(n<2){
            throw 1;
        }

        cout << "Ievadi elementus: ";
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            pievienot(first, last, num);
        }

        cout << "Saraksts: ";
        print(first);

        if(irDivi(first)) {
            cout << "Sarakstā ir vismaz divi elementi ar vienādām vērtībām." << endl;
        } else {
            cout << "Sarakstā nav divu elementu ar vienādām vērtībām." << endl;
        };
        atbrivo(first);
        cout << "Saraksts pēc atbrīvošanas: ";
        print(first);
    }catch(int e){
        cout<<"Error: "<<e<<endl<<"Elementu skaitam jābūt vismaz 2."<<endl;
    }
    cout << "Vai turpināt (1) vai beigt (0)? ";
    cin >> ok;
}while(ok != 0);
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
n=-1                  Kļūda. Elementu skaitam jābūt pozitīvam  +
n=2: 4 4             JĀ (abi vienādi)                         +
n=2: 4 5             NĒ (abi atšķirīgi)                       +
*******************************************/
