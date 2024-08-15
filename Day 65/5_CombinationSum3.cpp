#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& ds,int lmt,int k,int trg,vector<int>& nums,int idx){
        if(lmt == k &&  trg == 0){
            ans.push_back(ds);
            return;
        }
        if(lmt == k || trg == 0 || idx >= nums.size()){
            return;
        }

        ds.push_back(nums[idx]);
        solve(ans,ds,lmt+1,k,trg-nums[idx],nums,idx+1);
        ds.pop_back();

        solve(ans,ds,lmt,k,trg,nums,idx+1);

        return;
    }

    vector<vector<int>> combinationSum3(int k, int trg) {
        vector<int> nums;
        for(int i = 1;i <= 9;i++){
            nums.push_back(i);
        }
        int lmt = 0;
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,ds,lmt,k,trg,nums,idx);
        return ans;
    }
};