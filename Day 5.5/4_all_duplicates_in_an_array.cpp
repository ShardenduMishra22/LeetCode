#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<bool>check(nums.size()+2, false);
        vector<int>ans;
        for(int i=0; i< nums.size();i++){
            if(check[nums[i]]){
                ans.push_back(nums[i]);
            }
            check[nums[i]] = true;
        }

        return ans;    
    }
};

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> a(n + 1, 0);
//         vector<int> ans;
        
        
//         for(int i = 0; i < n; i++) {
//             a[nums[i]]++;
//         }
        

//         for(int i = 1; i <= n; i++) { 
//             if(a[i] == 2) {
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
//     }
// };
