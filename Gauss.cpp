#include <iostream>
#define MAXN 100
#define EPS 0.000001
using namespace std;
int M, N;
double A[MAXN][MAXN];
double X[MAXN];
void CitireMatrice(){
cout<<"Cate linii are matricea?";
cin>>N;
cout<<"Dar coloane?";
    cin>>M;
    cout<<"Dati aceste elemente: (cu precizarea ca pe fiecare linie se afla, la final, elementul solutie al ecuatiei)\n";
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M+1; j++)
            cin>>A[i][j];
}
void TiparireMatrice(){
for(int i=1; i<=N; i++){
    for(int j=1; j<=M+1; j++)
        cout<<A[i][j]<<" ";
    cout<<endl;
}
    }
void Gauss(){
int i=1, j=1; //pozitiile cu care se incepe parcurgerea liniilor, respectiv a coloanelor matricei
while(i<=N && j<=M){
    //se cauta o linie pentru care elementul de pe coloana j sa fie diferit de 0
    int p;
    for(p=i; p<=N; p++){
        if(A[p][j]<-EPS || A[p][j]>EPS)
            break; //se opreste cand l-a gasit;
    }
    if(p==N+1) //daca nu a gasit un astfel de element, incrementeaza indicele pentru coloana
        j++;
    if(p!=i) //in acest caz, interschimba liniile i si k intre ele
        for(int l=1; l<=M+1; l++)
        swap(A[i][l], A[p][l]);
    //acum se impart toate elementele de pe linia i la elementul A[i][j]
    for(int l=j+1; l<=M+1; l++)
        A[i][l]/=A[i][j];
    A[i][j]=1;
    //acum transformam in 0 toate elementele de pe coloana j, scazand din elementele de pe fiecare coloana elementul
    for(int u=i+1; u<=N; u++){
            for(int l=j+1; l<=M+1; l++)
                A[u][l]-=A[u][j]*A[i][l];
            A[u][j]=0;
        }
      //  TiparireMatrice();
        i++;
        j++;
}
}
void Necunoscute(){
for(int i=N; i>=1; i--){
    for(int j=1; j<=M+1; j++){
        if(A[i][j]<-EPS || A[i][j]>EPS){
            if(j==M+1){
                cout<<"Ecuatia nu are solutii.";
                return;
            }
            //necunoscuta j este rezultatul ecuatiei de pe linia i fara celelalte necunoscute de pe coloane, inmultite cu coeficientii lor;
            X[j]=A[i][M+1]; //rezultatul
            for(int k=j+1; k<=M; k++)
                X[j]-=X[k]*A[i][k];
            cout<<X[j]<<" ";
        }
    }
}
}
int main()
{
  CitireMatrice();
  Gauss();
 // TiparireMatrice();
  Necunoscute();
    return 0;
}
