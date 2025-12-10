//Lab4.h
/*
Ričards Nils Liberts, rl25036

Klasē "Laiks" tiek glabāti trīs
skaitļi - stunda, minūte, sekunde. Klasei izveidotas šādas metodes:
(1) konstruktors, ar kuru tiek padotas sākotnējās vērtības h, m, s,
(2) destruktors, kurš paziņo par objekta likvidēšanu,
(3) metode "Mainīt" ar trīs parametriem h, m, s, kas uzstāda jaunās vērtības,
(4) metode "Drukāt", kas izdrukā laiku,
(5) metode "Distance" ar trīs parametriem(h2, m2,s2) citu laika momentu, kas aprēķina un izdrukā attālumu starp
abiem laika momentiem gan sekundēs, gan minūtēs, gan apvienoti(stundās, minūtēs un sekundēs)
*/
class Laiks{
private:
    int h;
    int m;
    int s;
    void pārveide(int laiks);
public:
    Laiks(int h, int m, int s);             //(1)
    ~Laiks();                               //(2)
    void Mainīt(int h, int m, int s);       //(3)
    void Drukāt();                          //(4)
    void Distance(int h2, int m2, int s2);  //(5)
};
