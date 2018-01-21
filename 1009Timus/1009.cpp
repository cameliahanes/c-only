#include <bits/stdc++.h>
using namespace std;

long long dp[20][20];

int main(){
int n, k;
cin >> n >> k;

dp[1][0] = 0;

/// numbers of 1 digit k-based (<k indicates that we can only use digits less than k)
for (int first = 1; first < k; ++ first)
	dp[1][first] = 1;

for (int len = 1; len < n; ++ len ){
	/// numbers with length = len
	for (int last = 0; last < k; ++ last){
		/// parse for each digit between 0 and k
		if ( dp[len][last] > 0 ){
			/// if we have numbers of length len that are last-based
			for (int next = 0; next < k; ++ next){
				if (last == 0 and next == 0) continue;
				/// if we can ensure that we have no successive zeros, then
				/// we can add to the new solution the previous solution found
				/// and this happens for each possible next digit
				dp[len + 1][next] += dp[len][last];
			}
		}
	}
}

long long res = 0;
/// the solution will be compound of the solutions found for each possible last digit
for (int last = 0; last < k; ++ last )
	res += dp[n][last];
cout << res <<"\n";
return 0;
}
