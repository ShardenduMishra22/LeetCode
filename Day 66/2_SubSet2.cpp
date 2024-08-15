#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& arr, vector<int>& res, vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            arr.push_back(res);
            return;
        }

        res.push_back(nums[idx]);
        solve(arr, res, nums, idx + 1);
        res.pop_back();

        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        solve(arr, res, nums, idx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> res;
        sort(nums.begin(), nums.end());
        solve(arr, res, nums, 0);
        return arr;
    }
};
