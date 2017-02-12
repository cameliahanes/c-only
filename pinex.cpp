#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;
#define ll long long
#define maxim 1000000

ifstream f("pinex.in");
ofstream g("pinex.out");
ll m, a, b, factors[30];
int primefactors[80000];
bool prime[maxim];

void precalculate(){
    fill(prime+2, prime+maxim, 1);
    for ( int i = 2; i < maxim; ++i ){
        if (prime[i]){
            for ( int j = 2*i; j < maxim; j += i)
                prime[j] = false;
            primefactors[++primefactors[0]] = i;
        }
    }
}

void solve(){
    ll t = 0, d = 0;
    while ( b > 1){
        ++d;
        if ( b % primefactors[d] == 0 ){
            factors[++t] = primefactors[d];
            while(b%primefactors[d] == 0)
                b /= primefactors[d];
        }
        if ( primefactors[d] > sqrt(b) && b > 1 ){
            factors[++t] = b;
            b = 1;
        }
    }
    ll solution = a;
    for ( int i = 1; i < (1 << t); ++i ){
        ll nr = 0, product = 1;
        for ( int j = 0; j < t; ++j )
        if ( (1<<j) & i){
            product = 1LL * product * factors[j+1];
            ++nr;
        }

        if (nr % 2) nr = -1;
        else nr = 1;

        solution = solution + 1LL*nr*a/product;
    }
g << solution << "\n";
}
int main()
{
    precalculate();
    f >> m;
    for ( int i = 1; i <= m; ++i){
        f >> a >> b;
        solve();
    }
    f.close();
    g.close();
    return 0;
}
