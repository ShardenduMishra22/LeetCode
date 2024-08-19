#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int minSteps(int n) {
//         vector<int> dp(n + 1, 1000);
//         dp[1] = 0;

//         for (int i = 2; i <= n; i++){
//             for (int j = 1; j <= i / 2; j++){
//                 if (i % j == 0) {
//                     dp[i] = min(dp[i], dp[j] + i / j);
//                 }
//             }
//         }
//         return dp[n];
//     }
// };



// class Solution {
// public:
//     int solve(int trg,int CurrLen,int BoardLen,vector<vector<int>>& dp){
//         if(CurrLen == trg){
//             return 0;
//         }
//         if(CurrLen > trg){
//             return 9999;
//         }
//         if(dp[CurrLen][BoardLen] != -1){
//             return dp[CurrLen][BoardLen];
//         }
//         int CP = 2 + solve(trg,CurrLen*2,CurrLen,dp);
//         int P = 1 + solve(trg,CurrLen + BoardLen,BoardLen,dp);
    
//         return dp[CurrLen][BoardLen] = min(CP,P);
//     }

//     int minSteps(int n) {
//         if(n == 1){
//             return 0;
//         }
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//         int CurrLen = 1;
//         int BoardLen = 1;
//         int ans = 1 + solve(n,CurrLen,BoardLen,dp);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int solve(int trg,int CurrLen,int BoardLen){
//         if(CurrLen == trg){
//             return 0;
//         }
//         if(CurrLen > trg){
//             return 9999;
//         }
//         int CP = 2 + solve(trg,CurrLen*2,CurrLen);
//         int P = 1 + solve(trg,CurrLen + BoardLen,BoardLen);
    
//         return min(CP,P);
//     }

//     int minSteps(int n) {
//         if(n == 1){
//             return 0;
//         }
//         int CurrLen = 1;
//         int BoardLen = 1;
//         int ans = 1 + solve(n,CurrLen,BoardLen);
//         return ans;
//     }
// };