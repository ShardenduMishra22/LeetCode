#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) { 
            mp[i]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(mp[a] == mp[b]) return a > b;
            else return mp[a] < mp[b]; 
        });
        return nums; 
    }
};