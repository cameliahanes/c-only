#include <bits/stdc++.h>
using namespace std;
#define k 1999999973
#define cif 10001 // nr max cifre

int main(){
long long n, p;
ifstream f("lgput.in");
ofstream g("lgput.out");
f >> n >> p;
long long a = n;
long long sol =1;
for (int i = 0; (1 << i) <= p; ++ i ){
	if ( ((1 << i) & p) ) // bitul i din p este 1 
		sol = (sol * a) % k;
	a = (a * a) % k;
}
g << sol << "\n";
return 0;
}


