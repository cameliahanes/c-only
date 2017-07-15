#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twosum(vector<int>& nums, int target){
    vector<int> result;
    int i = 0, j = nums.size()-1;
    while( i < j ){
        int sum = nums[i] + nums[j];
        if ( sum == target ){
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            return result;
        } else {
        if ( sum < target )
            ++ i ;
        else
            -- j;
        }
    }
    return result;
    }
};

int main(){

    vector<int> nums = {2,8,11,15};
    Solution s;
    vector<int> nrs = s.twosum(nums, 22);
    for ( int i = 0; i < nrs.size(); ++ i )
        cout << nrs[i] << " ";
    return 0;
}
