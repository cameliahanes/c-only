#include <bits/stdc++.h>
using namespace std;

int minn[100];


int main(){
int n;
cin >> n;
int s[100];
/// coins
for (int  i =0; i < n; ++ i ) cin >> s[i];
/// set min nr of coins for the sum
int sum;
cin >> sum;
for (int i = 0; i <= sum; ++ i )
	minn[i] = INT_MAX;
minn[0] = 0;


for (int i = 1; i <= sum; ++ i ){
	for (int j = 0; j < n; ++ j ){
		if ( s[j] <= i && minn[i - s[j]] + 1 < minn[i] )
			minn[i] = minn[i - s[j]] + 1;
	}
}

cout << minn[sum];

return 0;
}
