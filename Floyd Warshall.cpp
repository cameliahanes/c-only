#include <iostream>
#define infinity 32766
using namespace std;

void read(int& n, int dist[100][100]){
    int x, y, value;
    cin >> n;
    for ( int i = 1; i <= n; ++i ){
        for ( int j = 1; j <= n; ++j ){
            if ( i != j )
                dist[i][j] = infinity;
            else
                dist[i][j] = 0;
        }
    }
    for ( int i = 1; i <= n; ++i ){
        cin >> x >> y >> value;
        dist[x][y] = value;
    }
}

void floyd_warshall(int n, int dist[100][100]){
    for ( int k = 1; k <= n; ++k ){
        for ( int i = 1; i <= n; ++i ){
            for ( int j = 1; j <= n; ++j ){
                if ( dist[i][j] > dist[i][k] + dist[k][j] )
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void display(int n, int dist[100][100]){
for ( int i = 1; i <= n; ++i ){
    for ( int j = 1; j <= n; ++j ){
        cout << dist[i][j] << " ";
    }
    cout << "\n";
}
}

int main()
{
    int dist[100][100], n;
    read(n, dist);
    floyd_warshall(n, dist);
    display(n, dist);
    return 0;
}
