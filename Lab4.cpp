//Ričards Nils Liberts, rl25036
#include <iostream>
#include "Lab4.h"
using namespace std;

void Laiks::pārveide(int laiks){ //Laika pārveide standarta formātam hh:mm:ss
    if (laiks == 0) {
        cout << "00";
    } else if (laiks < 10) {
        cout << "0" << laiks;
    } else {
        cout << laiks;
    }
}
Laiks::Laiks(int stundas, int minutes, int sekundes){ //laika objekta izveide
    h=stundas;
    m=minutes;
    s=sekundes;
    cout << "Objekts izveidots." << endl;
}
Laiks::~Laiks(){
  cout << "Likvidēts objekts ar adresi " << this << endl;
}
void Laiks::Mainīt(int stundas, int minutes, int sekundes){ //nomaina laika vērtības
    h=stundas;
    m=minutes;
    s=sekundes;
    cout << "Vērtības mainītas." << endl;
}
void Laiks::Drukāt(){ //izdrukā laiku standarta formātā hh:mm:ss
    pārveide(h);
    cout<<":";
    pārveide(m);
    cout<<":";
    pārveide(s);
    cout<<endl;
}
void Laiks::Distance(int h2, int m2, int s2){ //atgriež kā rezultātu starpības moduli starp diviem laika momentiem
    int laiks1=h*3600+m*60+s;
    int laiks2=h2*3600+m2*60+s2;
    int distance=laiks2-laiks1;
    if(distance<0) distance=-distance;
    cout<<"Attālums starp abiem laika momentiem sekundēs:"<<distance<<endl;
    cout<<"Attālums starp abiem laika momentiem minūtēs:"<<distance/60.0<<endl;
    int distH=distance/3600;
    int atlik= distance%3600;
    int distM=atlik/60;
    int distS=atlik%60;
    cout<<"Attālums starp abiem laika momentiem (stundas:minūtes:sekundes): ";
    pārveide(distH);
    cout<<":";
    pārveide(distM);
    cout<<":";
    pārveide(distS);
    cout<<endl;

}
