#include <bits/stdc++.h>
using namespace std;

int shortest(int matrix[][100], int n, int m, int l, int c){
	if (l < 0 || c < 0 || l == n || c == m )
		return 1;
	if ( matrix[l][c] == 1 )
		return 101;
	
	if (l == n - 1 || c == m - 1 || l == 0 || c == 0 ) return 1;
	matrix[l][c] = 1; // kind of visited
	
	int best = min(min(shortest(matrix, n, m, l + 1, c), shortest(matrix, n, m, l - 1, c)), min(shortest(matrix, n, m, l, c + 1), shortest(matrix, n, m, l, c - 1)));
	return best + 1;
}


int main(){
int n, m, l, c;
int matrix[100][100];
ifstream f("lab.in");
f >> n >> m;
for (int i = 0; i < n; ++ i )
	for (int j = 0; j < m; ++j )
		f  >> matrix[i][j];
f >> l >> c;
cout << shortest(matrix, n, m, l, c) << "\n";
return 0;
}
