class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        vector<int> counter(26);
        int start = 0, maxCount = 0, maxLen = 0;
        for ( int end = 0; end < s.size(); ++ end ){
            maxCount = max(maxCount, ++ counter[s[end] - 'A']);
            while (end - start + 1 - maxCount > k){
                counter[s[start] - 'A'] --;
                start ++;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};
