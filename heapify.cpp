#include <iostream>
#include <vector>
using namespace std;

int left_side(int i){ return 2*i; }
int right_side(int i){ return 2*i + 1; }

void max_heapify(vector<int> &a, int i){
    int l = left_side(i);
    int r = right_side(i);
    int largest;
    if ( l <= a.size() and a[l] > a[i] ){
        largest = l;
    } else { largest = i; }
    if ( r <= a.size() and a[r] > a[largest] ){
        largest = r;
    }
    if ( largest != i ){ swap(a[i], a[largest]);
        max_heapify(a, largest);
     }
}

void build_max_heap(vector<int> &a){
    for ( int i = a.size()/2; i >= 1; i -- ){
        max_heapify(a, i);
    }
}

void heapsort(vector<int> &a){
    int len = a.size();
    for ( int i = len; i >= 2; i --){
        swap(a[1], a[i]);
        max_heapify(a, 1);
        len --;
    }
}

void print_heap(vector<int> &a){
for ( int i = 1; i <= a.size(); i ++)
    cout << a[i] <<" ";
}

int main()
{
    vector<int> a; // = [1, 7, 3, 4, 2, 5, 6, 9, 11, 2];
    int n;
    cin >> n;
    while ( n ){
        int input;
        cin >> input;
        a.push_back(input);
        n --;
    }
    heapsort(a);
    print_heap(a);
    return 0;
}
