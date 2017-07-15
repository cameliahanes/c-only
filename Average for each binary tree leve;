#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
       vector<double> result;
       deque<TreeNode*> nodes;
       deque<TreeNode*> aux;

       nodes.push_back(root);
       while(!nodes.empty()){
            aux.clear();

            int ma = 0;
            int countt = 0;

            while(!nodes.empty()){
            TreeNode* tn = nodes.front();
            ma += tn->val;
            countt += 1;
            nodes.pop_front();
            if ( tn->left )
                aux.push_back(tn->left);
            if ( tn->right )
                aux.push_back(tn->right);
            }
            result.push_back((double)ma/countt);
            nodes = aux;
       }
    return result;

    }
};



int main()
{
    TreeNode* t = new TreeNode(3);
    t->left = new TreeNode(9);
    t->right = new TreeNode(20);
    t->right->left = new TreeNode(15);
    t->right->right = new TreeNode(7);
    Solution solution;
    vector<double> sol = solution.averageOfLevels(t);
    for ( int i = 0; i < sol.size(); ++i )
        cout << sol[i] << " ";
    return 0;
}
