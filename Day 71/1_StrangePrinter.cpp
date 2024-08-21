#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int j,string& s,vector<vector<int>>& dp){
        if(i == j){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k = i;k < j;k += 1){
            mn = min(mn, solve(i,k,s,dp) + solve(k+1,j,s,dp));
        }
        return dp[i][j] = (s[i] == s[j] ? mn - 1 : mn) ;
    }


    int strangePrinter(string s){
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp);   
    }
};

// class Solution {
// public:
//     int strangePrinter(string s) {
//         unordered_map<char,int> m;
//         for(auto i : s){
//             m[i] += 1;
//         }
//         return m.size();
//     }
// };

// fails for "abcabc"
// ans for "abab" and "abba"