#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsPal(string& s,int i,int j,vector<vector<int>>& dp){
        if(s.size() <= 1){
            return true;
        }
        if(i >= j){
            return true;
        }
        if(dp[i][j] != false){
            return dp[i][j];
        }
        if(s[i] != s[j]){
            return false;
        }
        return dp[i][j] = IsPal(s,i+1,j-1,dp);
    }

    string largestPalindrome(int n, int k) {
        int num = 0;
        for(int i=0;i<n;i++){
            num = num*10 + 9;
        }

        for(int i = num;i >= 0;i--){
            string s = to_string(i);
            vector<vector<bool>> dp(s.size().vector<bool>(s.size(),false));
            if(i % k == 0 && IsPal(s,0,s.size()-1,dp)){
                return s;
            }
        }
        return "";

    }
};