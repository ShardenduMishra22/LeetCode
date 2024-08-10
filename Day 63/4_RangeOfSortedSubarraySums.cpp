#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums){
        vector<int> arr(nums);
        int cnt1 = 0;
        for(int i : nums){
            if(i) cnt1 += 1;
            arr.push_back(i);
        }
        int prev = 0,mx1 = 0;
        
        for(int i=0;i<cnt1;i++){
            if(nums[i]){
                mx1 += 1;
            }
        }
        prev = mx1;
        int j = 0;
        
        for(int i=cnt1;i<arr.size();i++){
            if(arr[j]){
                prev -= 1;
            }
            if(arr[i]){
                prev += 1;
            }
            j += 1;
            mx1 = max(mx1,prev);
        }
        return cnt1 - mx1;
    }
};