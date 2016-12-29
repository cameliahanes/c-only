#include <iostream>

using namespace std;

int countt ( int n, int type ){
    int nex = 0;
    switch (type)
        {
    case 25:
        nex = 10;
        break;
    case 10:
         nex = 5;
        break;
    case 5:
        nex = 1;
        break;
    case 1:
        return 1;
        }
    int ways = 0;
    for ( int i = 0; i*type <= n; i ++){
        ways += countt(n-i*type, nex);
    }
    return ways;
}

int main()
{
    int n;
    cin >> n;
    cout << countt(n, 25);
    return 0;
}
