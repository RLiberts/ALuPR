#include <iostream>
#include "func.h"
using namespace std;

/**
elem* veidot(elem*& last, int skaitli[], int n);
Funkcija veidot(last, skaitli[], n) - pārveido parasto masīvu 'skaitli' 
ar 'n' elementiem par dinamisku saistīto sarakstu. Katrs masīva elements
tiek pievienots saraksta beigās, izmantojot funkciju pievienot(). Atgriež sākuma rādītāju 
uz izveidoto sarakstu. Atgriež norādi uz saraksta pirmo elementu.
**/
elem* veidot(elem*& last,int skaitli[], int n){
    elem* first=NULL;
    last=NULL;
    for(int i=0;i<n;i++){
        pievienot(first,last,skaitli[i]);
    }
    return first;
}

bool test_a(){
    elem* last;
    int a[]={5,3,8,3,1};
    elem* first=veidot(last,a,5);
    bool rez=irDivi(first);
    atbrivo(first);
    return rez==true;
}
bool test_b(){
    elem* last;
    int a[]={1,2,3,4};
    elem* first=veidot(last,a,4);
    bool rez=irDivi(first);
    atbrivo(first);
    return rez==false;
}
bool test_c(){
    elem* last;
    int a[]={7,7,7};
    elem* first=veidot(last,a,3);
    bool rez=irDivi(first);
    atbrivo(first);
    return rez==true;
}
bool test_d() {
    elem* first = NULL;
    bool rez = irDivi(first);
    return rez == false;
}
bool test_e() {
    elem* last;
    int a[] = {4, 4};
    elem* first = veidot(last,a, 2);
    bool rez = irDivi(first);
    atbrivo(first);
    return rez == true;
}
bool test_f() {
    elem* last;
    int a[] = {5, 4};
    elem* first = veidot(last,a, 2);
    bool rez = irDivi(first);
    atbrivo(first);
    return rez == false;
}
int main() {
    // Izvada 1 = tests nokārtots, 0 = tests neizturēts
    cout<<"test_a:"<<test_a()<<endl;
    cout<<"test_b:"<<test_b()<<endl;
    cout<<"test_c:"<<test_c()<<endl;
    cout<<"test_d: "<<test_d()<<endl;
    cout<<"test_e:"<< test_e()<<endl;
    cout<<"test_f:"<< test_f()<<endl;
    return 0;
}
