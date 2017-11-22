
/**

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.


*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if ( nums.size() == 0 || nums.size() == 1 ) return false;
        set<int> s;
        for ( int i = 0; i < nums.size() ; ++ i ){
            auto index = s.lower_bound(nums[i] - t);
            if ( index != s.end() && *index - nums[i] <= t ) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
