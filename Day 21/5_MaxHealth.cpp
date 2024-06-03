#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int mx = 0,curr = 0;
        for(int i=0;i<acc.size();i++){
            for(int j=0;j<acc[0].size();j++){
                curr += acc[i][j];
            }
            mx = max(mx,curr);
            curr = 0;
        }
        return mx;
    }
};

