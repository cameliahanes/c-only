#include <iostream>
#define min_abs -32767
using namespace std;
struct subarray{
    int max_left;
    int max_right;
    int max_sum;
};

subarray find_max_crossing_subarray(int A[], int low, int mid, int high){
subarray s;
int left_sum = min_abs;
int sum = 0;
for ( int i = mid; i >= low; i --){
    sum = sum + A[i];
    if ( sum > left_sum ){
        left_sum = sum;
        s.max_left = i;
    }
}
int right_sum = min_abs;
sum = 0;
for ( int j = mid+1; j <= high; j ++ ){
    sum = sum + A[j];
    if ( sum > right_sum ){
        right_sum = sum;
        s.max_right = j;
    }
}
s.max_sum = left_sum + right_sum;
return s;
}

subarray find_max_subarray(int A[], int low, int high){
if ( high == low ){
    subarray ss;
    ss.max_left = low;
    ss.max_right = high;
    ss.max_sum = A[low];
    return ss;
} else {
    int mid = (low + high) /2;
    subarray s1 = find_max_subarray(A, low, mid);
    subarray s2 = find_max_subarray(A, mid+1, high);
    subarray cross = find_max_crossing_subarray(A, low, mid, high);
    if ( s1.max_sum >= s2.max_sum ){
        return s1;
    } else if ( s2.max_sum >= s1.max_sum ){
    return s2; } else return cross;
}

}


int main()
{
    int n, a[100];
    cin >> n;
    for ( int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    subarray s = find_max_subarray(a, 0, n-1);
    cout << s.max_left << " " << s.max_right << "\n";
    for ( int i = s.max_left; i <= s.max_right; i ++ ){
        cout << a[i] << " ";
    }
    return 0;
}
