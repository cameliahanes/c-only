/**

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

*/



class TrieNode {
public:
    map<char, TrieNode*> children;
    string word;
};



class Solution {
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for ( string w : words ){
            TrieNode* p = root;
            for ( char c : w ){
                if ( p->children.find(c) == p->children.end() )
                    p->children[c] = new TrieNode();
                p = p->children[c];
            }
            p->word = w;
        }
        return root;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        for ( int i = 0; i < board.size(); ++ i ){
            for ( int j  =0; j < board[i].size(); ++ j )
                dfs(board, i, j, root, res);
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res){
        char c = board[i][j];
        if ( c == '#' || p->children.find(c) == p->children.end() )
            return;
        p = p->children[c];
        if ( p->word.size() ){
            res.emplace_back(p->word);
            p->word = "";
        }
        
        board[i][j] = '#';
        if ( i > 0 )
            dfs(board, i - 1, j, p, res);
        if ( j > 0 )
            dfs(board, i, j - 1, p, res);
        if ( i < board.size() - 1 )
            dfs(board, i + 1, j, p, res);
        if ( j < board[0].size() - 1 )
            dfs(board, i, j + 1, p, res);
        board[i][j] = c;
    }
    
};
