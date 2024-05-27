#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(nums.size() <= 2) {
            return nums[nums.size()-1];
        }
        return nums[nums.size()-3];
    }
};

// #include <vector>
// #include <set>
// #include <climits>

// class Solution {
// public:
//     int thirdMax(std::vector<int>& nums) {
//         std::set<int> s(nums.begin(), nums.end());
        
//         if (s.size() < 3) {
//             return *s.rbegin(); // Return the maximum element
//         }
        
//         auto it = s.rbegin();
//         std::advance(it, 2); // Move iterator to the third element
        
//         return *it;
//     }
// };
