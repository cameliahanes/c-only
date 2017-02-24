#include <iostream>
#include <fstream>
using namespace std;
int n, m, k;
long a[1000][1000], element;


struct stt{
    int length;
    int positions[500];
};

int main()
{
    cin >> m >> n;
    stt st[n];
    for ( int i = 0; i < m ; ++ i ){
        st[i].length = 0;
        st[i].positions[0] = 0;
    }
    for ( int i = 0; i < m; ++i ){
        for ( int j = 0; j < n; ++j ){
            cin >> element;
            a[i][j] = element;
            if ( i > 0 ){
                if ( a[i][j] < a[i-1][j] ){
                    ++ st[j].length ;
                    st[j].positions[st[j].length - 1] = i;
                }
            }
        }
        //preprocessed
    }
    cin >> k;
    long l, r;
    for ( int i = 0; i < k ; ++i ){
        cin>> l >> r;
        if ( l == r || l + 1== r ){
            cout << "Yes \n";
        } else {
            bool ok = false, ok2= false;
        for ( int i = 0; i < m ; ++ i){
                if ( st[i].length == 0 ){
                    cout << "Yes \n";
                    //ok = true;
                break;}
                else {
                ok2 = false;
                for ( int j = 0; j <= st[i].length-1; ++j ){
                    if ( st[i].positions[j] >= l-1 || st[i].positions[j+1] <= r-1 ){
                        ok = false;
                    } else ok2 = true;
                }
                }

            }
            if ( ok2 == true ){
                cout << "Yes \n";
            } else
            if ( ok == false ){
                cout << "No \n";
            }
        }
        }


    return 0;
}
