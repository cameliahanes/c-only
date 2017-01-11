#include <iostream>
#define NMax 1024
#include <fstream>
using namespace std;

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;
ifstream f( "cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int i, j;
    f >> M >> N;
    for(i= 1; i<= M; i++ ) f >> A[i];
    for(i= 1; i<= N; i++) f >> B[i];

    for(i=1; i<=M; i++ )
    for(j=1; j<= N; j++ )
    if ( A[i] == B[j] )
        D[i][j] = 1 + D[i-1][j-1];
    else D[i][j] = max(D[i-1][j], D[i][j-1]);

    i = M;
    j=N;
    while ( i ){
        if ( A[i] == B[j] )
        sir[++bst] = A[i], --i, --j;
    else if (D[i-1][j] < D[i][j-1] )
        --j;
    else --i;
    for ( i = bst; i; --i )
        cout << sir[i] <<" ";}
    return 0;
}
