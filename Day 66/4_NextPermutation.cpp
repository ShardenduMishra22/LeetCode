#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                idx = i - 1;
                break;
            }
        }        
        if (idx != -1) {
            int swp = n - 1;
            for (int j = n - 1; j > idx; j--) {
                if (nums[j] > nums[idx]) {
                    swp = j;
                    break;
                }
            }
            swap(nums[swp], nums[idx]);
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
};

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(),nums.end());
//     }
// };