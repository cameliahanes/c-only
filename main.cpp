#include <iostream>
#define modd 98999
#include <fstream>
using namespace std;

void precalculareSI (int m[202][202], int n){
m[1][1] = 1;
for(int i =2; i<n; i++){
    for(int j = 1; j<=i; j++)
        m[i][j] = ( m[i-1][j-1] - (i-1)*m[i-1][j] )%modd;
}
}

void precalculareSII (int m[202][202], int n){
m[1][1] = 1;
for(int i=2; i<n; i++){
    for( int j =1; j<=i; j++)
        m[i][j] = ( m[i-1][j-1] + j *m[i-1][j] ) % modd;
}
}
int main()
{
    ifstream f("stirling.in");
    ofstream g("stirling.out");
    int n, T;
    int s[202][202], S[202][202];
    precalculareSI(s, 202);
    precalculareSII(S, 202);
    f >> T;
    int x, m;
    while(T--){
        f >>x >> n>> m;
        if( x == 1){            g << s[n][m]<<"\n";
           }
        else{
            if( x == 2){
                g << S[n][m]<<"\n";
                }
        }
    }
    f.close();
    g.close();
    return 0;
}
