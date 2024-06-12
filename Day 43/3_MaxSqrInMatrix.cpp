#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)

#define rvrs(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())

#define YES cout<<"Yes \n";
#define NOO cout<<"No  \n";
#define nl cout<<"\n";

#define MAX_SIZE 10000
#define nptr nullptr

typedef stringstream strgm;
typedef long long int ll;
typedef const int c_int;
typedef unsigned unsg;
typedef double dbl;

typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbl;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;

typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
typedef vector<ll> vll;

typedef stack<string> sstr;
typedef stack<bool> sbl;
typedef stack<int> sint;
typedef stack<ll> sll;

typedef queue<string> qstr;
typedef queue<bool> qbl;
typedef queue<int> qint;
typedef queue<ll> qll;

c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        int mx = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    int dig = prev[j];
                    int r = prev[j + 1];
                    int d = curr[j];

                    curr[j + 1] = 1 + min(dig, min(r, d));
                    mx = max(mx, curr[j + 1]);
                } else {
                    curr[j + 1] = 0;
                }
            }
            prev = curr;
        }

        return mx * mx;
    }
};

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         if (matrix.empty() || matrix[0].empty()) return 0;

//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         int mx = 0;

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {                
//                 if (matrix[i][j] == '1') {
//                     if (i == 0 || j == 0) {
//                         dp[i][j] = 1; 
//                     } else {
//                         dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
//                     }
//                     mx = max(mx, dp[i][j]); 
//                 }
//             }
//         }

//         return mx * mx; 
//     }
// };




// class Solution {
// public:
//     int solve(vector<vector<char>>& mat, int i, int j, int& mx, vector<vector<int>>& dp) {
//         if (i >= mat.size() || j >= mat[0].size()) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int dig = solve(mat, i + 1, j + 1, mx);
//         int r = solve(mat, i, j + 1, mx);
//         int d = solve(mat, i + 1, j, mx);

//         if (mat[i][j] == '1') {
//             dp[i][j] = 1 + min(r, min(dig, d));
//             mx = max(dp[i][j], mx);
//             return dp[i][j];
//         }

//         return dp[i][j] = 0;
//     }

//     int maximalSquare(vector<vector<char>>& mat) {
//         if (mat.empty() || mat[0].empty()) return 0;

//         int m = mat.size();
//         int n = mat[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         int mx = 0;
//         solve(mat, 0, 0, mx);
//         return mx * mx;
//     }
// };

// class Solution {
// public:
//     int solve(vector<vector<char>>& mat, int i, int j, int& mx) {
//         if (i >= mat.size() || j >= mat[0].size()) {
//             return 0;
//         }

//         int dig = solve(mat, i + 1, j + 1, mx);
//         int r = solve(mat, i, j + 1, mx);
//         int d = solve(mat, i + 1, j, mx);

//         if (mat[i][j] == '1') {
//             int ans = 1 + min(r, min(dig, d));
//             mx = max(ans, mx);
//             return ans;
//         }
        
//         return 0;
//     }

//     int maximalSquare(vector<vector<char>>& mat) {
//         if (mat.empty() || mat[0].empty()) return 0;
        
//         int mx = 0;
//         solve(mat, 0, 0, mx);
//         return mx * mx; 
//     }
// };