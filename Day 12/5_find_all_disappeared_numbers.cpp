#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        for(int i=0; i < n; i++){
            if(nums[abs(nums[i])-1] < 0) continue;
            nums[abs(nums[i])-1] *= -1;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};