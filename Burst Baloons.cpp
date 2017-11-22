/*

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
   
   */
   
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if ( n == 0 ) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        /// we populated the dp vector with 0 values
        /// the final answer will be given by dp[0][nums.size()], which represents the maximum number of coins obtained after removing
        /// the elements from the entire interval [0 : nums.size()];
        
        for ( int length = 1; length <= n; ++ length ){
            for ( int i = 0; i <= n - length; ++ i ){
                /// j will be the upper limit we reach while we consider the subarrays of length equal to 'length'
                int j = i + length - 1; 
                for ( int k = i; k <= j; ++ k ){
                    /// k indicates the element which is considered at every state
                    /// inside this loop we decide which element gives us the maximum number of coins if removed first
                    int leftVal = i == 0 ? 1 : nums[i - 1];
                    int rightVal = j == n - 1 ? 1 : nums[j + 1];
                    /// leftVal and rightVal contain the values which the currently removed eleemnt can be multiplied with
                    /// these variables are the neighbors inside the initial array (1 if the considered element is at the boundary
                    /// of the considered interval of size 'length')
                    
                    int before = k == i ? 0 : dp[i][k - 1];
                    int after = k == j ? 0 : dp[k + 1][j];
                    /// the elements that have been previously computed for the subinterval that contains the currently considered
                    /// new interval
                    
                    dp[i][j] = max ( dp[i][j], nums[k] * leftVal * rightVal + before + after );
                }
            }
        }
        return dp[0][n - 1];
    }
};
