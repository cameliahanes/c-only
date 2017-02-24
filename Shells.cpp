#include <iostream>

using namespace std;
long long n;
int x;
int main()
{
    cin >> n;
    cin >> x;
    if ( n == 0 ){
        cout << x;
    } else if ( n % 6 == 0 ){
    cout << x;
    } else if ( n % 6 == 1 ){
    if (x == 0) cout << 1;
    else if ( x == 1) cout << 0;
    else if ( x == 2) cout << 2;
    } else if ( n % 6 == 2){
    if (  x == 0 ) cout << 1;
    else if ( x == 1) cout << 2;
    else cout << 0;

    } else if ( n % 6 == 3){
    if ( x == 0) cout << 2;
    else if ( x == 1) cout << 1;
    else cout << 0;
    } else if ( n % 6 == 4){
    if ( x == 0 ) cout<< 2;
    else if ( x == 1) cout << 0;
    else cout << 1;
    } else {
    if ( x == 0 ) cout << 0;
    else if ( x == 1) cout << 2;
    else cout << 1;
    }
    return 0;
}
