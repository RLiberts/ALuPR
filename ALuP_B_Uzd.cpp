/****************************
Ričards Nils Liberts, rl25036
B19. Atrast visus simetriskus skaitļus intervālā [n, m,
kurus kāpinot kvadrātā iegūst simetrisku skaitli.
Skaitļu dalīšana ciparos jāveic skaitliski.
Risinājumā izmantot funkciju, kas noskaidro, vai skaitlis ir simetrisks
(Piemēram, skaitlim 2341 simetriskais skaitlis ir 1432).
Programma izveidota: 18.10.2025.
*******************************/
#include <iostream>
using namespace std;
//Funkcija, kas izveido simetrisku skaitli
int apgriezts(int x){
    int ap=0; //sākotnējā vērtība 0. Glabās mūsu simetrisko skailti
    if (x<0) x=-x; //Negatīvus skaitļus pārvērš pozitīvos
    //Ciklā simetriska skaitļa iegūšanao
    while (x>0){
        ap=ap*10+x%10;
        x/=10;
    }
    return ap;
}
//Funkcija, kas pārliecinās, vai skaitļi ir simetriski
bool simetrija(int x){
    if (x<0) x=-x; //Negatīvus skaitļus pārvērš pozitīvos
    return x==apgriezts(x);//Atgriež true or false par izteikumu, kas nosaka simetriju skaitlim
}

int main(){
    int ok;
do{
   int n, m; //deklerē intervāla sākuma un beigu punktu.
   bool sim;
   //Iekšējs cikls, kas ļauj atkārtotu ievadi, ja lietotāja ievadītais sākuma punkts ir lielāks par beigu punktu
   do{
        cout<<"Ievadi intervāla sākuma punktu (veselu skaitli):" << endl;
        cin>>n;
        cout<<"Ievadi intervāla beigu punktu (veselu skaitli):" << endl;
        cin>>m;
        if (n>m) cout<<"Sākuma intervāla vērtībai jābūt mazākai par beigu intervāla vērtību"<<endl;

}while(n>m ); //Iespējams beigt ciklu tikai tad, kad ievadītas pareizas vērtības. Intervāla sākumpunkts mazāks par beigu punkts.
    for(int i=n; i<=m; i++){
        if(simetrija(i)&&simetrija(i*i)){
           cout<<i<<" ir simetrisks skaitlis, tā kvadrāts ir "<<i*i<<",kas arī ir simetrisks skaitlis"<<endl;
           sim=true;
           }
    }
    if(sim==false) cout<<"Nav tāda skaitļa intervālā, kurš pats būtu simetrisks un arī tā kvadrāts"<<endl;
    cout << "Vai turpināt (1) vai beigt (0)?" << endl;
    cin >> ok;
}while(ok==1);
    return 0;
}


/*************************Testa plāns***********************************************

Ievade                        Programmas vēlamā reakcija
n=1, m=4                      1 ir simetrisks skaitlis, tā kvadrāts ir 1,kas arī ir simetrisks skaitlis
                              2 ir simetrisks skaitlis, tā kvadrāts ir 4,kas arī ir simetrisks skaitlis
                              3 ir simetrisks skaitlis, tā kvadrāts ir 9,kas arī ir simetrisks skaitlis

n=-55, m=55                   -22 ir simetrisks skaitlis, tā kvadrāts ir 484,kas arī ir simetrisks skaitlis
                              -11 ir simetrisks skaitlis, tā kvadrāts ir 121,kas arī ir simetrisks skaitlis
                              -3 ir simetrisks skaitlis, tā kvadrāts ir 9,kas arī ir simetrisks skaitlis
                              -2 ir simetrisks skaitlis, tā kvadrāts ir 4,kas arī ir simetrisks skaitlis
                              -1 ir simetrisks skaitlis, tā kvadrāts ir 1,kas arī ir simetrisks skaitlis
                              0 ir simetrisks skaitlis, tā kvadrāts ir 0,kas arī ir simetrisks skaitlis
                              1 ir simetrisks skaitlis, tā kvadrāts ir 1,kas arī ir simetrisks skaitlis
                              2 ir simetrisks skaitlis, tā kvadrāts ir 4,kas arī ir simetrisks skaitlis
                              3 ir simetrisks skaitlis, tā kvadrāts ir 9,kas arī ir simetrisks skaitlis
                              11 ir simetrisks skaitlis, tā kvadrāts ir 121,kas arī ir simetrisks skaitlis
                              22 ir simetrisks skaitlis, tā kvadrāts ir 484,kas arī ir simetrisks skaitlis

n=14, m=16                    Nav tāda skaitļa intervālā, kurš pats būtu simetrisks un arī tā kvadrāts
*************************************************************************************/
