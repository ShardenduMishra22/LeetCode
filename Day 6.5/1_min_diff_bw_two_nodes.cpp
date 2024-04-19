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
    void solve(TreeNode* root,vector<int>& ans){
        if(root == NULL) return;

        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        sort(ans.begin(),ans.end());
        int i = 0,j = 1;
        int mn = INT_MAX;
        while(j < ans.size()){
            mn = min(mn,ans[j] - ans[i]);
            i++;j++;
        }
        return mn;
    }
};