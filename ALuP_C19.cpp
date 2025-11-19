/****************************
Ričards Nils Liberts, rl25036
C19. Dots masīvs no veseliem nenegatīviem
skaitļiem A(n) Atrast tā elementa indeksu,
kuram pirms tā esošo skaitļu summa vismazāk
atšķiras no pēc tā esošo skaitļu summas.
Ja elementi ar šādu īpašību ir vairāki,
uzrādīt visus.
Programma izveidota: 18.11.2025.
*******************************/
#include <iostream>
using namespace std;

/*
int SummaPirms(int A[], int indekss);
Funkcija SummaPirms(A, indekss) -
atgriež kā rezultātu visu to masīva A elementu summu, kas atrodas
pirms elementa ar indeksu indekss.
*/
int SummaPirms(int A[], int indekss){
int summa=0;
for(int i=0; i<indekss; i++) summa +=A[i];
return summa;
}
/*
int SummaPec(int A[], int indekss);
Funkcija SummaPirms(A, indekss) -
atgriež kā rezultātu visu to masīva A elementu summu, kas atrodas
pēc elementa ar indeksu indekss.
*/
int SummaPec(int A[], int indekss, int n){
int summa=0;
for(int i=indekss+1; i<n; i++) summa +=A[i];
return summa;
}
/*
int ElementuIevade();
Funkcija ElementuIevade() -
pieprasa lietotājam ievadīt veselus nenegatīvus, pārbauda
atbilstību. Kļūdainā gadījumā pieprasa atkārtotu ievadi. Atgriež kā
rezultātu korekti ievadītu nenegatīvu veselu skaitli.
*/
int ElementuIevade(int i){
int skaitlis;
do{
cin>>skaitlis;
if(skaitlis<0) cout<< "Kļūdaina vērtība. Jāievada nenegatīvs skaitlis(skaitlis>=0.)"<<endl<<i+1<<".elements:";
}while(skaitlis<0);
return skaitlis;
}
/*
int Modulis(int x);
Funkcija Modulis(x) -
atgriež kā rezultātu  veselu skaitli
kā nenegatīvu.
*/
int Modulis(int x){
if(x<0) return -x;
return x;
}

int main(){
int ok;
do{
const int N=100; //deklerē konstantu masīva maksimālo garumu
int A[N], n;

//Lietotāja ievade masīva elementu skaitam.
do{
cout<<"Ievadiet masīva A izmēru n.(2<=n<=100):"<<endl;
cin>>n;
if(n<2||n>N) cout<<"Kļūdaina vērtība. Masīva izmēram jābut diapazonā no 2 līdz 100.";
}while(n<2||n>N);

//Katra masīva elementa ievade
cout<<"Ievadiet masīva A elementus. Nenegatīvus skaitļus"<<endl;
for(int i=0; i<n; i++){
cout<<i+1<<".elements:";
A[i]=ElementuIevade(i); //Izsauc funkciju korektai nenegatīva skaitļa ievadei.
}


int starpiba0 = Modulis(SummaPirms(A,0)-SummaPec(A,0,n)); //Aprēķina A[0] elementa summas pirms un pēc starpību
int starpiba; //Mainīgais pašreizējai starpībai.

//Cikls, lai atrastu minimālo starpību starp summu pirms un summu pēc elementa visā masīvā
for(int i=1; i<n; i++){
starpiba = Modulis(SummaPirms(A,i)-SummaPec(A,i, n));
if(starpiba<starpiba0) starpiba0=starpiba;
}

//Cikls atkārtoti aprēķina starpību katram elementam un pārbauda, vai tā ir vienāda ar starpbiba0 jeb mazāko starpību visā masīvā.
for(int i=0; i<n; i++){
starpiba = Modulis(SummaPirms(A,i)-SummaPec(A,i, n));
if(starpiba==starpiba0) cout<<"Elementa indekss:"<<i<<endl;
}

cout << "Vai turpināt (1) vai beigt (0)?" << endl;
cin >> ok;
}while(ok==1);
return 0;
}

/*************************Testa plāns***********************************************

Ievade                        Programmas vēlamā reakcija
n=5, A={1;5;3;2;4}            Elementa indekss:2

n=4, A={2;2;2;2}              Elementa indekss:1
                              Elementa indekss:2

n=1, A={}                     Kļūdaina vērtība. Masīva izmēram jābut diapazonā no 2 līdz 100.Ievadiet masīva A izmēru n.(2<=n<=100):

n=3 A={-3;...}                Kļūdaina vērtība. Jāievada nenegatīvs skaitlis(skaitlis>0.)
                              1.elements:
*************************************************************************************/


