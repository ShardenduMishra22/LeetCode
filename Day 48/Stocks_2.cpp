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
    int solve(int n, vector<int>& pr, vector<vector<int>>& dp) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                int prf = 0;
                if (j == 1) {
                    int buy_karo = -pr[i] + dp[i + 1][0];
                    int skip_karo = 0 + dp[i + 1][1];
                    prf = max(buy_karo, skip_karo);
                } else {
                    int sell_karo = pr[i] + dp[i + 1][1];
                    int skip_karo = 0 + dp[i + 1][0];
                    prf = max(sell_karo, skip_karo);
                }
                dp[i][j] = prf;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        return solve(n, prices, dp);
    }
};


// class Solution {
// public:
//     int solve(int idx, int buy, vector<int>& pr, vector<vector<int>>& dp) {
//         if (idx == pr.size()) {
//             return 0;
//         }
//         if (dp[idx][buy] != -1) {
//             return dp[idx][buy];
//         }

//         int prf = 0;
//         if (buy) {
//             int buy_karo = -pr[idx] + solve(idx + 1, 0, pr, dp);
//             int skip_karo = 0 + solve(idx + 1, 1, pr, dp);
//             prf = max(buy_karo, skip_karo);
//         } else {
//             int sell_karo = pr[idx] + solve(idx + 1, 1, pr, dp);
//             int skip_karo = 0 + solve(idx + 1, 0, pr, dp);
//             prf = max(sell_karo, skip_karo);
//         }

//         return dp[idx][buy] = prf;
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1)); 
//         return solve(0, 1, prices, dp);
//     }
// };


// class Solution {
// public:
//     int solve(int idx,int buy,vector<int>& pr){
//         if(idx == pr.size())
//             return 0;
        
//         int prf = 0;
//         if(buy){
//             int buy_karo = -pr[idx] + solve(idx+1,0,pr);
//             int skip_karo = 0 + solve(idx+1,1,pr);
//             prf = max(buy_karo,skip_karo);
//         }else{
//             int sell_karo = pr[idx] + solve(idx+1,1,pr);
//             int skip_karo = 0 + solve(idx+1,0,pr);
//             prf = max(sell_karo,skip_karo);
//         }

//         return prf;
//     }

//     int maxProfit(vector<int>& prices) {
//         return solve(0,1,prices);
//     }
// };