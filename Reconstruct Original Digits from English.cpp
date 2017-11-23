/**

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"

*/


class Solution {
public:
    string originalDigits(string s) {
        vector<int> counter(10, 0);
        for ( int i = 0; i < s.size(); ++ i ){
            char c = s[i];
            if ( c == 'z' )
                counter[0] ++;
            if ( c == 'w' )
                counter[2] ++;
            if ( c == 'x' )
                counter[6] ++;
            if ( c == 's')
                counter[7] ++;
            if ( c == 'g' )
                counter[8] ++;
            if ( c == 'u' )
                counter[4] ++;
            if ( c == 'f' )
                counter[5] ++;
            if ( c == 'h' )
                counter[3] ++;
            if ( c == 'i' )
                counter[9] ++;
            if ( c == 'o' )
                counter[1] ++;
        }
        counter[7] -= counter[6];
        counter[5] -= counter[4];
        counter[3] -= counter[8];
        counter[9] = counter[9] - counter[8] - counter[5] - counter[6];
        counter[1] = counter[1] - counter[0] - counter[2] - counter[4];
        string res = "";
        for ( int i = 0; i < 10; ++ i )
            for ( int j = 0; j < counter[i]; ++ j )
                res += to_string(i);
        return res;
    }
};
