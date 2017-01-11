#include <iostream>
#include <cmath>
using namespace std;

void readArray ( int arr[ ], int& length ){
cin >> length;
for ( int i = 0; i < length; i ++ ) cin >> arr[i];
}

void findClosest ( int left, int right, int arr[ ], int sum ){
int index_f, index_l;
int diffabs = 32766;
while ( left < right ){
    if ( abs(sum - (arr[left] + arr[right]) < diffabs )){
        diffabs = abs( sum - (arr[left] + arr[right]));
        index_f = left;
        index_l = right;
    }
    if ( arr[left] + arr[right] > sum ) right--; else left++;
}
cout << "The numbers are " << arr[index_f]<<" and " <<arr[index_l];
}

int main()
{
    int arr[100], length, sum;
    readArray(arr, length);
    cin >> sum;
    findClosest(0, length-1, arr, sum);
    return 0;
}
