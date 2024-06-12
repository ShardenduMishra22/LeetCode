#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);
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

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    int solve(vector<int>& val) {
        fast();
        int n = val.size();
        vvint dp(n+1,vint(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j+=1){
                int ans = INT_MAX;
                for(int k=i+1;k<j;k+=1){
                    ans = min(ans,val[i]*val[j]*val[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int>& val) {
        return solve(val);
    }
};

// class Solution {
// public:
//     int solve(vector<int>& val, int i, int j, vector<vector<int>>& dp) {
//         if (j - i == 1)  
//             return 0;

//         if (dp[i][j] != INT_MAX) {
//             return dp[i][j];
//         }

//         int ans = INT_MAX;
//         for (int k = i + 1; k < j; ++k) {
//             ans = min(ans, val[i] * val[j] * val[k] + solve(val, k, j, dp) + solve(val, i, k, dp));
//         }

//         dp[i][j] = ans;
//         return dp[i][j];
//     }

//     int minScoreTriangulation(vector<int>& val) {
//         int n = val.size();
//         vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//         return solve(val, 0, n - 1, dp);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& val, int i, int j, vector<vector<int>>& dp) {
//         if (j - i == 1)  
//             return 0;

//         if (dp[i][j] != INT_MAX) {
//             return dp[i][j];
//         }

//         int ans = INT_MAX;
//         for (int k = i + 1; k < j; ++k) {
//             ans = min(ans, val[i] * val[j] * val[k] + solve(val, k, j, dp) + solve(val, i, k, dp));
//         }

//         dp[i][j] = ans;
//         return dp[i][j];
//     }

//     int minScoreTriangulation(vector<int>& val) {
//         int n = val.size();
//         vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//         return solve(val, 0, n - 1, dp);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& val,int i,int j){
//         if(i+1 == j)
//             return 0;
        
//         int ans = INT_MAX;
//         for(int k = i+1;k<j;k+=1){
//             ans = min(ans,val[i]*val[j]*val[k] + solve(val,k,j) + solve(val,i,k));
//         }
//         return ans;
//     }

//     int minScoreTriangulation(vector<int>& val) {
//         int n = val.size();
//         return solve(val,0,n-1);
//     }
// };