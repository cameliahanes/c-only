/**

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

*/

class Node {
public:
    unordered_map<char, Node*> children;
    bool isEnd;
    char c; 
    
    Node(char c){
        this->c = c;
        isEnd = false;
    }    
};

class Trie {
public:
    Node* root;
    
    Trie(){
        this->root = new Node('0');
    }
    
    void insertWord(string word){
        Node* current = root;
        for ( int i = 0; i < word.size(); ++ i ){
            if ( current->children.find(word[i]) == current->children.end() )
                current->children[word[i]] = new Node(word[i]);
            current = current->children[word[i]];
        }
        current->isEnd = true;
    }
    
    int indexOfSearch(string longword){
        if ( longword.size() == 0 ) return 0;
        Node* current = root;
        int i = 0;
        for ( ; i < longword.size(); ++ i ){
            if ( current->children.find(longword[i]) == current->children.end() )
                break;
            else
                if ( current->isEnd == true ) return i;
                else current = current->children[longword[i]];
        }
        
        return ( i < longword.size() && current->isEnd == true ) ? i : 0;
        
    }
    
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* trie = new Trie(); 
        for ( auto&word : dict ){
            trie->insertWord(word);
        }
        
        string newString = "";
        std::stringstream ss(sentence);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> ssentence(begin, end);
        
        for ( auto& s : ssentence ){
            int index = trie->indexOfSearch(s);
            if ( index == 0 )
                newString += s;
            else
                newString += s.substr(0, index);
            newString += " ";
        }
        newString.pop_back();
        return newString;
    }
};
