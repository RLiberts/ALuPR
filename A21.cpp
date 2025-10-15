/****************************
Ričards Nils Liberts, rl25036
A21. Doti 3 naturāli skaitļi m, n un k.
Izdrukāt tos skaitļus, kuri atrodas intervālā [m,n] un kuri dalās ar k bez atlikuma.
Programma izveidota: 29.09.2025.
Programma papildināta: 15.10.2025.
*******************************/
#include <iostream>
using namespace std;

int main(){
int ok;
do //do while nodrošina atkārtotas izpildes iespējas
{
int m,n,k; //tiek deklerēti mainīgie, m ir intervāla sākumpunkts, n beigu punkts, k
bool num=false; //deklerē boolean tipa mainīgo, kas aptvers to vai vispār pastāv kāds skaitlis, kas dalās noteiktajā intervālā
                //Piešķir vērtību false, kamēr nav atrasts neviens skaitlis, kas dalās ar k intervālā [n;m]
do
{ //Iekšējs cikls, kas ļauj atkārtotu ievadi, ja lietotāja ievadītais sākuma punkts ir lielāks par beigu punktu
cout << "Ievadi intervāla sākuma punktu (naturāls skaitlis >= 1):" << endl;
cin>> m;
cout << "Ievadi intervāla beigu punktu (naturāls skaitlis >= 1):" << endl;
cin>> n;
if (m>n) cout<<"Sākuma intervāla vērtībai jābūt mazākai par beigu intervāla vērtību"<<endl; //Sākuma punktam jābūt mazākam nekā intervāla beigu punktam
}while(m>n); //Iespējams beigt ciklu tikai tad, kad ievadītas pareizas vērtības. Intervāla sākumpunkts mazāks nekā beigu punkts.
do
{
cout << "Ievadi dalītāju (naturāls skaitlis >= 1):" << endl;
cin >> k;
if (k<=0) cout<< "Dalītājs nedrīkst būt vienāds ar nulli"<<endl<<"Ievadi dalītāju (naturāls skaitlis >= 1):"<<endl;
}while(k<=0);

cout << "Skaitļi, kuri atrodas intervālā " << m << "-" << n << " un dalās ar " << k << ":" << endl;
for (int i=m; i<=n; i++){ //deklerērts i un piešķirta sākotnējā vērtība m, jo m ir mūsu intervāla sākumpunkts.
//Cikls strādā tik ilgi kamēr i ir mazāks vai vienāds par n, jo n ir galapunkts. Tā kā nepieciešami naturāli skaitļi, mūsu solis ciklā palielinās par vienu veselu.
if (i%k==0){
cout << i << endl;
num = true; //Tā kā izpildas darbība i%k==0 vismaz vienu reizi, tad mainīgam num, tiek piešķirta vērtībaa true, kas apliecina, ka ir tāds skaitlis intervālā, kas dalas ar izvēlēto.
}
}
if (num==false) cout << "Nav atrasts neviens skaitlis intervālā, kas dalās ar " << k << "." << endl; //Ja pēc for cikla, mainīgā num vērtība paliek nemainīga, tad
//šajā intervālā nav tāda skaitļa, kas dalītos ar k. Tāpēc arī nepieciešams mainīgais num.
cout << "Vai turpināt (1) vai beigt (0)?" << endl;
cin >> ok;
} while (ok == 1);
return 0;
}

/*************************Testa plāns***********************************************

Ievade                      Programmas vēlamā reakcija
m=1, n=18, k=3              3, 6, 9, 12, 15, 18
m=18, n=1, k=3              Sākuma intervāla vērtībai(M) jābūt mazākai par beigu intervāla vērtību(N)
m=1, n=5, k=10              Nav atrasts neviens skaitlis intervālā, kas dalās ar 10
m=1, n=18, k=-2             Dalītājs nedrīkst būt vienāds ar nulli
*************************************************************************************/
