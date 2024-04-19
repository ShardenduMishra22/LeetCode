#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for(int i = 0;i < n;i++){
            sum -= nums[i];
        }
        return sum;
    }
};

// First approach
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int len = nums.size();
//         vector<bool> ans(len + 1, false);
        

        
//         for(int i = 0; i < len; i++){
//             ans[nums[i]] = true;
//         }
        
//         int missing = -1;
//         for(int i = 0; i < len + 1; i++){
//             if(ans[i] == false) {
//                 missing = i;
//                 break;
//             }
//         }
        
//         return missing;
//     }
// };
