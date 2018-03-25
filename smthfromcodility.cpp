// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> s;

    for(unsigned int i = 0; i < A.size(); ++ i){
        s.insert(A[i]);
    }    
    int number = 1;
    while (s.find(number) != s.end())
        number ++;
    return number;
}
