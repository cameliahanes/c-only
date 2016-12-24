#include <iostream>
#include <cmath>
using namespace std;
struct Element
{
    int grad;
    int coeficient;
};

void CitirePlinom(Element A[], int& lungime)
{
    int n;
    cout<<"Dati lungimea vectorului cu coeficienti: \n";
    cin>>n;
    lungime=n;
    cout<<"\nDati elementele vectorului, sub forma coeficient-grad, incepand de la gradul cel mai mic: \n";
    for(int i=0; i<=lungime; i++)
        cin>>A[i].coeficient>>A[i].grad;

}
void TparirePolinom(Element A[], int lungime)
{
    //tiparirea de face in ordinea descrescatoare a gradelor;
    cout<<A[lungime].coeficient<<"*X^"<<A[lungime].grad;
    for(int i=lungime-1; i>=0; i--)
        cout<<"+"<<A[i].coeficient<<"*X^"<<A[i].grad;
}
void DerivarePolinom(Element A[], int& lungime)
{
    //functia deriveaza polinomul A dat ca parametru si realizeaza modificari in ce priveste lungimea acestuia
    if(A[0].grad==0)
    {
        for(int i=0; i<lungime; i++)
        {
            A[i].coeficient=A[i+1].coeficient*A[i+1].grad;
            A[i].grad=A[i+1].grad-1;
        }
        lungime--;
    }
    else{
        for(int i=0; i<=lungime; i++)
        {
            A[i].coeficient*=A[i].grad;
            A[i].grad--;
        }
    }

}

int EvalPoli(Element A[], int lungime, int x)
{
int pol=0, q;
q=pow(x, A[0].grad);
pol=q*A[0].coeficient;
for(int i=1; i<=lungime; i++)
{
    q*=pow(x, A[i].grad-A[i-1].grad);
    pol+=q*A[i].coeficient;
}
    return pol;
}

int TFX(Element A[], int& lungime, int a, int x)
{
    int n=A[lungime].grad; //nr de derivari posibile ale functiei
    int T=EvalPoli(A, lungime, a);
    //cout<<T;
    int  fact=1, p, q=x-a;
    for(int i=1; i<=n; i++)
    {
        DerivarePolinom(A, lungime);
       p=EvalPoli(A, lungime, a);
       //cout<<p<<" ";
       T+=(q*p)/fact;
       //cout<<"+((x-"<<a<<")^"<<i<<"/"<<fact<<")*"<<p;
    fact*=(i+1);
    q*=(x-a);
    }
    return T;
}
int taylorappprox(int x, int a){

    }
int main()
{
   Element A[100];
   int lungime;
   CitirePlinom(A, lungime);
int x, a;
cin>>a>>x;
cout<<TFX(A, lungime, a, x);
    return 0;
}
