/**

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/


class Solution {
public:
    int minCut(string s) {
        if ( s.size() == 0 ) return 0;
        int n = s.size();
        vector<vector<bool>> palindrom(n, vector<bool>(n, false));
        vector<int> mincut(n);
        for ( int i = n - 1; i >= 0; -- i ){
            mincut[i] = n - i - 1;
            for ( int j = i; j < n; ++ j ){
                if ( s[i] == s[j] && (j - i < 2 || palindrom[i + 1][j - 1] )){
                    palindrom[i][j] = true;
                    if ( j == n - 1 )
                        mincut[i] = 0;
                    else if (mincut[j + 1] + 1 < mincut[i] )
                        mincut[i] = mincut[j + 1] + 1;
                }
            }
        }
        return mincut[0];
    }
};
