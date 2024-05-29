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
    int solve(TreeNode* root, int& max_len) {
        if (root == nullptr) {
            return 0;
        }

        int left_len = solve(root->left, max_len);
        int right_len = solve(root->right, max_len);
        max_len = max(max_len, left_len + right_len);

        return 1 + max(left_len, right_len);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int max_len = 0;
        solve(root, max_len);
        return max_len;
    }
};
