#include <bits/stdc++.h>
using namespace std;

void process(string pattern, int F[]){
    F[0] = 0;
    int i = 1, j = 0;
    while( i < pattern.size() ){
        if ( pattern[i] == pattern[j] ){
            j ++;
            F[i] = j;
            i++;
        }
        else {
            if ( j != 0 ){
                j = F[j-1];
            } else {
            F[i] = 0; i++;
            }
        }
    }
}

vector<int> kmp(string text, string pattern){
    int n = text.size(), m = pattern.size();
    int F[m+1];
    process(pattern, F);
    int i = 0, j = 0;
    vector<int> matches;
    while(i < n){

    if ( pattern[j] == text[i]){
        i ++; j++;
    }
    if ( j == m ) {
        matches.push_back(i-j);
        j = F[j-1];
    }
    else if ( i < n && pattern[j] != text[i] ){
        if ( j != 0 )
            j = F[j-1];
        else
            i ++;
    }
    }
    return matches;
}

int main()
{
    string text = "ABABAC", pattern = "ABA";
    vector<int> matches = kmp(text, pattern);

    for(int i = 0; i < matches.size(); ++ i )
            cout << matches[i] << " ";
        return 0;
}
