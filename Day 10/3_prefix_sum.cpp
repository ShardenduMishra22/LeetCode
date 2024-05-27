#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        // vec[0] = nums[0];
        // this will show an error because 
        // uninitialised vector dont have size 
        vec = nums;
        for (int i = 1; i < nums.size(); i++)
            vec[i] = nums[i] + vec[i-1];
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return vec[j];
        return vec[j] - vec[i-1];
    }
private:
    vector<int> vec;
};
