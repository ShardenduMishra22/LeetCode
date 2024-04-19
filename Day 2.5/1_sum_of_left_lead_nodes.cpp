#include<bits/stdc++.h>
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
    TreeNode* solve(TreeNode* root, int& ans) {
        if (root == NULL) return NULL;

        TreeNode* left = solve(root->left, ans);
        TreeNode* right = solve(root->right, ans);
        
        if (left != NULL && left->left == NULL && left->right == NULL) {
            ans += left->val;
        }
    
        return root;
    }


    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};