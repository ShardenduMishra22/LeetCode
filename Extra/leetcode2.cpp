#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(vector<int>& edA, vector<int>& edB, int idx, int prev, vector<vector<long long>>& dp) {
        if (idx >= edA.size()) {
            return 0;
        }
        if (dp[idx][prev] != -1) {
            return dp[idx][prev];
        }
        long long mx = INT_MIN;
        if (prev == 0) {
            long long ans1 = edA[idx] + solve(edA, edB, idx + 1, 1, dp);
            long long ans2 = edB[idx] + solve(edA, edB, idx + 1, 2, dp);
            mx = max(ans1, ans2);
        } else if (prev == 1) {
            long long ans1 = edA[idx] + solve(edA, edB, idx + 1, 1, dp);
            long long ans2 = solve(edA, edB, idx + 1, 2, dp);
            mx = max(ans1, ans2);
        } else {
            long long ans1 = solve(edA, edB, idx + 1, 1, dp);
            long long ans2 = edB[idx] + solve(edA, edB, idx + 1, 2, dp);
            mx = max(ans1, ans2);
        }
        return dp[idx][prev] = mx;
    }

    long long maxEnergyBoost(vector<int>& edA, vector<int>& edB) {
        vector<vector<long long>> dp(edA.size(), vector<long long>(3, -1));
        return solve(edA, edB, 0, 0, dp);
    }
};