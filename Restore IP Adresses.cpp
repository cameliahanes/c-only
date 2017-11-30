/**

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


*/

class Solution {  
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.size();
        
        for ( int i = 1; i < 4 && i < len - 2; ++ i ){
            for ( int j = i + 1; j < i + 4 && j < len - 1; ++ j ){
                for ( int k = j + 1; k < j + 4 && k < len; ++ k ){
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j - i);
                    string s3 = s.substr(j, k - j);
                    string s4 = s.substr(k);
                    if ( isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4) )
                        res.emplace_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }
        return res;
    }

private:
        bool isValid(string s){
        if ( s.size() > 3 || s.size() == 0 || (s[0] == '0' && s.size() > 1 ) || atoi(s.c_str()) > 255 )
            return false;
        return true;
    }

};
