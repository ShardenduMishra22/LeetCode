#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> evn;

        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                evn.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }

        sort(odd.rbegin(), odd.rend());
        sort(evn.begin(), evn.end());

        int evenIndex = 0;
        int oddIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                nums[i] = evn[evenIndex++];
            } else {
                nums[i] = odd[oddIndex++];
            }
        }

        return nums;
    }
};
