#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(auto i : nums){
            n = n ^ i;
        }
        return n;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = 0;
//         for(int i = 0;i < nums.size();i++){
//             n = n ^ nums[i];
//         }
//         return n;
//     }
// };