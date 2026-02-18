/**
Ričards Nils Liberts, rl25036
16.02.2026.

Izveidot programmu valodā C++, kas
apstrādā teksta failu secīgā režīmā.

Dati no faila jānolasa pa vienai rindiņai.
Nedrīkst dublēt visa faila saturu operatīvajā
atmiņā.
Sīkākas prasības sk. Laboratorijas
darbu noteikumos.

F9. Izvadīt dotajā teksta failā
f sastapto latīņu alfabēta burtu
lietojuma biežuma tabulu (nešķirojot
lielos un mazos burtus) failā f1.
Tabulai jābūt sakārtotai alfabētiski.

**/
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){

fstream fin;
fstream fout;
string rin;
int biezums[26] = {0}; //saturēs biežumu simboliem A-Z

fin.open("f.txt", ios::in);
fout.open("f1.txt", ios::out);

if(!fin) {cout<<"Nav faila"<<endl; return 17;}

getline(fin,rin);

while(fin){
    for(int i=0;i<rin.length(); i++){
            unsigned char c = (unsigned char)rin[i]; //ASCII koda indeksa nolukos lietots unsigned
            if(isalpha(c)){ //Izsekos tikai burtus nevis citus simbolus
                int indekss = toupper(c)-'A'; //ASCII koda atnemsana, lai iegutu index vertibu diapozdona 0-25
                if (indekss>=0 && indekss<26){
                    biezums[indekss]++;//Pievieno biezuma papildinajumu attiecosam burtam
                }
            }
    }

    getline(fin,rin);
}
fin.close();

for(int i=0;i<26;i++){
    if(biezums[i]>0){ //Lai izdrukatu tikai to burtu biezumu, kas paradas teksta faila
        fout<<(char)('A'+i)<<": "<<biezums[i]<<endl;
    }
}
fout.close();
cout<<"Darbība veiksmīga"<<endl;
return 0;
}


/**************  Testu plāns **************************
 teksta fails      paredzamais rezultāts
 f.txt             f1.txt
 "aAddbbbB!"       A: 2
                   B: 4
                   D: 2
 -----------------------------------------------------
 "ccc   cc"        A: 2
 "aAddbbbB!"       B: 4
                   C: 5
                   D: 2
------------------------------------------------------
!!!!!!!            tukšs fails
*******
))))))
------------------------------------------------------
tukšs fails         tukšs fails
------------------------------------------------------
f.open("ff.txt",io::in)              Nav faila
******************************************************/



