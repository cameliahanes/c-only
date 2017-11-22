/**

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if ( n == 0 ) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxim = 0;
        for ( int i = 0; i < matrix.size(); ++ i ){
            if ( matrix[i][0] == '1' ) dp[i][0] = 1;
            maxim = max(maxim, dp[i][0]);
        }
        for ( int i = 0; i < matrix[0].size(); ++ i ){
            if ( matrix[0][i] == '1' ) dp[0][i] = 1;
            maxim = max(maxim, dp[0][i]);
        }
        for ( int i = 1; i < matrix.size(); ++ i ){
            for ( int j = 1; j < matrix[i].size(); ++ j ){
                if ( matrix[i][j] == '1' )
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                maxim = max(maxim, dp[i][j]);
            }
        }
        return maxim * maxim;
    }
};
