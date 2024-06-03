// Level Order Traversal
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
    void solve(TreeNode* root, map<int, vector<int>>& m, int level) {
        if (root == nullptr)
            return;
        
        m[level].push_back(root->val);
        solve(root->left, m, level + 1);
        solve(root->right, m, level + 1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        map<int, vector<int>> m;
        int level = 0;
        solve(root, m, level);
        
        for (auto i : m) {
            double sum = 0;
            for (int val : i.second) {
                sum += val;
            }
            ans.push_back(sum / i.second.size());
        }
        return ans;
    }
};