#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permute(vector<string>& res, string init, string last){
        if ( init.size() == 0 ){
            res.emplace_back(last);
            return;
        }
        for ( int i = 0; i < init.size(); ++ i ){
            string pre = init.substr(0, i);
            string post = init.substr(i + 1);
            permute(res, pre + post, init[i] + last);
        }
    }
};


int main()
{
    string s = "abc";
    vector<string> res;
    Solution ss;
    ss.permute(res, s, "");
    for ( string elem : res )
        cout << elem <<" ";
    return 0;
}
