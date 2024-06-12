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
    int solve(vector<int>& sat,int idx,int time){
        int n = sat.size();
        vvint dp(n+1,vint(n+1,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int time=idx;time>=0;time-=1){
                int inc = sat[idx]*(time+1) + dp[idx+1][time+1];
                int exc = dp[idx+1][time];

                dp[idx][time] = max(inc,exc);
            }
        }
        return dp[0][0];
    }

    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int time = 0;
        int idx = 0;
        return solve(sat,idx,time);
    }
};

// class Solution {
// public:
//     int solve(vector<int>& sat,int idx,int time,vvint& dp){
//         if(idx == sat.size())
//             return 0;
//         if(dp[idx][time] != -1)
//             return dp[idx][time];

//         int inc = sat[idx]*(time+1) + solve(sat,idx+1,time+1,dp);
//         int exc = 0 + solve(sat,idx+1,time,dp);

//         dp[idx][time] = max(inc,exc);
//         return dp[idx][time];
//     }

//     int maxSatisfaction(vector<int>& sat) {
//         sort(sat.begin(),sat.end());
//         int time = 0;
//         int idx = 0;
//         vector<vector<int>> dp(sat.size()+1,vector<int>(sat.size()+1,-1));
//         return solve(sat,idx,time,dp);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& sat,int idx,int time){
//         if(idx == sat.size())
//             return 0;

//         int inc = sat[idx]*(time+1) + solve(sat,idx+1,time+1);
//         int exc = 0 + solve(sat,idx+1,time);

//         return max(inc,exc);
//     }

//     int maxSatisfaction(vector<int>& sat) {
//         sort(sat.begin(),sat.end());
//         int time = 0;
//         int idx = 0;
//         return solve(sat,idx,time);
//     }
// };