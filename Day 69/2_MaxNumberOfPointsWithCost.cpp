#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int m, n;

    ll maxPoints(vector<vector<int>>& pts) {
        m = pts.size();
        n = pts[0].size();
        vector<vector<ll>> dp(m, vector<ll>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = pts[0][j];
        }

        for (int i = 1; i < m; i++) {
            vector<ll> left(n, 0), right(n, 0);

            left[0] = dp[i - 1][0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, dp[i - 1][j]);
            }

            right[n - 1] = dp[i - 1][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, dp[i - 1][j]);
            }

            for (int j = 0; j < n; j++) {
                dp[i][j] = pts[i][j] + max(left[j], right[j]);
            }
        }

        return *max_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};


// class Solution {
// public:
//     typedef long long ll;
//     int m, n;

//     ll maxPoints(vector<vector<int>>& pts) {
//         m = pts.size();
//         n = pts[0].size();
//         vector<vector<ll>> dp(m, vector<ll>(n, LLONG_MIN));

//         for (int j = 0; j < n; j++) {
//             dp[0][j] = pts[0][j];
//         }

//         for (int i = 1; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int k = 0; k < n; k++) {
//                     ll num = dp[i-1][k] - abs(j - k) + pts[i][j];
//                     dp[i][j] = max(dp[i][j], num);
//                 }
//             }
//         }

//         return *max_element(dp[m-1].begin(), dp[m-1].end());
//     }
// };

// class Solution {
// public:
//     typedef long long ll;
//     int m, n;

//     ll solve(vector<vector<int>>& pts, int i, int j,vector<vector<ll>>& dp){
//         if (i == m) return 0;
//         if (j < 0 || j >= n) return LLONG_MIN;
//         if (dp[i][j] != -1){
//             return dp[i][j];
//         }
//         for (int k = 0; k < n; k++) {
//             ll num = solve(pts,i+1,k,dp) - abs(j - k) + pts[i][j];
//             dp[i][j] = max(dp[i][j], num);
//         }
//         return dp[i][j];
//     }

//     ll maxPoints(vector<vector<int>>& pts) {
//         ll ans = LLONG_MIN;
//         m = pts.size();
//         n = pts[0].size();
//         vector<vector<ll>> dp(m,vector<ll>(n,-1));

//         for (int j = 0; j < n; j++) {
//             ll num = solve(pts, 0, j,dp);
//             ans = max(ans, num);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     typedef long long ll;
//     int m, n;

//     ll solve(vector<vector<int>>& pts, int i, int j) {
//         if (i == m) return 0;
//         if (j < 0 || j >= n) return LLONG_MIN;

//         ll ans = LLONG_MIN;
//         for (int k = 0; k < n; k++) {
//             ll num = solve(pts,i+1,k) - abs(j - k) + pts[i][j];
//             ans = max(ans, num);
//         }
//         return ans;
//     }

//     ll maxPoints(vector<vector<int>>& pts) {
//         ll ans = LLONG_MIN;
//         m = pts.size();
//         n = pts[0].size();

//         for (int j = 0; j < n; j++) {
//             ll num = solve(pts, 0, j);
//             ans = max(ans, num);
//         }
//         return ans;
//     }
// };