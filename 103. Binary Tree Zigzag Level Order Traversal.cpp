/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 
 PROBLEM STATEMENT:
 
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 
 
 */
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if ( root == NULL ) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode*> s;
        s.push(root);
        bool direction = true;
        while ( !s.empty() ){
            queue<TreeNode*> saux;
            vector<int> temp(s.size());
            int i = 0;
            int n = s.size();
            while ( !s.empty() ){
                TreeNode* t = s.front();
                s.pop();
                int index = direction ? i : (n - i - 1);
                temp[index] = t->val;
                if ( t->left ) saux.push(t->left);
                if ( t->right ) saux.push(t->right);
                i ++;
            }
            s = saux;
            res.emplace_back(temp);
            direction = !direction;
            
        }
        return res;
    }
};
