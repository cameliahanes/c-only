#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    if (l == r ) return 0;
    else{
        int k = l;
        int xor_max = 0;
        while ( k < r ){
            int p = k + 1;
            while ( p <= r ){
                if ( (k ^ p) > xor_max ){
                    xor_max = (k ^ p);}
                ++p;
            }
            ++k;
        }
        return xor_max;
    }

}

int main() {
    int res;
    int _l;
    cin >> _l;

    int _r;
    cin >> _r;

    res = maxXor(_l, _r);
    cout << res;

    return 0;
}
