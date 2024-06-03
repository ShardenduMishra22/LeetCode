#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i += 1){
            if(nums.size()&1 && i == nums.size())
                continue;
            if ((nums[i] & 1) && (nums[i + 1] & 1) || !(nums[i] & 1) && !(nums[i + 1] & 1))
                return false;
        }
        return true;
    }
};
