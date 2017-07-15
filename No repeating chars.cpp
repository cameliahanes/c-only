/*

Given a string, find the length of the longest substring without repeating characters.

*/


#include <bits/stdc++.h>
#include <hash_map>
using namespace std;

class Solution{
public:
    int get_length_of_max_subsequence_without_repeating_chars(string s){
        int n = s.size();
        int ans = 0;

        vector<int> index(128);

        for ( int i = 0, j = 0; j < n; ++ j ){
            i = max(index[s[j]], i);
            ans = max(ans, j-i+1);
            index[ s[j] ] = j+1;
        }
        return ans;
    }
};


int main(){
    string s = "abcabcbb";
    Solution so;
    cout << so.get_length_of_max_subsequence_without_repeating_chars(s);
    return 0;
}
