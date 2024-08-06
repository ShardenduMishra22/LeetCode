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
private:
    void in_order(TreeNode* root, vector<int>& InOrdr) {
        if (root == nullptr) return;
        in_order(root->left, InOrdr);
        InOrdr.push_back(root->val);
        in_order(root->right, InOrdr);
    }

    TreeNode* createBalancedBST(const vector<int>& InOrdr, int start, int end) {
        if (start > end) 
            return nullptr;
        
        int mid = start + (end - start) / 2;
        
        TreeNode* left = createBalancedBST(InOrdr, start, mid - 1);
        TreeNode* right = createBalancedBST(InOrdr, mid + 1, end);

        TreeNode* node = new TreeNode(InOrdr[mid]);
        node->left = left;
        node->right = right;
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> InOrdr;
        in_order(root, InOrdr);
        int size = InOrdr.size();
        return createBalancedBST(InOrdr, 0, size - 1);
    }
};