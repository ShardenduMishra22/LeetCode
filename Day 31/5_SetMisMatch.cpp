#include <bits/stdc++.h>
using namespace std;

// Correct but the order of elements is not maintained
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i : nums){
            m[i] += 1;
        }
        vector<int>ans;
        for(int i=1;i<nums.size()+1;i++){
            if(m[i] == 0 || m[i] == 2){
                ans.push_back(i);
            }
        }
        // reverse if the number taht comes twice isnt first 
        if(m[ans[0]] == 0){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};