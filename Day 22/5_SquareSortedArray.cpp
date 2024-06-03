#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums[0] >= 0) {
            vector<int> ans;
            for(auto i : nums) {
                ans.push_back(i * i);
            }
            return ans;
        }

        vector<int> ans;
        int idx = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            for(auto i : nums) {
                ans.push_back(i * i);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }

        int i = idx - 1, j = idx;

        while(i >= 0 && j < nums.size()) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if(a > b) {
                ans.push_back(b);
                j++;
            } else {
                ans.push_back(a);
                i--;
            }
        }

        while(i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }

        while(j < nums.size()) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }

        return ans;
    }
};
