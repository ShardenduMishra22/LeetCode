#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2) return 0;
        sort(nums.begin(),nums.end());
        int smallest=nums[0];
        int biggest=nums[n-1];
        int count=0;
        for(int i=1;i<n-1;i++)
            if(nums[i]!=smallest && nums[i]!=biggest) count++;
        return count;
    }
};

// Very Complex
// class Solution {
// public:
//     int countElements(vector<int>& nums) {
//         if(nums.size() < 2) {
//             return 0; 
//         }
//         sort(nums.begin(), nums.end());
        
//         int i = 1;
//         while(i < nums.size() && nums[i] == nums[0]) {
//             i++;
//         }
        
//         if(i == nums.size()) { 
//             return 0;
//         }
        
//         int j = nums.size() - 2;
//         while(j >= 0 && nums[j] == nums[nums.size() - 1]) {
//             j--;
//         }
        
//         return j - i + 1;  
//     }
// };

// Fails if the 
// class Solution {
// public:
//     int countElements(vector<int>&n){
//         set<int> s(n.begin(),n.end());
//         return s.size() - 2;
//     }
// };

// Fails if duplicate element 
// class Solution {
// public:
//     int countElements(vector<int>& nums) {
//         return nums.size() - 2
//     }
// };