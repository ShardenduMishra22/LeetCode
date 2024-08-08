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
    void MakeGraph(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& adj) {
        if (!node) return;
        
        if (parent) {
            adj[node].push_back(parent);
            adj[parent].push_back(node);
        }

        MakeGraph(node->left, node, adj);
        MakeGraph(node->right, node, adj);
    }

    void findLeaves(TreeNode* node, unordered_set<TreeNode*>& leaves) {
        if (!node) return;
        if (!node->left && !node->right) {
            leaves.insert(node);
        }
        findLeaves(node->left, leaves);
        findLeaves(node->right, leaves);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leaves;
        MakeGraph(root, nullptr, adj);
        findLeaves(root, leaves);

        int cnt = 0;

        for (auto& leaf : leaves) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> vis;
            q.push(leaf);
            vis.insert(leaf);

            for (int lvl = 0; lvl <= distance; lvl++) {
                int size = q.size();
                while (size--) {
                    TreeNode* curr = q.front();
                    q.pop();

                    if (curr != leaf && leaves.count(curr)) {
                        cnt++;
                    }

                    for (auto& ngbr : adj[curr]) {
                        if (!vis.count(ngbr)) {
                            q.push(ngbr);
                            vis.insert(ngbr);
                        }
                    }
                }
            }
        }
        return cnt / 2;
    }
};  