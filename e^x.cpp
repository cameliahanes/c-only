#include <iostream>
#define EPS 0.000001
using namespace std;
double e_X ( double x ){
double rez = 1.0;
double t = x;
double p = 2;

while (t*x/p - t >= EPS){
    rez+=t;
    t=t*x/p;
    p++;
}
return rez+t;
}
int main()
{
    double x;
    cin>>x;
   cout<<e_X(x);
    return 0;
}
