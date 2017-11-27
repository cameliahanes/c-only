class Solution{
public: 
    bool exist(vector<vector<char>>& board, string& word) {
        for (int y=0; y<board.size(); y++) {
            for (int x=0; x<board[y].size(); x++) {
                if (existss(board, y, x, word, 0)) return true;
            }
        }
        return false;
    }

private:
    bool existss(vector<vector<char>>& board, int y, int x, string& word, int i) {
        if (i == word.size()) return true;
        if (y<0 || x<0 || y == board.size() || x == board[y].size()) return false;
        if (board[y][x] != word[i]) return false;
        board[y][x] ^= 256;
        bool exists = existss(board, y, x+1, word, i+1)
            || existss(board, y, x-1, word, i+1)
            || existss(board, y+1, x, word, i+1)
            || existss(board, y-1, x, word, i+1);
        board[y][x] ^= 256;
        return exists;
    }
};
