#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P, vector<P>> MxPq;
        priority_queue<P, vector<P>, greater<P>> MnPq;
        
        int i = 0, j = 0;
        int MxLngth = 0;
        while (j < n) {
            MxPq.push({nums[j], j});
            MnPq.push({nums[j], j});
            while (MxPq.top().first - MnPq.top().first > limit) {
                i = min(MxPq.top().second, MnPq.top().second) + 1;
                
                while (MxPq.top().second < i) {
                    MxPq.pop();
                }
                
                while (MnPq.top().second < i) {
                    MnPq.pop();
                }
            }
            MxLngth = max(MxLngth, j - i + 1);
            j++;
        }
        return MxLngth;
    }
};