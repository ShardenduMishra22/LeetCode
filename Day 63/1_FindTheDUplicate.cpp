#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0;i < n;i++){
//             for(int j = i + 1;j < n;j++){
//                 if(nums[i] == nums[j]){
//                     return nums[i];
//                 }
//             }
//         }
//         return n;
//     }
// };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int,int> m;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]] += 1;
//         }
//         for(auto i : m){
//             if(i.second > 1){
//                 return i.;
//             }
//         }
//         return 0;
//     }
// };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for(int i : nums){
//             int idx = abs(i);
//             if(nums[idx] < 0){
//                 return idx;
//             }
//             nums[idx] = - nums[idx];
//         }
//         return n;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do{ 
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};