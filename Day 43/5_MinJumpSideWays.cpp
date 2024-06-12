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
    int minSideJumps(vector<int>& obs){
        vvint dp(4, vint(obs.size(), INT_MAX));
        int n = obs.size() - 1;
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int cr_posn = n - 1; cr_posn >= 0; --cr_posn) {
            for(int cr_ln = 1; cr_ln <= 3; ++cr_ln) {
                if(obs[cr_posn + 1] != cr_ln) {
                    dp[cr_ln][cr_posn] = dp[cr_ln][cr_posn + 1];
                } else {
                    int ans = INT_MAX;
                    for(int i = 1; i <= 3; ++i) {
                        if(cr_ln != i && obs[cr_posn] != i) {
                            ans = min(ans, 1 + dp[i][cr_posn + 1]);
                        }
                    }
                    dp[cr_ln][cr_posn] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }
};

// class Solution {
// public:
//     int solve(vector<int>& obs,int cr_ln,int cr_posn,vvint& dp){
//         int n = obs.size() - 1;
//         if(cr_posn == n)
//             return 0;
        
//         if(dp[cr_ln][cr_posn] != -1){
//             return dp[cr_ln][cr_posn];
//         }

//         if(obs[cr_posn + 1] != cr_ln){
//             return solve(obs,cr_ln,cr_posn+1,dp);
//         }
//         int ans = INT_MAX;
//         for(int i=1;i<=3;i++){
//             if(cr_ln != i && obs[cr_posn] != i){
//                 ans = min(ans,1+solve(obs,i,cr_posn,dp));
//             }
//         }
//         dp[cr_ln][cr_posn] = ans;
//         return dp[cr_ln][cr_posn];
//     }

//     int minSideJumps(vector<int>& obs) {
//         int curr_lane = 2;
//         int curr_posn = 0;
//         vvint dp(4,vint (obs.size(),-1));
//         return solve(obs,curr_lane,curr_posn,dp);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& obs,int cr_ln,int cr_posn){
//         int n = obs.size() - 1;
//         if(cr_posn == n)
//             return 0;
        
//         if(obs[cr_posn + 1] != cr_ln){
//             return solve(obs,cr_ln,cr_posn+1);
//         }
//         int ans = INT_MAX;
//         for(int i=1;i<=3;i++){
//             if(cr_ln != i && obs[cr_posn] != i){
//                 ans = min(ans,1+solve(obs,i,cr_posn));
//             }
//         }
//         return ans;
//     }

//     int minSideJumps(vector<int>& obs) {
//         int curr_lane = 2;
//         int curr_posn = 0;
//         return solve(obs,curr_lane,curr_posn);
//     }
// };