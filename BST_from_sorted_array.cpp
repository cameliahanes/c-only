#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    TreeNode(int &val): value{val}, left{NULL}, right{NULL}{
    }

    int value;
    TreeNode* left, *right;
};

TreeNode* create_bst(int start, int finish, vector<int> arr){
    if ( finish < start )
        return NULL;
    int mid = (start + finish)/2;

    TreeNode* n = new TreeNode(arr[mid]);
    n->left = create_bst(start, mid-1, arr);
    n->right = create_bst(mid+1, finish, arr);
    return n;
}


void print_bst(TreeNode* t){
    if ( t == NULL )
        return;
    cout << t->value << "\n";
    print_bst(t->left);
    print_bst(t->right);
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode* t = create_bst(0, arr.size()-1, arr);
    print_bst(t);

    return 0;
}
