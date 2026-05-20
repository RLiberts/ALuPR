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
void pievienot(elem*& first, elem *& last, int num);


/**
void print(elem* first);

Funkcija print(first) - izdrukā visus saistītā saraksta elementus,
uz kura pirmo elementu norāda first. Elementi tiek drukāti vienā rindā,
atdalīti ar atstarpi.
**/
void print(elem* first);


/**
bool irDivi(elem* first);

Funkcija irDivi(first) - pārbauda, vai saistītajā sarakstā,
uz kura pirmo elementu norāda first, ir vismaz divi elementi ar vienādām
vērtībām. Katrs elements tiek salīdzināts ar visiem nākošajiem.
Atgriež true, ja atrasts vismaz viens vienāds pāris, citādi false.
**/
bool irDivi(elem* first);


/**
void atbrivo(elem*& first);
Funkcija atbrivo(first) - atbrīvo visu saistītajam sarakstam
izdalīto dinamisko atmiņu, izdzēšot katru elementu pa vienam.
Pēc izpildes first == NULL.
**/
void atbrivo(elem *&first);


