#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};


// class Solution {
// public:
//     bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
//         if (i < 0 && j < 0)
//             return true;

//         if (j < 0)
//             return false;

//         if (i < 0) {
//             for (int k = 0; k <= j; ++k) {
//                 if (p[k] != '*')
//                     return false;
//             }
//             return true;
//         }

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (p[j] == s[i] || p[j] == '?') {
//             return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
//         }else if (p[j] == '*') {
//             return dp[i][j] = solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);
//         }else {
//             return dp[i][j] = false;
//         }
//     }

//     bool isMatch(string s, string p) {
//         int n = s.size();
//         int m = p.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//         return solve(s, p, n - 1, m - 1, dp);
//     }
// };

// class Solution {
// public:
//     bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
//         if (i < 0 && j < 0)
//             return true;

//         if (j < 0)
//             return false;

//         if (i < 0) {
//             for (int k = 0; k <= j; ++k) {
//                 if (p[k] != '*')
//                     return false;
//             }
//             return true;
//         }

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (p[j] == s[i] || p[j] == '?') {
//             return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
//         }else if (p[j] == '*') {
//             return dp[i][j] = solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);
//         }else {
//             return dp[i][j] = false;
//         }
//     }

//     bool isMatch(string s, string p) {
//         int n = s.size();
//         int m = p.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//         return solve(s, p, n - 1, m - 1, dp);
//     }
// };

// class Solution {
// public:
//     bool solve(string s, string p,int i,int j){
//         if(i<0 && j<0)
//             return true;

//         if(i>=0 && j < 0)
//             return false;
        
//         if(j>=0 && i < 0){
//             for(int k=0;k<=j;k+=1){
//                 if(p[k] != '*')
//                     return false;
//             }
//             return true;
//         }

//         if(p[j] == s[i] || p[j] == '?'){
//             return solve(s,p,i-1,j-1);
//         }else if(p[j] == '*'){
//             return solve(s,p,i-1,j) || solve(s,p,i,j-1);
//         }
//         return false;
//     }

//     bool isMatch(string s, string p) {
//         int n = s.size();
//         int m = p.size();
//         return solve(s,p,n-1,m-1);
//     }
// };