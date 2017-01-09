#include <iostream>

using namespace std;
//read and initialize adiacence matrix
void read ( int edges[][100], int& dim ){
cout << "Give the points x & y : \n";
int x, y;
cin >> x >> y;
dim = max(x, y);
while ( x != -1 && y != -1 ){
        dim = max ( dim, max(x, y) );
    edges[x][y] = 1;
    edges[y][x] = 1;
    cin >> x >> y;
}
}

int getRoot ( int arr[ ], int i ){
while ( arr[i] != i ){
    arr[i] = arr[arr[i]];
    i = arr[i];
} return i;
}

int countComponents ( int n, int edges[ ][100], int dim ){
int counter = n;
int root[n];
//initialize each node is an island
for ( int i = 0; i < n; i ++ ) root[i] = i;

for ( int i = 0; i < dim; i ++ ){
    int x = edges[i][0];
    int y = edges[i][1];
    int xRoot = getRoot(root, x);
    int yRoot = getRoot(root, y);
    if ( xRoot != yRoot ){
        counter --;
        root[xRoot] = yRoot;
    }
}
return counter;
}
int main()
{
    int edges[100][100]; int dim = 0;
    read(edges, dim);
    cout << countComponents(dim, edges, dim);
    return 0;
}
