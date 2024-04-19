#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> seen(nums.size()+1);
        vector<int> ans;
        for(auto c : nums) seen[c] = true;
        for(int i = 1; i <= nums.size(); i++)
            if(!seen[i]) ans.push_back(i);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int len = nums.size();
//         vector<int> ans(len + 1); 
//         vector<int> res;
//         for (int i = 0; i < len; i++) {
//             ans[nums[i]]++;   
//         }
//         for (int i = 1; i <= len; i++) { 
//             if (ans[i] == 0) {
//                 res.push_back(i);
//             }
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         ios_base::sync_with_stdio(0);
//         for(auto num : nums) {
//             int i = abs(num) - 1;
//             nums[i] = -1 * abs(nums[i]);
//         }
//         vector<int> ans;
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] > 0) ans.push_back(i + 1);
//         }
//         return ans;
//     }
// };