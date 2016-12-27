#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> insertion_sort_STL(vector<int> v){
    int n = v.size();
    for ( int i = 1; i < n; ++i ){
        int j = i-1;
        int key = v[i];
        while ( j >= 0 && v[j] > key ){
            v[j+1] = v[j];
            j-- ;
        }
        v[j+1] = key;
    }
    return v;
}

int main()
{
    vector<int> v;
    int length;
    cin >> length;
    int input;
    while ( length >0 ){
            cin >> input;
        v.push_back(input);
        --length;
    }
    v = insertion_sort_STL(v);

    vector<int>::iterator it;
    for ( it = v.begin(); it != v.end(); it ++ ){
        cout << *it << " ";
    }
    return 0;
}
