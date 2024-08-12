#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    int countWays(vector<vector<int>>& rngs) {
        sort(rngs.begin(), rngs.end());
        int rem = 1;
        int temp = rngs[0][1];
        
        for(int i = 1; i < rngs.size(); i++) {
            if(temp < rngs[i][0]) rem++;
            temp = max(temp, rngs[i][1]);
        }       
        int ans = 1;
        while(rem--){
            ans = (ans * 2) % MOD;
        }
        
        return ans;
    }
};