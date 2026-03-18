/**
G9. Uzrakstīt funkciju, kas pārbauda,
vai sarakstā ir  vismaz divi elementi ar vienādām vērtībām.

Ričards Nils Liberts, rl25036
16.03.2026.
 * */
#include <iostream>
using namespace std;

//glaba vertibu un noradi uz nakamo elementu
struct elem {
    int num;
    elem* next;
};

/**
void pievienot(elem*& first, elem*& last, int i);

Funkcija pievienot(first, last, i) - pievieno jaunu elementu ar
vērtību i saistītā saraksta beigās. Tukša saraksta gadījumā,
jaunais elements kļūst par pirmo un pēdējo,citādi, tas tiek piekabināts
pēdējam elementam.
**/
void pievienot(elem*& first, elem *& last, int num) {
    elem* p= new elem;
    p->num = num;
    p->next = NULL;

    if (first == NULL) {
        //saraksts tukss un abi norada uz jauno elementu
        first = last = p; 
    } else {
        //pieliek elementu saraksta beigam un jaunais klust par pedejo
        last->next = p;
        last = p;
    };
}


/**
void print(elem* first);

Funkcija print(first) - izdrukā visus saistītā saraksta elementus,
uz kura pirmo elementu norāda first. Elementi tiek drukāti vienā rindā,
atdalīti ar atstarpi.
**/
void print(elem* first) {
    for(elem* p = first; p != NULL; p = p->next) {
        cout << p->num << " ";
    }
    cout << endl;
}


/**
bool irDivi(elem* first);

Funkcija irDivi(first) - pārbauda, vai saistītajā sarakstā,
uz kura pirmo elementu norāda first, ir vismaz divi elementi ar vienādām
vērtībām. Katrs elements tiek salīdzināts ar visiem nākošajiem.
Atgriež true, ja atrasts vismaz viens vienāds pāris, citādi false.
**/
bool irDivi(elem* first) {
    for(elem* p = first; p != NULL; p = p->next) {
        for(elem* q = p->next; q != NULL; q = q->next) {
            if (p->num == q->num) {
                return true;
            }
        }
    }
    return false;
}


/**
void atbrivo(elem*& first);
Funkcija atbrivo(first) - atbrīvo visu saistītajam sarakstam
izdalīto dinamisko atmiņu, izdzēšot katru elementu pa vienam.
Pēc izpildes first == NULL.
**/
void atbrivo(elem *&first) {
    elem *p = first;
    while (p != NULL) {
        first = first->next;
        delete p;
        p = first;
    };
}


int main() {
int ok;
do{
    elem* first = NULL, *last = NULL;
    int n, num;
    cout << "Ievadi elementu skaitu: ";
    cin >> n;
    if (n < 2) {
        cout << "Sarakstam jābūt vismaz 2 elementiem." << endl;
    }else {
        cout << "Ievadi elementus: ";   
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            pievienot(first, last, num);    
        }
    };

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
    cout << "Vai vēlaties turpināt? (1-jā, 0-nē): ";
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
