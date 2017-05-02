#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int m, k;
    while ( cin >> m >> k ){
        vector<int> f(m);
        for ( int i  =0; i < m; ++ i )
            cin >> f[i];

        long long frecv_total = 0;
        for ( int i = 0; i <  m; ++ i )
            frecv_total += f[i];

        vector<int> a_total(m);
        for ( int i = 0, x; i < k; ++ i ){
            cin >> x;
            a_total[x-1] ++;
        }

        priority_queue< pair<int, int> > Q;

        for ( int i = 0; i < m; ++ i ){
            Q.push( make_pair(-( ( a_total[i] + 1 ) * frecv_total + f[i] - 1 ) / f[i], i) );
        }

        int n;

        for ( n = k + 1; n <= k + 2 * frecv_total; ++ n ){
            if ( -Q.top().first < n ){
                n = -Q.top().first;
                break;
            }

            int i = Q.top().second;
            a_total[i] ++;
            Q.pop();
            Q.push( make_pair( -( (a_total[i] + 1)*frecv_total + f[i] - 1 )/ f[i], i  ) );
        }

        if ( n > k + 2 * frecv_total ){
            cout << "forever\n";
        } else {
        cout << n - k - 1 <<"\n";
        }


    }





    return 0;
}
