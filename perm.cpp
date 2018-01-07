#include <bits/stdc++.h>
using namespace std;

int p;
void perm(int N, int index, bool visited[]){
	if (index > N){
		p ++;
	}	
		for (int i = 1; i <= N; ++ i ){
			if (!visited[i] && (index % i == 0 || i % index == 0)){
			visited[i] = true;
			perm(N, index + 1, visited);
			visited[i] = false;	
		}}
			
}

int main(){
bool visited[100];
int N;
cin >> N;
for (int i = 1; i <= N; ++ i ) visited[i] = false;
perm(N, 1, visited);
cout << p;
return 0;
}
