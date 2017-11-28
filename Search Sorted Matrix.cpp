class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.size() == 0 ) return false;
        if ( matrix[0].size() == 0 ) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m * n - 1;
        while ( left != right ){
            int mid = (left + right - 1) >> 1;
            if ( matrix[mid / m][mid % m] < target )
                left = mid + 1;
            else
                right = mid;
        }
        return matrix[right / m][right % m] == target;
    }
};
