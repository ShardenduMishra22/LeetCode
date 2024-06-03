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
    void solve(TreeNode* root, long long& ans, int num) {
        if (root == NULL) {
            return;
        }
        num = (num << 1) | root->val;
        if (root->left == NULL && root->right == NULL) {
            ans += num;
            return;
        }
        solve(root->left, ans, num);
        solve(root->right, ans, num);
    }

    int sumRootToLeaf(TreeNode* root) {
        long long ans = 0;
        int num = 0;
        solve(root, ans, num);
        return ans;
    }
};

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
//     long long binTodec(long long n) {
//         long long ans = 0, base = 1;
//         while (n != 0) {
//             int a = n % 10;
//             ans += a * base;
//             base *= 2;
//             n /= 10;
//         }
//         return ans;
//     }

//     void solve(TreeNode* root, long long& ans, long long num) {
//         if (root == NULL) {
//             return;
//         }
//         num = num * 10 + root->val;
//         if (root->left == NULL && root->right == NULL) {
//             ans += binTodec(num);
//             return;
//         }
//         solve(root->left, ans, num);
//         solve(root->right, ans, num);
//     }

//     int sumRootToLeaf(TreeNode* root) {
//         long long ans = 0;
//         long long num = 0;
//         solve(root, ans, num);
//         return ans;
//     }
// };