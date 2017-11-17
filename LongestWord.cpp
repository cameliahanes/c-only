/**

Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

*/


class Node{
    Node* root;
    char c;
    unordered_map<char, Node*> children;
    int end;
    
public:
    Node(char c){
        this->c = c;  
        this->end = -1;
    }
    
    unordered_map<char, Node*> getChildren(){
        return children;
    }
    
    void insertChild(char c){
        children[c] = new Node('c');
    }
    
    void setEnd(int index){
        this->end = index;
    }
    
    int getEnd(){
        return end;
    }
    
};


class Trie{
    Node* root;
    vector<string> words;
    
public:
    Trie(){
        root = new Node('0');
    }
    
    void setWords(vector<string> w){
        this->words = w;
    }
    
    void insert(string word, int index){
        Node* current = root;
        for ( char c : word ){
            if (current->getChildren().find(c) == current->getChildren().end() )
                current->insertChild(c);
            current = current->getChildren()[c];
        }
        current->setEnd(index);
    }
    
    string dfs(){
        string ans = "";
        stack<Node*> st;
        st.push(root);
        while ( !st.empty() ){
            Node* node = st.top();
            st.pop();
            if ( node->getEnd() > 0 || node == root ){
                if ( node != root ){
                    string word = words[node->getEnd() - 1];
                    if ( word.size() > ans.size() || word.size() == ans.size() && strcmp(word.c_str(), ans.c_str()) < 0)
                        ans = word;
                }
                for ( auto& nei : node->getChildren())
                    st.push(nei.second);
            }
        }
        return ans;
    }
    
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        int index = 0;
        for ( string w : words )
            trie->insert(w, ++index);
        trie->setWords(words);
        return trie->dfs();
        return "";
    }
};
