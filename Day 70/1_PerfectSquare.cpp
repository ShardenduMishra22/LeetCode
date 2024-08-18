#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int n, vector<int>& ans, int idx,vector<vector<int>>& dp){
        if (n == 0) {
            return 0;
        }
        
        if (n < 0 || idx == ans.size()) {
            return INT_MAX;
        }

        if (dp[n][idx] != -1) {
            return dp[n][idx];
        }

        int include = solve(n - ans[idx], ans, idx, dp);
        if (include != INT_MAX) {
            include += 1;
        }

        int exclude = solve(n, ans, idx + 1, dp);
    
        return dp[n][idx] = min(include, exclude);
    }

    int numSquares(int n) {
        vector<int> ans;
        for (int i = 1; i * i <= n; i++) {
            ans.push_back(i * i);
        }

        vector<vector<int>> dp(n + 1, vector<int>(ans.size(), -1));
        int cnt = solve(n, ans, 0, dp);
        
        return (cnt == INT_MAX) ? -1 : cnt;
    }
};


// class Solution {
// public:
//     int solve(int n, vector<int>& ans, int idx) {
//         if (n == 0) {
//             return 0; // Base case: if n becomes 0, we found a valid combination
//         }

//         // If n goes negative or we run out of numbers, return a large value (no solution)
//         if (n < 0 || idx == ans.size()) {
//             return INT_MAX;
//         }
        
//         // Option 1: Include the current perfect square
//         int include = solve(n - ans[idx], ans, idx);
        
//         // If it's a valid solution, add 1 to the count
//         if (include != INT_MAX){
//             include += 1;
//         }

//         // Option 2: Skip the current perfect square and move to the next one
//         int exclude = solve(n, ans, idx + 1);
        
//         return min(include, exclude);
//     }

//     int numSquares(int n) {
//         vector<int> ans;
//         for (int i = 1; i * i <= n; i++) {
//             ans.push_back(i * i);
//         }
//         int cnt = solve(n, ans, 0);
//         return (cnt == INT_MAX) ? -1 : cnt;
//     }
// };