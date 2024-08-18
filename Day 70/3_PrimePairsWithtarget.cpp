#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<bool>& prm,int& n){
        prm[0] = prm[1] = false;
        for(int i=2;i<n;i++){
            if(prm[i]){
                for(int j=i*2;j<n;j+=i){
                    prm[j] = false;
                }
            }
        }
    } 

    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prm(n,true);
        solve(prm,n);
        vector<vector<int>> ans;
        for(int i=2;i<=n/2;i++){
            if(prm[i] && prm[n-i]){
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};