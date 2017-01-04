#include <iostream>

using namespace std;
struct Polinom
{
    double V[100];
    int grad;
};

Polinom ProdusPoli(Polinom P1, Polinom P2)
{
    Polinom P3;
for (int i=0;i<100;i++){
    P3.V[i]=0;
}

    for(int i=0; i<=P1.grad; i++)
    for(int j=0; j<=P2.grad; j++){
         P3.V[i+j]+=P1.V[i]* P2.V[j];
         if(P1.V[i]* P2.V[j]>0)
            P3.grad=i+j;

    }
    return P3;

}

void CitirePolinom(Polinom &P)
{


cout<< "Introduceti gradul polinomului: \n";
cin>>P.grad;
cout<<"Introduceti coeficientii: \n";
for(int i=P.grad; i>=0; i--)
    cin>>P.V[i];
}

void TiparirePolinom(Polinom P)
{
    cout<<P.grad<<'\n';
    for(int i=P.grad; i>0; i--)
        cout<<P.V[i]<<"*x^"<<i<<"+";
    cout<<P.V[0];
}

void Deriveaza(Polinom &P){
for(int i=0; i<P.grad; i++)
    P.V[i]=(i+1)*P.V[i+1];
    P.grad--;
}


int main()
{
    Polinom P;
    CitirePolinom(P);
    Deriveaza(P);
/*    Polinom Q;
    CitirePolinom(Q);
    Polinom R=ProdusPoli(P, Q);

    TiparirePolinom(R);

  */


  TiparirePolinom(P);
return 0;
}
