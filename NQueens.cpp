/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


*/


class Solution {
    void solveNQueensHelper(vector<vector<string>>& res, vector<string>& nQueens, vector<int>& flagCol, vector<int>& flag45, vector<int>& flag135, int row, int& n){
        if ( row == n ){
            res.emplace_back(nQueens);
            return;
        }
        for ( int col = 0; col < n; ++ col ){
            if ( flagCol[col] && flag45[col + row] && flag135[n - 1 + col - row] ){
                nQueens[row][col] = 'Q';
                flagCol[col] = flag45[col + row] = flag135[n - 1 + col - row] = 0;
                solveNQueensHelper(res, nQueens, flagCol, flag45, flag135, row + 1, n);     
                nQueens[row][col] = '.';
                flagCol[col] = flag45[col + row] = flag135[n - 1 + col - row] = 1;
            }
        }   
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        vector<int> flagCol(n, 1), flag45(2 * n - 1, 1), flag135(2 * n - 1, 1);
        solveNQueensHelper(res, nQueens, flagCol, flag45, flag135, 0, n);
        return res;
    }
};
