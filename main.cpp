#include <iostream>

using namespace std;

const inline int fin (int n, int minutes){}

int main()
{
    int n, k;
    cin >> n >> k;
    int s = 5 * n * (n+1) / 2;
    int nrp = n;
    int p = 240 - k;
    while (s > p){

        //cout << nrp << "h";
        s -= (5*nrp);
        -- nrp ;
    }
    cout << nrp;
    return 0;
}
