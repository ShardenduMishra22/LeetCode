#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nm; 
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(nm.find(complement) != nm.end()) {
                ans.push_back(nm[complement]);
                ans.push_back(i);
                return ans;
            }
            nm[nums[i]] = i;
        }
        
        return ans; 
    }
};