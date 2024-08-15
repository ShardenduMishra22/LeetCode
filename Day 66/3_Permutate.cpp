#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> res;

    void solve(unordered_map<int, int>& m, vector<int>& temp) {
        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }

        for (auto& [num, count] : m) { 
            if (count == 0) {
                continue;
            }
            
            temp.push_back(num);
            m[num] -= 1;

            solve(m, temp);

            temp.pop_back();
            m[num] += 1;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> m;
        for (int& i : nums) {
            m[i] += 1;
        }
        vector<int> temp;
        solve(m, temp);
        
        return res;
    }
};

// class Solution {
// public:
//     int n;
//     vector<vector<int>> res;
//     unordered_set<int> st;

//     void solve(vector<int>& temp, vector<int>& nums) {
//         if (temp.size() == n) {
//             res.push_back(temp);
//             return;
//         }

//         for (int i = 0; i < n; i++) {
//             if (st.find(nums[i]) == st.end()){
//                 temp.push_back(nums[i]);
//                 st.insert(nums[i]);

//                 solve(temp, nums);

//                 temp.pop_back();
//                 st.erase(nums[i]);
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         n = nums.size();
//         vector<int> temp;
//         solve(temp, nums);
//         return res;
//     }
// };


// class Solution {
// public:
//     void solve(vector<int>& nums, vector<vector<int>>& ans, int i) {
//         if (i == nums.size()) {
//             ans.push_back(nums);
//             return;
//         }
//         for (int j = i; j < nums.size(); j++) {
//             swap(nums[i], nums[j]);
//             solve(nums, ans, i + 1);
//             swap(nums[i], nums[j]);
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         solve(nums, ans, 0);
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         do{
//             ans.push_back(nums);
//         }while(next_permutation(nums.begin(),nums.end()));

//         return ans;
//     }
// };