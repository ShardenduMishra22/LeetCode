#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt1 = 0,cnt0 = 0,ans = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(s[j] == '1' ){
                    cnt1 += 1;
                }else{
                    cnt0 += 1;
                }
            }
            if(cnt1 <= k || cnt0 <= k){
                ans += 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        
    }
};