#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int remainder = 0;
        for (int i = 0; i < nums.size(); i++) {
            remainder = ((remainder << 1) + nums[i]) % 5;
            ans.push_back(remainder == 0);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) {
//         uint64_t num = 0;
//         vector<bool> ans;
//         for(uint64_t i = 0; i < nums.size(); i++) {
//             num = (num << 1) | nums[i];
//             ans.push_back(num % 5 == 0); 
//         }
//         return ans;
//     }
// };
