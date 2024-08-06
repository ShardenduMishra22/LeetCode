// class Solution {
// public:
//     void solve(TreeNode* root,int& sum){
//         if(!root){
//             return;
//         }
//         solve(root->right,sum);
//         sum += root->val;
//         root->val = sum;
//         solve(root->left,sum);
//     }

//     TreeNode* bstToGst(TreeNode* root) {
//         int sum = 0;
//         solve(root,sum);
//         return root;
//     }
// };

// class Solution {
// public:
//     void solve(vector<int>& ans, TreeNode* root) {
//         if (!root) {
//             return;
//         }
//         solve(ans, root->left);
//         ans.push_back(root->val);
//         solve(ans, root->right);
//     }

//     void GST(unordered_map<int, int>& m, TreeNode* root) {
//         if (!root) {
//             return;
//         }
//         GST(m, root->left);
//         root->val = m[root->val];
//         GST(m, root->right);
//     }

//     TreeNode* bstToGst(TreeNode* root) {
//         vector<int> ans1;
//         solve(ans1, root);
//         vector<int> ans2(ans1.size() + 1, 0);
        
//         for (int i = ans1.size() - 1; i >= 0; i--) {
//             ans2[i] = ans2[i + 1] + ans1[i];
//         }

//         unordered_map<int, int> m;
//         for (int i = 0; i < ans1.size(); i++) {
//             m[ans1[i]] = ans2[i];
//         }

//         GST(m, root);
//         return root;
//     }
// };