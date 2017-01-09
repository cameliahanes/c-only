#include <iostream>

using namespace std;
struct ElementPolinom
{
    int coeficient;
    int grad;
};

struct Polinom
{
    ElementPolinom V[100];
    int lungime;
};

int ComparaGrade(ElementPolinom e1, ElementPolinom e2)
//functia returneaza valoarea 1 daca e1 are gradul mai mic decat e2, returneaza 0 daca au gradele egale si returneaza 2 daca are gradul mai mare decat e2
{
    if(e1.grad<e2.grad)
        return 1;
    else
    {
        if(e1.grad==e2.grad)
            return 0;
    }
    return 2;
}

int BinarySearchGrade(Polinom P, ElementPolinom e)
{
    //fnctia returneaza pozitia elementului care are gradul egal cu a elementului e sau -1 daca nu exista gradul respectiv deja in sir;
    if(e.grad==P.V[0].grad)
        return 0;
    if(e.grad==P.V[P.lungime-1].grad)
        return P.lungime-1;
    int st, dr;
    st=0;
    dr=P.lungime-1;
    while(st<dr)
    {
         int mijl=(st+dr)/2;
        if(P.V[mijl].grad==e.grad)
            return mijl;
        else
        {
            if(e.grad<P.V[mijl].grad)
                dr=mijl-1;
            else
                st=mijl+1;
        }
    }
    return -1; //returneaza -1 daca gradul elementului care va fi inserat in vectorul polinomului nu exista in sir deja
}

void Inserare(Polinom &P, ElementPolinom e)
{
    if(P.lungime==0)
    {
        P.V[0]=e;
        P.lungime++;
    }
    else
    {
        if(ComparaGrade(e, P.V[P.lungime-1])==2) //daca are gradul mai mare decat toate elementele existente il pune la final
        { P.lungime++;
            P.V[P.lungime-1]=e;

        }
        else
        {
            int k=BinarySearchGrade(P, e); //ii da lui k val -1 sau a pozitiei elementului cu grad egal cu al lui e
            if(k!=-1){
                P.V[k].coeficient+=e.coeficient;//aduna coeficientii daca gradele sunt egale
                //decrementarea lungimii vectorului
                }

            else
            {
                int i=P.lungime-1;
P.lungime++;
                while(ComparaGrade(e, P.V[i])==1) //parcurge vectorul pana gaseste pozitia potrivita pentru element
                {
                    P.V[i+1]=P.V[i];
                    i--;
                }
                P.V[i+1]=e; //il pune pe pozitia dorita

            }
        }
    }
}

void CitirePolinom(Polinom &P)
{
    P.lungime=0;
    ElementPolinom p; //declararea unui element al polinomului
    cout<<"Dati primul element al polinomului (coeficient, grad): \n";
    cin>>p.coeficient>>p.grad;
    while(p.grad>=0 && p.coeficient!=0) //citirea se opreste cand sunt introduse doua valori de 0 sau doar valoarea coeficientului 0
    {
        Inserare(P, p);
        cout<<"Dati urmatorul element al polinomului (coeficient, grad): \n";
        cin>>p.coeficient>>p.grad;
    }
}

Polinom Derivata(Polinom P)
{
    Polinom d=P;
    for(int i=0; i<=P.lungime; i++){
        d.V[i].coeficient*=d.V[i].grad;
        d.V[i].grad--;
    }
    if(d.V[d.lungime].coeficient==0)
        d.lungime--;

    return d;
}

int Putere(int x, int k)
{
    if(k==0)
        return 1;
    else
        return x*Putere(x, k-1);
}
int EvalPoli(Polinom P, int x)
{
    int t=1;
    int p=P.V[0].coeficient*Putere(x, P.V[0].grad);
    for(int i=1; i<=P.lungime-1; i++)
    {
        t=t*Putere(x, P.V[i].grad-P.V[i-1].grad);
        p+=P.V[i].coeficient*t;
    }
    return p;
}


Polinom SumaPoli(Polinom A, Polinom B)
{
    Polinom C;
    C.lungime=0;
    int i=0, j=0;
    while(i<A.lungime && j<B.lungime)
    {
        if(A.V[i].grad<B.V[j].grad)
        {
            C.V[C.lungime].grad=A.V[i].grad;
            C.V[C.lungime].coeficient=A.V[i].coeficient;
            C.lungime++;
            i++;
        }
        else
        {
            if(B.V[j].grad<A.V[i].grad)
            {
             C.V[C.lungime]=B.V[j];
             C.lungime++;
             j++;
            }
            else
            {
                C.V[C.lungime].grad=A.V[i].grad;
                C.V[C.lungime].coeficient=A.V[i].coeficient+B.V[j].coeficient;
                C.lungime++;
                i++;
                j++;
            }
        }
    }

    if(i<A.lungime-1)
        while(i<=A.lungime-1)
    {
        C.V[C.lungime]=A.V[i];
        C.lungime++;
        i++;
    }
    if(j<B.lungime-1)
        while(j<=B.lungime-1)
    {
        C.V[C.lungime]=B.V[j];
        j++;
        C.lungime++;
    }
    return C;
}

Polinom ProdusPoli(Polinom A, Polinom B)
{
    Polinom C;
    for(int i=0; i<100; i++){
        C.V[i].grad=0;
        C.V[i].coeficient=0;
    }

    C.lungime=0;
    for(int i=0; i<A.lungime-2; i++)
        for(int j=0; j<B.lungime-2; j++)
    {
        if(i+j>C.lungime)
            C.lungime=i+j;
        C.V[i+j].coeficient+=A.V[i].coeficient*B.V[j].coeficient;
        C.V[i+j].grad=A.V[i].grad*B.V[j].grad;

    }
    return C;
}
void TiparirePolinom(Polinom P)
{
    cout<<P.V[P.lungime].coeficient<<"*x^"<<P.V[P.lungime].grad;
    for(int i=P.lungime-1; i>=0; i--)
        cout<<"+"<<P.V[i].coeficient<<"*x^"<<P.V[i].grad;
}


int main()
{
int optiune;
cout<<"Alegeti operatia care doriti sa fie efectuata: \n 1-valoarea polinomului intr-un punct \n 2-derivata polinomului \n 3-suma a doua polinoame \n 4-produsul a doua polinoame \n";
cin>>optiune;
switch(optiune)
{
case 1:
    {
        Polinom A;
        cout<<"Dati polinomul: \n";
         CitirePolinom(A);
         cout<<"Polinomul este: \n";
         TiparirePolinom(A);
         cout<<endl;
         cout<<"Dati punctul in care doriti sa fie calculat polinomul (intreg): \n";
         int x;
         cin>>x;
         cout<<"Valoarea polinomului in punctul "<<x<<" este: "<<EvalPoli(A, x)<<"\n";
         break;
    }
case 2:
    {
        Polinom A;
        cout<<"Dati polinomul: \n";
         CitirePolinom(A);
         cout<<"Polinomul este: \n";
         TiparirePolinom(A);
         cout<<endl;
         cout<<"Derivata polinomului este: \n";
         TiparirePolinom(Derivata(A));
         break;
    }
case 3:
    {
        Polinom A, B;
        cout<<"Dati primul polinom: \n";
        CitirePolinom(A);
        cout<<endl;
        cout<<"Dati cel de-al doilea polinom: \n";
        CitirePolinom(B);
        cout<<"Suma celor doua polinoame este: \n";
        TiparirePolinom(SumaPoli(A, B));
        break;
    }
case 4:
    {
        Polinom A, B;
        cout<<"Dati primul polinom: \n";
        CitirePolinom(A);
        cout<<endl;
        cout<<"Dati cel de-al doilea polinom: \n";
        CitirePolinom(B);
        cout<<"Produsul celor doua polinoame este: \n";
        TiparirePolinom(ProdusPoli(A, B));
        break;
    }
}

    return 0;
}
