#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
bool VerificaEcuatia(int a, int b, int c, int x, int y){
if(a*x*x+b*y*y==c)
    return true;
return false;
}
void Citire(int& a, int& b, int& c, int& n, int s[]){
cin>>a>>b>>c>>n; //citeste a, b, c, n
for(int i=1; i<=n; i++)
    cin>>s[i]; //citeste sirul;
}
void TiparirePerechi_I (int a, int b, int c, int n, int s[]){
//n este lungimea sirului si s este sirul propriu-zis
//vom lua pe rand elementele si le vom verifica proprietatea de a verifica ecuatia grupandu-le cu toate celelalte
//este de luat in conderare faptul ca verificarea se face si la stanga si la dreapta, adica verificam pripietatea pe doua cazuri
//numerele luate in ordine normala si inversa, doua cate doua;
for(int i=1; i<n; i++){
    for(int j=i+1;j<=n; j++){
        if(VerificaEcuatia(a, b, c, s[i], s[j])==true)
            cout<<s[i]<<" "<<s[j]<<endl;
        if(VerificaEcuatia(a, b, c, s[j], s[i])==true)
            cout<<s[j]<<" "<<s[i]<<endl;
    }
}
}

int NumarPerechi_II (int a, int b, int c, int n, int s[]){
//pornim de la primul numar si il calculam pe urmatorul in functie de ecuatia acestuia; apoi, cautam numarul rezultat din rezolvarea ecuatiei/
//si daca numarul exista in sir, incrementam numarul de perechi
int nr_perechi =0;
for(int i=1; i<=n; i++){
    int t = a*s[i]*s[i]; //elementul cunoscut
    int w = ceil(sqrt(c-t));
    if(w > s[i]){
        int k=i+1;
        while(s[k] < w)
            k++;
        if(s[k]==w)
            nr_perechi++;
            if(VerificaEcuatia(a, b, c, w, s[i])==true)
                nr_perechi++;


    }
}
return nr_perechi;
}

int main()
{
   int n, a, b, c, s[100];
   Citire(a, b, c, n, s);
  // TiparirePerechi_I(a, b, c, n, s);
   cout<<NumarPerechi_II(a, b, c, n, s);
    return 0;
}
