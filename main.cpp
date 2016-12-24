#include <iostream>
#include <fstream>
using namespace std;
ifstream f("farey.in");
ofstream g("farey.out");
/*
void citireDateFisier ( int& n, int& a, int& b ){
f >> n >> a >> b;
f.close();
}
*/
void citireDate ( long& n, long& k){
f >> n >> k;
f.close();
}

/*
void fractiaRezultata ( int a, int b, int& aa, int& bb, int n ){
int af, bf, ai, bi;
ai = 1;
af = n-1;
bf = n;
bi = n;
int xi = ai+1;
int xf = af-1;
int yi = bf - 1;
int yf = bf - 1;
while ( xi != xf ){
    if ( a == ai && b==bi){
        aa = xi;
        bb = yi;
        return ;
    }
    if( a == xf && b == yf ){
        aa = af;
        bb = bf;
        return ;
    }
    ai = xi;
    af = xf;
    bi = yi;
    bf = yf;
    if ( xf - 1 + xi < yf) {
        xi ++;
        xf = n-xi;
        yf = n;
        yi = n;
    }else{
    yi --;
    yf --;
    xf = yf-xi;
    }
}
}
*/
void fractiaRezultataII ( long k, long& aa, long& bb, long n ){
long af, bf, ai, bi;
ai = 1;
af = n-1;
bf = n;
bi = n;
long i = 1, j = n;
long xi = ai;
long xf = af;
long yi = bf;
long yf = bf;
while ( i<j ){

    if ( xf - 1 + xi < yf) {
        xi ++;
        xf = n-xi;
        yf = n;
        yi = n;
    }else{
    yi --;
    yf --;
    xf = yf-xi;
    }
     if ( i==k ){
        aa = xi;
        bb = yi;
        return ;
    }
    if( j==k ){
        aa = xf;
        bb = yf;
        return ;
    }
i++;
j--;
}
}


void tiparireFisier ( long a, long b ){
g << a <<" " <<b;
g.close();
}
int main()
{
    long n, a, b, aa, bb, k;
    citireDate(n, k);
//    citireDateFisier(n, a, b);
   // fractiaRezultata(a, b, aa, bb, n);
    fractiaRezultataII(k, aa, bb, n);
    tiparireFisier(aa, bb);
 //   cout << aa <<" "<<bb;
    return 0;
}
