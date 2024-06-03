#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& n) {
        sort(n.begin(), n.end());
        int ans = 0, maxAns = 0;
        int l = 0, r = 0;
        
        while (r < n.size()) {
            if ((n[r] - n[l]) == 1) {
                ans = r - l + 1;
                maxAns = max(maxAns, ans);
            } else if (n[r] - n[l] > 1) {
                while (n[r] - n[l] > 1) {
                    l += 1;
                }
            }
            r += 1;
        }        
        return maxAns;
    }
};
