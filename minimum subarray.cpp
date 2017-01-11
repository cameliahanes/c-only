#include <iostream>

using namespace std;

void read ( int& length, int nums[ ], int& s ){
cin >> length;
for ( int i = 0; i < length; i ++ )
    cin >> nums[i];
cin >> s;
}

int minSubarrayLen ( int length, int s, int nums[ ] ){
if ( nums == NULL || length == 1 )
    return 0;

int result = length;
int start = 0;
int sum = 0;
int i = 0;
bool exists = false;

    while ( i <= length ){
        if ( sum >= s ){
            exists = true; //mark if there existst suc a subarray
            if ( start == i-1 )
                return 1;
            result = min ( result, i-start );
            sum = sum - nums[start];
            start ++;
        } else {
            if ( i == length )
            break;
            sum = sum + nums[i];
            i ++;
        }

    }
if ( exists )
    return result;
else
    return 0;
}

int main()
{
    int nums[100], length, s;
read(length, nums, s);
cout << minSubarrayLen(length, s, nums);
    return 0;
}
