/*
Ričards Nils Liberts, rl25036

Izveidot programmu valodā C++,
izmantojot objektorientētās programmēšanas
līdzekļus un strukturējot programmu vismaz
trīs failos. Klases hederi obligāti novietot atsevišķā
hedera failā (program.h). Visas metodes realizēt ārpus
hedera faila – speciālā C++ failā (program.cpp).
Funkcija main ievietojama vēl citā C++ failā (main.cpp).
Klases dati pēc noklusēšanas ir slēpti (private), bet
metodes atklātas (public). Šīs programmas ietvaros NAV
obligāti jānodrošina tāda lietotāja saskarne, kāda tika
prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst
“cieti” iekodēt). Citas prasības sk. Laboratorijas darbu noteikumos.

D19. Izveidot klasi "Laiks" - Time, kurā tiek glabāti trīs
skaitļi - stunda, minūte, sekunde. Klasei izveidot šādas metodes:
(1) konstruktors, ar kuru tiek padotas sākotnējās vērtības,
(2) destruktors, kurš paziņo par objekta likvidēšanu,
(3) metode "Mainīt" - change ar trīs parametriem, kas uzstāda jaunās vērtības,
(4) metode "Drukāt" - print, kas izdrukā laiku, (5) metode "Distance" - distance
ar trīs parametriem - citu laika momentu, kas aprēķina un izdrukā attālumu starp
abiem laika momentiem gan sekundēs, gan minūtēs, gan apvienoti
(stundās, minūtēs un sekundēs).

Programma izveidota: 30.11.2025.
*/
#include <iostream>
#include "Lab4.h"
using namespace std;

int main(){
    Laiks laiks1(15,30,0);
    laiks1.Drukāt();
    laiks1.Distance(16,45,0);
    laiks1.Mainīt(17,30,05);
    laiks1.Drukāt();
    laiks1.Mainīt(1,1,1);
    laiks1.Drukāt();
    return 0;
}


/*************************Testa plāns***********************************************

Ievade                        Programmas vēlamā reakcija
Laiks laiks1(15,30,0);        Objekts izveidots.
laiks1.Drukāt();              15:30:00
laiks1.Distance(16,45,0);     Attālums starp abiem laika momentiem sekundēs:4500
                              Attālums starp abiem laika momentiem minūtēs:75
                              Attālums starp abiem laika momentiem (stundas:minūtes:sekundes): 01:15:00

laiks1.Mainīt(17,30,05);      Vērtības mainītas.
laiks1.Drukāt();              17:30:05
laiks1.Mainīt(1,1,1);         Vērtības mainītas.
laiks1.Drukāt();              01:01:01
                              Likvidēts objekts ar adresi 0xd9ba1ffd84
*************************************************************************************/
