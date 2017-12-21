#include <bits/stdc++.h>
using namespace std;

int endr, endc, N, M, r, c;

bool valid(int i, int j, vector<vector<int> >& m){
	if (i < 0 || i >= N || j < 0 || j >= M)
		return false;
	if (m[i][j] == -1 ) return false;
	return true;
}

int main(){
	ifstream f("lee.in");
	f >> N >> M;
	queue<pair<int, int> > q;
	vector<vector<int> > m(N + 1, vector<int>(M + 1));
	for (int i = 0; i < N; ++ i )
		for (int j = 0; j < M; ++ j )
			f >> m[i][j];
	f >> r >> c;
	f >> endr >> endc;

	// Lee
	int di[4] = {1, 0, -1, 0};
	int dj[4] = {0, 1, 0, -1};
	q.push(make_pair(r, c));
	m[r][c] = 0;
	while (!q.empty()){
		pair<int, int> pos = q.front();
		q.pop();
		int row = pos.first;
		int col = pos.second;
		for (int k = 0; k < 4; ++ k ){
			if (valid(row + di[k], col + dj[k], m) && m[row + di[k]][col + dj[k]] < 1)
			{	q.push(make_pair(row + di[k], col + dj[k]));
				m[row + di[k]][col + dj[k]] = m[row][col] + 1;
			}
		}
		
	}
	cout << m[endr][endc] <<"\n";
	cout << "\n\n\n";
	for (int i = 0; i < N; ++ i ){
		for (int j  = 0; j < M; ++ j )
			cout << m[i][j] <<" ";
		cout << "\n";
	}
	return 0;
}


