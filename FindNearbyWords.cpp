#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
        bool isWord(string s){ return true; }

        string nearbychars(char c){
                if (c == 'h' ) return "jg";
                if (c == 'o') return "po";
                if (c == 'a') return "s";
                return "#";
        }

        void nearbyperm(set<string>& res, string& helper, string& s, int index){
                if (index == s.size()){
                if ( isWord(helper) )
                        res.insert(helper);
                }

                string c =  nearbychars(s[index]);
                for (int i = 0; i < c.size(); ++ i ){
                        helper += c[i];
                        nearbyperm(res, helper, s, index + 1);
                        helper = helper.substr(0, helper.size() - 1);
                }
        }

public:
        set<string> nearby(string s){
        set<string> Set;
        string helper = "";
        nearbyperm(Set, helper, s, 0);
        return Set;
        }
};


int main()
{
Solution s;
string ss = "aho";
set<string> res = s.nearby(ss);
set<string>::iterator it = res.begin();
for (; it != res.end(); ++ it )
        cout << *it << " ";
return 0;
}








