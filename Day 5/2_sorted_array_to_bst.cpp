#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* solve(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        
        int mid = (l + r) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = solve(nums, l, mid - 1);
        newNode->right = solve(nums, mid + 1, r);
        
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return solve(nums, 0, nums.size() - 1);
    }
};
