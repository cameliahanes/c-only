#include <iostream>
#include <fstream>
using namespace std;
long long L, C;

const inline long fnc(long long L, long long C){ return (L-1)^(C-1); }
ifstream f("tabela.in");
ofstream g("tabela.out");

int main()
{
    f >> L >> C;
    g << fnc(L,C);
    return 0;
}
