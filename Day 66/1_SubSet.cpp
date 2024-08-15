#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         int subsetCount = 1 << n; // 2^n subsets
//         vector<vector<int>> allSubsets;

//         for (int mask = 0; mask < subsetCount; ++mask) {
//             vector<int> subset;
//             for (int i = 0; i < n; ++i) {
//                 if (mask & (1 << i)) {
//                     subset.push_back(nums[i]);
//                 }
//             }
//             allSubsets.push_back(subset);
//         }

//         return allSubsets;
//     }
// };

class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, int idx, vector<int>& res) {
        if (idx == nums.size()) {
            ans.push_back(res);
            return;
        }

        solve(ans, nums, idx + 1, res);

        res.push_back(nums[idx]);
        solve(ans, nums, idx + 1, res);
        res.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int idx = 0;
        solve(ans, nums, idx, res);
        return ans;
    }
};