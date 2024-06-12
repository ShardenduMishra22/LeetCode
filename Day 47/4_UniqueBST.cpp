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
    int solve(int n){
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;

        for(int i=2;i<=n;i+=1){
            for(int j=1;j<=i;j+=1){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }

        return dp[n];
    }

    int numTrees(int n) {
        return solve(n);
    }
};

// class Solution {
// public:
//     int solve(vector<int>& dp,int n){
//         if(n <= 1)
//             return 1;
//         if(dp[n] != -1)
//             return dp[n];
        
//         int ans = 0;
//         for(int i = 1;i <= n;i += 1){
//             ans += solve(dp,i-1)*solve(dp,n-i);
//         }

//         return dp[n] = ans;
//     }

//     int numTrees(int n) {
//         vector<int> dp(n+1,-1);
//         return solve(dp,n);
//     }
// };