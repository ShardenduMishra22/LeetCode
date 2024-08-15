#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& ds,vector<int>& nums,int lmt,int k,int idx){
        if(lmt == k){
            ans.push_back(ds);
            return;
        }
        if(idx >= nums.size()){
            return;
        }
        ds.push_back(nums[idx]);
        solve(ans,ds,nums,lmt+1,k,idx+1);
        ds.pop_back();
        solve(ans,ds,nums,lmt,k,idx+1);
    }

    vector<vector<int>> combine(int n, int k){
        int lmt = 0;
        vector<int>nums;
        for(int i = 1;i<=n;i++){
            nums.push_back(i);
        }
        int idx = 0;
        vector<int> ds;
        vector<vector<int>> ans;
        solve(ans,ds,nums,lmt,k,idx);
        return ans;
    }
};