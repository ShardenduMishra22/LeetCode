#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; // Change val to an integer
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Update constructor
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void solve(TreeNode* root, string curr, string& ans) {
        if (root == nullptr) return;

        curr = char('a' + root->val) + curr; 

        if (root->left == nullptr && root->right == nullptr) {
            if (ans.empty() || curr < ans) {
                ans = curr; 
            }
            return;
        }

        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        solve(root, "", ans);
        return ans;
    }
};