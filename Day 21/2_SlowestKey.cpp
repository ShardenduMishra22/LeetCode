#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) {
        int idx = 0;
        int mn = rt[0]; 
        for (int i = 1; i < rt.size(); i++) {
            int duration = rt[i] - rt[i-1]; 
            if (duration > mn) {
                mn = duration;
                idx = i;
            } else if (duration == mn && kp[i] > kp[idx]) {
                idx = i;
            }
        }

        return kp[idx];
    }
};