#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& n) {
        for(int i=n.size();i>=1;i--){
            int ans = 0;
            for(int j=0;j<n.size();j++){
                if(n[j] >= i){
                    ans++;
                }
            }
            if(ans == i) return ans;
        }
        return -1;
    }
};