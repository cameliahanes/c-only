#include <bits/stdc++.h>
using namespace std;
#define MAX 500

/// lookup is going to store minimum value in nums[i ... j] 
vector<vector<int> > lookup(MAX, vector<int>(MAX));

class Solution{
public:
	void buildSparseTable(vector<int>& nums){
		int n = nums.size();
		/// initialize M for the intervals with size 1	
		for (int i = 0; i < n; ++ i ){
			lookup[i][0] = nums[i];
		}
		/// compute values from smaller to hight=er intervals
		for (int j = 1; (1 << j) <= n; ++ j ){
			/// compute minimum for all intervals of sizde (1 << j)
			for (int i = 0; (i + (1 << j) - 1) < n; ++ i ){
				if (lookup[i][j - 1] < lookup[i + (1 <<(j - 1))][j - 1])
					lookup[i][j] = lookup[i][j - 1];
				else
					lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
			}
		}
	}

	int query(int l, int r){
		/// find highest power of 2 that is smaller tham or equal to count of elements in given range
		int j = (int)log2(r - l + 1);
		if (lookup[l][j] <= lookup[r - (1 << j) + 1][j] ) 
			return lookup[l][j];
		else
			return lookup[r - (1 << j) + 1][j];
	}

};


int main(){
	Solution s;
return 0;
}



