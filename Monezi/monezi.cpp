#include <bits/stdc++.h>
using namespace std;
#define maxs 514
#define maxn 20
int N, S, v[maxn], dp[maxs], counter, res;

void backtracking(int index){
	if (index == N + 1)
		res += counter;
	else {
		for (int i = v[index]; i <= S; ++ i ){
			/// parse from the current coin to the value of max allowed sum
			if (dp[i - v[index]] && !dp[i]){
				/// if the current coin was not used so far
				dp[i] = index;	/// the sum obtained is determined by elements added up to index
				counter ++;	/// another possible sum
			}
		}
		
		backtracking(index + 1);	/// call backtracking for the next couple of coins having taken in account which sums were already obtained 
		for (int i = 0; i <= S; ++ i ){
			if (dp[i] == index){
				/// free the sums obtained for index k
				counter --;
				dp[i] = 0;
			}
		}
		backtracking(index + 1);	/// now from scratch
	}
}

int main(){
ifstream f("monezi.in");
ofstream g("monezi.out");
f >> N >> S;
for (int i = 1; i <= N; ++ i ){
	f >> v[i];	
}
dp[0] = -1;
backtracking(1);
g << res;
return 0;
}

