#include "func.h"
#include <iostream>
using namespace std;

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
