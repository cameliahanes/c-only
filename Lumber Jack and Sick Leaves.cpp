#include <iostream>

using namespace std;

struct Motivare
{
    int nrcrt;
    int FD; //prima zi
    int LD; //ultima zi
    int nrAbsenteMotivate;
    int v[30];
};

struct Absenta
{
    int data;
    Motivare m[30];
    int nrmotivari;
};

struct vectorM
{
    int nrM;
    int VnrcrtM[20];
} v[20];

void Citire(int& nrZile, int& totalAbsente, int& nrMotivari, Motivare M[], Absenta A[])
{
    cout<<"Cate zile are anul scolar? ";
    int n;
    cin>>n;
    nrZile=n;
    cout<<"\nCate absente are studentul? ";
    cin>>n;
    totalAbsente=n;
    cout<<"\nCate motivari are studentul? ";
    cin>>n;
    nrMotivari=n;
    cout<<"\nCare sunt datele pe care a absentat studentul? \n";
    for(int i=1; i<=totalAbsente; i++)
        cin>>A[i].data;
cout<<"\nDati datele motivarilor (prima zi-ultima zi): \n";
for(int i=1; i<=nrMotivari; i++)
{
    cin>>M[i].FD>>M[i].LD;
    M[i].nrcrt=i;
}
}

void TiparireDateMotivari(Motivare M[], int nrMotivari, Absenta A[], int totalAbsente)
{
    for(int i=1; i<=nrMotivari; i++)
        cout<<M[i].FD<<" "<<M[i].LD<<" "<<M[i].nrcrt<<endl;

        for(int i=1; i<=totalAbsente; i++)
            cout<<A[i].data<<" ";
}

void IncarcaVectorMotivariAbsenta(Absenta& a, int nrMotivari, Motivare M[])
{
    a.nrmotivari=1;
    for(int i=1; i<=nrMotivari; i++)
    {
        if(a.data>=M[i].FD && a.data<=M[i].LD)
        {
            a.m[a.nrmotivari++]=M[i];
          // cout<< a.m[a.nrmotivari-1].nrcrt<<" ";
        }
    }
}

void IncarcaVectoriMotivariAbsente(Absenta A[], int nrAbsente, Motivare M[], int nrMotivari)
{
    for(int i=1; i<=nrAbsente; i++)
        IncarcaVectorMotivariAbsenta(A[i], nrMotivari, M);

   /*     for(int i=1; i<=nrAbsente; i++)
        {
            for(int j=1; j<=A[i].nrmotivari-1; j++)
                cout<<A[i].m[j].nrcrt<<" ";
            cout<<endl;
        } */
}

int CautaAbsentaVectorMotivari(Absenta a, Motivare m)
{
    for(int i=1; i<m.nrAbsenteMotivate; i++)
        if(a.data==m.v[i])
        return 1;
    return 0;
    //functia returneaza 1 daca motivarea data ca parametru se gaseste printre motivarile care acopera absenta a
}

void NumaraMotivari(Absenta A[], int totalAbsente, Motivare M[], int totalMotivari)
{
    //functia pune intr-un vector de tip int datele absentelor motivate de fiecare motivare
    // parcurge vectorul total de motivari si cauta pentru cate absente este utila fiecare dintre acestea
    for(int i=0; i<=totalMotivari; i++)
        M[i].nrAbsenteMotivate=0;

    for(int i=1; i<=totalMotivari; i++)
    {
        for(int j=1; j<=totalAbsente; j++){
            if(M[i].FD<= A[j].data && M[i].LD>=A[j].data)
            {

                M[i].v[M[i].nrAbsenteMotivate]=A[j].data;
                   M[i].nrAbsenteMotivate++;
            }
        /*    for(int k=0; k<M[i].nrAbsenteMotivate; k++)
                cout<<M[i].v[k]<<" ";
    */}
}
//vectorul de abente pentru fiecare motivare este realizat; acum ne ramane sa verificam care motivare este cea mai potrivita pentru cel mai mare numar de absen

// v=[inf inf inf inf inf 0]
 // v[D+1]

}

 /*void IncarcaVectorVM(int totalAbsente, Absenta A[], vectorM v[], int &lungVM, Motivare M[], int totalMotivari)
{
    int ok=0, OK=0;
    lungVM=totalMotivari;
    int minim=totalMotivari;
    int i=2;
    v[1].nrM=1;
     v[1].VnrcrtM[v[1].nrM]=M[1].nrcrt;
     int nrAM=M[1].nrAbsenteMotivate;
     int j=1;
     while(j<totalMotivari){
            i=j;
            ok=0;
    nrAM=0;
    while(i<=totalMotivari && M[i].LD<=A[totalAbsente].data)
    {

        if(M[i].FD>M[i-1].LD){
            nrAM++;
            v[1].nrM++;
        v[1].VnrcrtM[v[1].nrM]=M[i].nrcrt;
        nrAM+=M[i].nrAbsenteMotivate;
        ok++; //numara cate motivari s-au folosit
        }
    }
    if(nrAM==totalAbsente)
        if(ok<minim)
            minim=ok;
            j++;}
            cout<<minim;
} */

int ExistaAbsenta(Absenta A[], int nrAbsente, int zi)
{
    int ziua=-1;
    for(int i=1; i<=nrAbsente; i++)
        if(A[i].data==zi)
        ziua = 0;
return ziua;
//functia returneaza valoarea 1 daca elevul a absentat pe data "zi" si 0 in caz contrar
}

int PrimaZiMotivare(Motivare M[], int nrMotivari, int ultimaZi)
{
    for(int i=1; i<=nrMotivari; i++)
        if(M[i].LD==ultimaZi)
        return M[i].FD;
}
void MotiveazaAbsente(Motivare M[], int nrMotivari, Absenta A[], int nrAbsente, int D) //D este numarul de zile ale anului scolar
{
    int v[D+1];
    for(int i=1; i<=D; i++)
        v[i]=32766;
    v[D+1]=0;
    int primaZi;
   int k=D;
        while(k>=1)
        {
            if(ExistaAbsenta(A, nrAbsente, k)==0){
                v[k]=min(v[k], (v[k+1]+1));
            primaZi=PrimaZiMotivare(M, nrMotivari, k);
                while(k>=1 && k>primaZi)
                {
                    k--;
                    v[k]=v[k+1];
                }
            }
            else{
                v[k]=v[k+1];
            k--;}

        }
          cout<<v[1]; //programare dinamica
}
int main()
{
    Motivare M[100];
    Absenta A[100];
    int n;
    int nrMotivari, nrZile, totalAbsente;
    Citire(nrZile, totalAbsente, nrMotivari, M, A);
    IncarcaVectoriMotivariAbsente(A, totalAbsente, M, nrMotivari);
    NumaraMotivari(A, totalAbsente, M, nrMotivari);
//    IncarcaVectorVM(totalAbsente, A, v, n, M, nrMotivari);
MotiveazaAbsente(M, nrMotivari, A, totalAbsente, nrZile);
    return 0;
}
