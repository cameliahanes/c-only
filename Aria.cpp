#include <iostream>
#include <fstream>
#include<iomanip>
#define maximm 100005
using namespace std;
ifstream f("aria.in");
ofstream g("aria.out");
struct punct {
double x, y;
};
void citireDateFisier(long& nrPuncte, punct vect[maximm]){
f >> nrPuncte;
for ( int i = 0; i< nrPuncte; i++ ){
    f >> vect[i].x >> vect[i].y;
}
f.close();
}
void determinaArie ( long nrPuncte, punct vect[maximm], double& sol ){
vect[nrPuncte]=vect[0];
sol = 0;
for ( int i = 0; i<nrPuncte; i++ ){
    sol+= ( vect[i].x*vect[i+1].y - vect[i].y*vect[i+1].x );
}
sol/=2.0;
}
void tiparireArieFisier (double sol ){
g << setprecision(10)<<sol;
g.close();
}
int main()
{
    punct vect[maximm];
    long nrPuncte;
    double solutie = 0;
    citireDateFisier(nrPuncte, vect);
    determinaArie(nrPuncte, vect, solutie);
    tiparireArieFisier(solutie);
    return 0;
}
