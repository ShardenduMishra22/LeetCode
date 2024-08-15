// class Solution {
// public:
//     void solve(vector<vector<int>>& ans, vector<int>& ds, int idx, vector<int>& cndt, int trg) {
//         if (trg == 0) {
//             ans.push_back(ds);
//             return;
//         }
//         if (idx == cndt.size() || trg < 0) {
//             return;
//         }

//         for (int i = idx; i < cndt.size(); i++) {
//             if (i > idx && cndt[i] == cndt[i - 1]) continue;
//             if (cndt[i] > trg) break;
//             ds.push_back(cndt[i]);
//             solve(ans, ds, i + 1, cndt, trg - cndt[i]);
//             ds.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& cndt, int trg) {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         sort(cndt.begin(), cndt.end());
//         solve(ans, ds, 0, cndt, trg);
//         return ans;
//     }
// };

// // class Solution {
// // public:
// //     void solve(vector<vector<int>>& ans, vector<int>& ds, int idx, vector<int>& cndt, int trg) {
// //         if (trg == 0) {
// //             ans.push_back(ds);
// //             return;
// //         }
// //         if (idx == cndt.size() || trg < 0) {
// //             return;
// //         }

// //         for (int i = idx; i < cndt.size(); i++) {
// //             if (i > idx && cndt[i] == cndt[i - 1]) continue;
// //             if (cndt[i] > trg) break;
// //             ds.push_back(cndt[i]);
// //             solve(ans, ds, i + 1, cndt, trg - cndt[i]);
// //             ds.pop_back();
// //         }
// //     }

// //     vector<vector<int>> combinationSum2(vector<int>& cndt, int trg) {
// //         vector<vector<int>> ans;
// //         vector<int> ds;
// //         sort(cndt.begin(), cndt.end());
// //         solve(ans, ds, 0, cndt, trg);
// //         return ans;
// //     }
// // };

// // class Solution {
// // public:
// //     void solve(map<vector<int>,bool>& m,vector<vector<int>>& ans, vector<int>& ds, int idx, vector<int>& cndt, int trg) {
// //         if (trg == 0 && !m[ds]) {
// //             ans.push_back(ds);
// //             m[ds] = true;
// //             return;
// //         }
// //         if (idx == cndt.size()) {
// //             return;
// //         }

// //         if (cndt[idx] <= trg) {
// //             ds.push_back(cndt[idx]);
// //             solve(m,ans, ds, idx + 1, cndt, trg - cndt[idx]);
// //             ds.pop_back();
// //         }

// //         solve(m,ans, ds, idx + 1, cndt, trg);
// //     }

// //     vector<vector<int>> combinationSum2(vector<int>& cndt, int trg) {
// //         vector<vector<int>> ans;
// //         vector<int> ds;
// //         map<vector<int>,bool> m;
// //         sort(cndt.begin(),cndt.end());
// //         solve(m,ans, ds, 0, cndt, trg);
// //         return ans;
// //     }
// // };