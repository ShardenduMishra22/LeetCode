#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        int mx_index = INT_MIN;
        int mx = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(m[nums[i]] > mx) {
                mx = m[nums[i]];
                mx_index = nums[i];
            }
        }
        return mx_index;
    }
};