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
    void push(TreeNode* root, vector<int> & v){
        if(!root){
            return;
        }
        push(root->left,v);
        v.push_back(root->val);
        push(root->right,v);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> ans;
        push(root,ans);
        sort(ans.begin(),ans.end());
        int mini = ans[0];
        int n = ans.size();
        if(ans[0]==ans[n-1]){
            return -1;
        }
        for(int i = 0 ; i<n ; i++){
            if(mini<ans[i]){
                mini = ans[i];
                break;
            }
        }
        return mini;
    }
};


// #include <climits>

// using namespace std;

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// public:
//     void solve(TreeNode* root, int& mn, int& mn2) {
//         if (root == nullptr) return;

//         if (root->val < mn) {
//             mn2 = mn;
//             mn = root->val;
//         } else if (root->val != mn && (mn2 == INT_MAX || root->val < mn2)) {
//             mn2 = root->val;
//         }

//         solve(root->left, mn, mn2);
//         solve(root->right, mn, mn2);
//     }

//     int findSecondMinimumValue(TreeNode* root) {
//         int mn = INT_MAX;
//         int mn2 = INT_MAX;
//         solve(root, mn, mn2);
//         return mn2 == INT_MAX ? -1 : mn2;
//     }
// };