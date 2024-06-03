#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool solve(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left != NULL && root->left->val != root->val) {
            return false;
        }
        if (root->right != NULL && root->right->val != root->val) {
            return false;
        }
        return solve(root->left) && solve(root->right);
    }

    bool isUnivalTree(TreeNode* root) {
        return solve(root);
    }
};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution sol;
    cout << (sol.isUnivalTree(root) ? "True" : "False") << endl; 

    return 0;
}
