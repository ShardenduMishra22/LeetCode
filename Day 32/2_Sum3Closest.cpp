#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff=INT_MAX,ans;
        for(int i=0;i<n;i++){
            int frst = nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                int sum = frst + nums[l] + nums[r];
                if(sum == target){
                    return target;
                }else if(abs(sum - target) < diff){
                    diff = abs(sum-target);
                    ans = sum;
                }
                if(sum > target){
                    r -= 1;
                }else{
                    l += 1;
                }
            }
        }
        return ans;
    }
};