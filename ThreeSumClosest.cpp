#include <iostream>
#include <algorithm>
using namespace std;

void read ( int nums[ ], int& length, int& target ){
    cin >> length;
    for ( int i = 0; i < length; i ++ )
        cin >> nums[i] ;
    cin >> target;
}

void sortArray ( int length, int nums[ ] ){
    bool temp ;
    do {
            temp = true;
        for ( int i = 0; i < length-1; i ++ ){
            if ( nums[i] >= nums[i+1] ){
                swap ( nums[i], nums[i+1] );
                temp = false;
            }
        }
    } while ( !temp );

}


int threeSumClosest ( int nums[ ], int length, int target ){
int mini = 32766;
int result = 0 ;
        sortArray(length, nums);

        for ( int i = 0; i < length; i++ ){
            int j = i + 1;
            int k = length - 1;
            while ( j < k ){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if ( diff == 0 )
                    return sum;
                if ( diff < mini ){
                    mini = diff;
                    result = sum;
                }
                if ( sum <= target )
                    j ++;
                else
                    k --;
            }

        }
        return result;
}


int main()
{
    int nums[100], length, target;
    read(nums, length, target);
    cout << threeSumClosest(nums, length, target);
    return 0;
}
