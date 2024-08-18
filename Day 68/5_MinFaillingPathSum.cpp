#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int left = INT_MAX, right = INT_MAX, down = dp[i-1][j];

                if (j > 0) {
                    left = dp[i-1][j-1];
                }
                if (j < n - 1) {
                    right = dp[i-1][j+1];
                }

                dp[i][j] = mat[i][j] + min({left, down, right});
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};

// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int n = mat.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         for (int j = 0; j < n; j++) {
//             dp[0][j] = mat[0][j];
//         }

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 int left = INT_MAX, right = INT_MAX, down = dp[i-1][j];

//                 if (j > 0) {
//                     left = dp[i-1][j-1];
//                 }
//                 if (j < n - 1) {
//                     right = dp[i-1][j+1];
//                 }

//                 dp[i][j] = mat[i][j] + min({left, down, right});
//             }
//         }

//         int ans = INT_MAX;
//         for (int j = 0; j < n; j++) {
//             ans = min(ans, dp[n-1][j]);
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int solve(vector<vector<int>>& mat, int i, int j,vector<vector<int>>& dp) {
//         if (i == mat.size()){ 
//             return 0;
//         }
//         if (j < 0 || j >= mat[0].size()){ 
//             return INT_MAX;
//         }
//         if (dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int s1 = solve(mat, i + 1, j - 1, dp);
//         int s2 = solve(mat, i + 1, j, dp);
//         int s3 = solve(mat, i + 1, j + 1, dp);

//         return dp[i][j] = min({s1, s2, s3}) + mat[i][j];
//     }

//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int ans = INT_MAX;
//         int n = mat[0].size();
//         vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
//         for (int j = 0; j < n; j++){
//             int sum = solve(mat, 0, j,dp);
//             ans = min(ans, sum);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int solve(vector<vector<int>>& mat, int i, int j) {
//         if (i == mat.size()){ 
//             return 0;
//         }
//         if (j < 0 || j >= mat[0].size()){ 
//             return INT_MAX;
//         }
//         int s1 = solve(mat, i + 1, j - 1);
//         int s2 = solve(mat, i + 1, j);
//         int s3 = solve(mat, i + 1, j + 1);

//         return min({s1, s2, s3}) + mat[i][j];
//     }

//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int ans = INT_MAX;
//         int n = mat[0].size();
//         for (int j = 0; j < n; j++) {
//             int sum = solve(mat, 0, j);
//             ans = min(ans, sum);
//         }
//         return ans;
//     }
// };