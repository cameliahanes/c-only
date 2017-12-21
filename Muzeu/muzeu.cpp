#include <bits/stdc++.h>
using namespace std;

int N;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
queue<pair<int, int> > q;

bool valid(int i, int j, vector<vector<int> >& m){
	if (i < 0 || j < 0 || i >= N || j >= N)
		return false;
	if (m[i][j] == 0)
		return false;
	return true;
}

int main(){
ifstream f("muzeu.in");
f >> N;
vector<vector<int> > m(N, vector<int>(N));
for (int i = 0; i < N; ++ i ){
	for (int j = 0; j < N; ++ j ){
		char a;
		f >> a;
		if (a == '#')
			m[i][j] = -2;
		else if (a == 'P'){
			m[i][j] = 0;
			q.push(make_pair(i, j));
		}
		else
			m[i][j] = -1;
	}
}

while (!q.empty()){
	pair<int, int> pos = q.front();
	q.pop();
	for (int k = 0; k < 4; ++ k ){
		int row = pos.first + di[k];
		int col = pos.second + dj[k];

		if (valid(row, col, m) && m[row][col] == -1 ){
			m[row][col] = m[pos.first][pos.second] + 1;
			q.push(make_pair(row, col));
		}
	}
}

for (int i = 0; i < N; ++ i ){
	for (int j = 0; j < N; ++ j ){
		cout << m[i][j] <<" ";
	}
cout << "\n";
}

return 0;
}
