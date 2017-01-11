#include <iostream>
#include <string.h>
using namespace std;
int operatie(int x){
if(x==1)
    return 2;
if(x==2)
    return 1;
}

void Conjugat(char s[], char conj[]){
for(int i=0; i<strlen(s); i++){
    if(s[i]=='1')
        conj[i]='2';
    else{
        if(s[i]=='2')
            conj[i]='1';
        else{
          //  cout<<"eroare.";
          conj[i]=NULL;
            return ;
        }
    }
}
}
void CreeazaSir(int nr_caractere_afisate, char s[]){
cin>>s; //citeste valorile date din sir
char conj[1000];
Conjugat(s, conj);
//acum avem sirul conjugat pt sirul dat;
//creem un sir auxiliar in care vom retine conjugatul sirului rezultat si asa mai departe pana ajungem la lungimea dorita
char aux[1000];
//strcat(s, conj);
while(strlen(s)<nr_caractere_afisate){
        strcpy(aux, s);
        aux[strlen(aux)]=NULL;
        strcat(s, conj);
        s[strlen(s)]=NULL;
strcat(s, conj);
 s[strlen(s)]=NULL;
strcat(s, aux);
 s[strlen(s)]=NULL;

strcpy(aux, s); //noul sir copiat in aux;

    Conjugat(s, conj);
    conj[strlen(conj)]=NULL;
    //acum concatenam aux la conj;
  //  strcat(s, conj);
   // cout<< conj <<" ";
  //  s[strlen(s)]=NULL;
}
}
void TiparesteCaractere(int nr_caractere_afisate, char s[]){
for(int i=0; i<nr_caractere_afisate; i++)
    cout<<s[i];
}

int returneaza_valoare_pozitie_data(int m){
//stim ca pozitiile unde se schimba cifra sunt multipli de 4, acolo unde incepe o noua concatenare;
//conform regulii de concatenare, pe pozitiile de tip putere para a lui 2, unde puterea e de forma 2k+p, se afla intotdeauna valoarea 1, iar pe cele impare 2;
//trebuie sa aflam intervalul unde este pozitia numarului si, avand la indemana regula de concatenare si pozitiile corespunzatoare puterilor lui 2
//vom crea un sir de maximum 16 elemente;
int k=16; //luam in condierare prima grupa de termeni
int nr_puteri=0;
int p;
int sir[17];
if(m>k){
while(m>k)
    m-=k; //mergem pana unde ne spune pozitia m;
  //  k-=16;
p=m; //pozitia in sirul pe care il vom forma
cout<<p;
/*
while(w/2>1){
    nr_puteri++; //aflam daca e la putere para sau impara;
    w/=2;
} */}
if(nr_puteri%2==0)
    //daca este 2 la putere para
{
    sir[1]=sir[4]=sir[6]=sir[7]=sir[10]=sir[11]=sir[13]=sir[16]=1;
    sir[2]=sir[3]=sir[5]=sir[8]=sir[9]=sir[12]=sir[14]=sir[15]=2;
} else{
sir[1]=sir[4]=sir[6]=sir[7]=sir[10]=sir[11]=sir[13]=sir[16]=2;
    sir[2]=sir[3]=sir[5]=sir[8]=sir[9]=sir[12]=sir[14]=sir[15]=1;
}
return sir[p];
}
int main()
{
    int nr_caractere_afisate;
    char s[1000], conj[1000];
  //  cin>>nr_caractere_afisate;
  int m;
    CreeazaSir(nr_caractere_afisate, s);
//TiparesteCaractere( nr_caractere_afisate ,s);
cin>>m;
cout<<returneaza_valoare_pozitie_data(m);
    return 0;
}
