/**

Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]


*/

class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        vector<int> lastNr(10, 0);
        for ( int i = 0; i < number.size(); ++ i )
            lastNr[number[i]- '0'] = i;
        
        for ( int i = 0; i < number.size(); ++ i ){
            for ( int d = 9; d > number[i] - '0'; -- d ){
                if ( lastNr[d] > i ){
                    swap(number[i], number[lastNr[d]]);
                    return atoi(number.c_str());
                }
            }
        }
        return num;
    }
};
