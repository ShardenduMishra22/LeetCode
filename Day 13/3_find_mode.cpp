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
    void solve(TreeNode* root, map<int, int>& ans, int& mx_occ) {
        if (root == NULL) {
            return;
        }
        solve(root->left, ans, mx_occ);
        ans[root->val] += 1;
        mx_occ = max(mx_occ, ans[root->val]);
        solve(root->right, ans, mx_occ);
    }

    vector<int> findMode(TreeNode* root) {
        map<int, int> ans;
        vector<int> res;
        int mx_occ = 0;
        solve(root, ans, mx_occ);
        for (auto i : ans) {
            if (i.second == mx_occ) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
