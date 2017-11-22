/*

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/


class Solution {
        void totalNQueensHelper(int& counter, unordered_set<int>& visitedCol, unordered_set<int>& visited45, unordered_set<int>& visited135, int row, int& n){
            if ( row == n ) counter ++;
            for ( int col = 0; col < n; ++ col ){
                if ( visitedCol.find(col) != visitedCol.end() )
                    continue;
                if ( visited45.find(col + row) != visited45.end() )
                    continue;
                if ( visited135.find(n - 1 + col - row) != visited135.end() )
                    continue;
                
                visitedCol.insert(col);
                visited45.insert(col + row);
                visited135.insert(n - 1 + col - row);
                totalNQueensHelper(counter, visitedCol, visited45, visited135, row + 1, n );
                visitedCol.erase(col);
                visited45.erase(col + row);
                visited135.erase(n - 1 + col - row);                
            }
        }

public:
    int totalNQueens(int n) {
        unordered_set<int> visitedCol, visited45, visited135;
        int counter = 0;
        
        totalNQueensHelper(counter, visitedCol, visited45, visited135, 0, n);
        
        return counter;
    }
};
