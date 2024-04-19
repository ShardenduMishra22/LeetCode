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
    void solve(TreeNode* root, vector<string>& ans, string& s) {
        if (root == nullptr) {
            return;
        }
        if (s != "") {
            s += "->";
        }
        s += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(s);
        }
        solve(root->left, ans, s);
        solve(root->right, ans, s);
        s = s.substr(0, s.size() - to_string(root->val).size() - 2);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) {
            return ans;
        }
        string s = "";
        solve(root, ans, s);
        return ans;
    }
};
