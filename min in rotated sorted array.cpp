#include <iostream>

using namespace std;

void read ( int& length, int nums[ ] ){
cin >> length;
for ( int i = 0; i < length; i++ ){
    cin >> nums[i];
}
}

int findMinimum ( int left, int right, int nums[ ] ){
if ( left == right )
    return nums[left];

if ( right-left == 1 )
    return min ( nums[left], nums[right] );

int middle = left + (right - left ) / 2;

    if ( nums[left]  < nums[right ] ) //if it is sorted
        return nums[left];
    else {
        if ( nums[middle] >= nums[left] )
            return findMinimum( middle, right, nums );
        else return findMinimum( left, middle, nums );
    }
}

int main()
{
    int nums[100], length;
    read(length, nums);
    cout << findMinimum(0, length-1, nums);
    return 0;
}
