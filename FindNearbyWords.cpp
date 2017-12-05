#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
        /// kinf od wrapper for a well defined (somewhere) function that checks for the given word in some trie i guess :)
        bool isWord(string s){ return true; }

        /// i ve just given som examples, in the whole project there l be for all chars :) 
        string nearbychars(char c){
                if (c == 'h' ) return "jg";
                if (c == 'o') return "po";
                if (c == 'a') return "s";
                return "#";
        }

        void nearbyperm(set<string>& res, string& helper, string s, unsigned int index){
                if (index == s.size() ){
                if ( isWord(helper) )
                        res.insert(helper);
                    return;
                }

                string c =  this->nearbychars(s[index]);
                helper += s[index];
                nearbyperm(res, helper, s, index + 1);
                helper.pop_back();
                for (unsigned int i = 0; i < c.size(); ++ i ){
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

