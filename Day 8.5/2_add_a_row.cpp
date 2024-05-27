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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root, val, depth, 1);
        return root;
    }
    
    void solve(TreeNode* root, int val, int depth, int currDepth) {
        if (root == nullptr) return;
        
        if (currDepth == depth - 1) {
            TreeNode* leftSubtree = root->left;
            TreeNode* rightSubtree = root->right;
            
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            
            root->left = newLeft;
            newLeft->left = leftSubtree;
            
            root->right = newRight;
            newRight->right = rightSubtree;
            
            return;
        }
        
        solve(root->left, val, depth, currDepth + 1);
        solve(root->right, val, depth, currDepth + 1);
    }
};
