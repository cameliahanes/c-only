#include <iostream>
#include <string.h>
using namespace std;

void citireSir ( int v[ ], int& lungime ){
cout <<"Dati lungimea sirului: ";
cin >> lungime;
cout <<"Dati sirul: \n";
for ( int i = 0; i < lungime; i++ ){
    cin >> v[i] ;
}
}

void sub ( int nr, int v[ ], int& n ){
    //subprogramul dubleaza numarul nr aparut in sir
    //pentru inceput copiem sirul intr-un sir auxiliar
    int aux [ 2 * n ];
    for ( int i = 0; i< n; i++ )
        aux[i] = v [ i];
    //sirul este copat, acum executam modificarile
    int length = 0;
    for ( int i = 0; i < n; i++ ){
        v[ length ] = aux[i];
        length ++;
        if ( aux[i] == nr ){
            v[length] = nr;
            length ++;
        }
    }
    n = length;
}

void tiperire ( int sir[ ], int lungime ){
cout << "Sirul este: \n";
for ( int i = 0; i < lungime; i++ ){
    cout << sir[i] <<" ";
}
}

int f ( int x ){
if ( x == 0 )
    return 0;
else{
    int c = f ( x / 10 );
    if ( x % 10 > c ){
        return x % 10;
        cout << c <<" ";
    }else return c;

}
}


int main()
{
   int lungime, v[100], nr;
/*   citireSir(v, lungime);
   cout <<"Dati nr: ";
   cin >> nr;
   sub(nr, v, lungime);
   tiperire(v, lungime); */
  // cin >> nr;

   cout << strstr( "informatica", "ma");
    return 0;
}
