#include <iostream>

using namespace std;
int given_sum;
int n;
const inline int f(int a, int b){ return (a^b);}
int main()
{
    cin >> n;
    cout << "Give the sum: ";
    cin >> given_sum;
    int ss = (n*(n+1))/2;
    cout << given_sum << " " << ss << endl;
    cout << f(given_sum, ss);
    return 0;
}
