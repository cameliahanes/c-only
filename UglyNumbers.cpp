#include <iostream>

using namespace std;


int main()
{
    int ugly[150];
    ugly[0] = 1;
    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    int next_multiple_of_2 = ugly[i2]*2;
    int next_multiple_of_3 = ugly[i3]*3;
    int next_multiple_of_5 = ugly[i5]*5;
    int n;
    cin >> n;
    int next_ugly_no;
    for ( int i = 1; i < n; i ++ ){
    next_ugly_no = min( next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
    if ( next_ugly_no == next_multiple_of_2 ){
        i2 = i2 + 1;
        next_multiple_of_2 = ugly[i2] * 2;
    }
    if ( next_ugly_no == next_multiple_of_3 ){
        i3 = i3 + 1;
        next_multiple_of_3 = ugly[i3] * 3;
    }
    if ( next_ugly_no == next_multiple_of_5 ){
        i5 = i5 + 1;
        next_multiple_of_5 = ugly[i5] * 5;
    }
    ugly[i] = next_ugly_no;
    }
    for ( int i = 0; i < n; i++ )
        cout  << ugly[i] << " ";
    return 0;
}
