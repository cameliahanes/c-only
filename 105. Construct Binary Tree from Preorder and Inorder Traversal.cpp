/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
class Solution {
    int search(vector<int>& v, int elem, int start, int end){
        for ( int i = start; i <= end; ++ i )
            if ( v[i] == elem ) return i;
        return -1;
    }
    
    TreeNode* buildHelper(vector<int>& preorder, int startp, int endp, vector<int>& inorder, int starti, int endi){
        if ( startp > endp ) return NULL;
        
        int index_in_inorder = search(inorder, preorder[startp], starti, endi);
        
        TreeNode* root = new TreeNode(preorder[startp]);
        root->left = buildHelper(preorder, startp + 1, startp + index_in_inorder - starti, inorder, starti, index_in_inorder - 1);
        root->right = buildHelper(preorder, endp - endi + index_in_inorder + 1, endp, inorder, index_in_inorder + 1, endi);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
