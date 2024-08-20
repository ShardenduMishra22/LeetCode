#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& piles, int person, int i, int M, vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        if (i >= n) return 0;
        if (dp[person][i][M] != -1) return dp[person][i][M];

        int res = person ? INT_MIN : INT_MAX;
        int stones = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            if (person == 1) {
                res = max(res, stones + solve(piles, 0, i + x, max(M, x), dp));
            } else {
                res = min(res, solve(piles, 1, i + x, max(M, x), dp));
            }
        }

        return dp[person][i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(piles, 1, 0, 1, dp);
    }
};
