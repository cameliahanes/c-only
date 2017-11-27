/**

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*/


class Solution {
    void dfs(int index, string& s, vector<string>& path, vector<vector<string>>& res){
        if ( index == s.size() ) {
            res.emplace_back(path);
            return;
        }
        
        for ( int i = index; i < s.size(); ++ i ){
            if ( isPalindrome(s, index, i)){
                path.emplace_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, res);
                path.pop_back();
            }
        }
        
    }
    
    
    bool isPalindrome(string& s, int start, int end){
        while ( start < end ){
            if ( s[start ++] != s[end -- ])
                return false;
        }
        return true;
    }    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if ( s.size() == 0 ) return res;
        vector<string> temp;
        int index = 0;
        int last = 0;
        dfs(index, s, temp, res);
        return res;
    }
};
