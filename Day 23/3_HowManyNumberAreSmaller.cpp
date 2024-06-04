#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums);
        sort(ans.begin(), ans.end());
        unordered_map<int, int> m;
        for (int i = ans.size() - 1; i >= 0; i--) {
            m[ans[i]] = i;
        }
        vector<int> res;
        for (int num : nums) {
            res.push_back(m[num]);
        }
        return res;
    }
};
