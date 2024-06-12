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

class Solution {
public:
    int solve(string& a, string& b){
        int n = a.size();
        int m = b.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        
        for(int j = 0; j <= m; ++j){
            prev[j] = m - j;
        }

        for(int i = n - 1; i >= 0; --i){
            curr[m] = n - i;
            for(int j = m - 1; j >= 0; --j){
                if (a[i] == b[j]) {
                    curr[j] = prev[j + 1];
                } else {
                    int insertAns = 1 + curr[j + 1];
                    int deleteAns = 1 + prev[j];
                    int replaceAns = 1 + prev[j + 1];
                    curr[j] = min(insertAns, min(deleteAns, replaceAns));
                }
            }
            swap(prev, curr);
        }
        return prev[0];
    }

    int minDistance(string word1, string word2) {
        return solve(word1, word2);
    }
};


// class Solution {
// public:
//     int solve(string& a, string& b, vector<vector<int>>& dp){
//         int n = a.size();
//         int m = b.size();
        
//         for(int j=0; j<=m; j+=1){
//             dp[n][j] = m - j;
//         }

//         for(int i=0; i<=n; i+=1){
//             dp[i][m] = n - i;
//         }

//         for(int i=n-1; i>=0; i-=1){
//             for(int j=m-1; j>=0; j-=1){
//                 if (a[i] == b[j]) {
//                     dp[i][j] = dp[i+1][j+1];
//                 } else {
//                     int insertAns = 1 + dp[i][j+1];
//                     int deleteAns = 1 + dp[i+1][j];
//                     int replaceAns = 1 + dp[i+1][j+1];

//                     dp[i][j] = min(insertAns, min(deleteAns, replaceAns));
//                 }
//             }
//         }
//         return dp[0][0];
//     }

//     int minDistance(string word1, string word2) {
//         vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//         return solve(word1, word2, dp);
//     }
// };


// class Solution {
// public:
//     int solve(string& a, string& b, int i, int j,vector<vector<int>>& dp){
//         if (a.size() == i)
//             return b.size() - j;
//         if (b.size() == j)
//             return a.size() - i;
//         if (dp[i][j] != 0)
//             return dp[i][j];

//         int ans = 0;
//         if (a[i] == b[j]) {
//             return solve(a, b, i + 1, j + 1,dp);
//         } else {
//             int insertAns = 1 + solve(a, b, i, j + 1,dp);
//             int deleteAns = 1 + solve(a, b, i + 1, j,dp);
//             int replaceAns = 1 + solve(a, b, i + 1, j + 1,dp);

//             ans = min(insertAns, min(deleteAns, replaceAns));
//         }
//         return dp[i][j] = ans;
//     }

//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         return solve(word1, word2, 0, 0,dp);
//     }
// };

// class Solution {
// public:
//     int solve(string& a, string& b, int i, int j) {
//         if (a.size() == i)
//             return b.size() - j;
//         if (b.size() == j)
//             return a.size() - i;

//         int ans = 0;
//         if (a[i] == b[j]) {
//             return solve(a, b, i + 1, j + 1);
//         } else {
//             int insertAns = 1 + solve(a, b, i, j + 1);
//             int deleteAns = 1 + solve(a, b, i + 1, j);
//             int replaceAns = 1 + solve(a, b, i + 1, j + 1);

//             ans = min(insertAns, min(deleteAns, replaceAns));
//         }
//         return ans;
//     }

//     int minDistance(string word1, string word2) {
//         return solve(word1, word2, 0, 0);
//     }
// };