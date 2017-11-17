/**

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if ( matrix.size() == 0 ) return matrix;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX - 10000));
        
        for ( int i = 0; i < matrix.size(); ++ i ){
            for ( int j = 0; j < matrix[i].size(); ++ j ){
                if ( matrix[i][j] == 0 )
                    dp[i][j] = 0;
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        
        for ( int i = matrix.size() - 1; i >= 0; -- i ){
            for ( int j = matrix[i].size() - 1; j >= 0; -- j ){
                if (i < matrix.size() - 1 )
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                if ( j < matrix[i].size() - 1 )
                    dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
            }
        }
     
        return dp;
    }
};
