#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//#include <Lime.h>
#define CLASS1234_H
using namespace std;

//find out if there are any four numbers that sum up to zero
//the same element can be used multiple times

//MEET IN THE MIDDLE technique
//we store all possible sums a + b in a hash set S
//then iterate through all n^2 combinations for c and d and
//check if S contains -(c+d)

class Solution{

public:
    vector<vector<int> > fourSum(vector<int> &num, int target){
        sort(num.begin(), num.end());
        set<vector<int> >rs;
        int n = num.size();
        for ( int i = 0; i < n-3; i ++){
            for (int j = i+1; j < n-3; j ++){
                int p = j+1;
                int q = n-1;
                while( p < q ){
                    int sum = num[i] + num[j] + num[p] + num[q];
                    if ( sum == target ){
                        vector<int> tmp(4);
                        tmp[0] = num[i];
                        tmp[1] = num[j];
                        tmp[2] = num[p];
                        tmp[3] = num[q];
                        rs.insert(tmp);
                        p ++;
                        q --;
                    } else if ( sum < target ){
                    p ++; } else { q --; }
                }

            }
        }
        vector<vector<int> > result(rs.begin(), rs.end());
        return result;
    }

};

