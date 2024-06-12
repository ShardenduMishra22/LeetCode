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
    int solve(string a, string b) {
        vector<int> next(b.size() + 1, 0);
        vector<int> curr(b.size() + 1, 0);

        for (int i = a.size() - 1; i >= 0; i--) {
            for (int j = b.size() - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    next[j] = 1 + curr[j + 1];
                } else {
                    next[j] = max(curr[j], next[j + 1]);
                }
            }
            curr = next;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string m;
        m = s;
        reverse(m.begin(),m.end());
        return solve(s,m);
    }
};


// class Solution {
// public:
//     int solve(string a, string b){
//         vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));

//         for(int i=a.size()-1;i>=0;i-=1){
//             for(int j=b.size()-1;j>=0;j-=1){
//                 int ans = 0;
//                 if(a[i] == b[j]){
//                     ans = 1 + dp[i+1][j+1];
//                 }else{
//                     ans = max(dpw   [i+1][j],dp[i][j+1]);
//                 }
//                 dp[i][j] = ans;
//             }
//         }
//         return dp[0][0];
//     }

//      int longestPalindromeSubseq(string s) {
//          string m;
//          m = s;
//          reverse(m.begin(),m.end());
//          return solve(s,m);
//      }
// };

// class Solution {
// public:
//     int solve(string a, string b,int i,int j,vector<vector<int>>& dp){
//         if(i == a.size())
//             return 0;
//         if(j == b.size())
//             return 0;
//         if(dp[i][j] != 0)
//             return dp[i][j];

//         int ans=0;
//         if(a[i] == b[j])
//             ans = 1 + solve(a,b,i+1,j+1,dp);
//         else
//             ans = max(solve(a,b,i,j+1,dp),solve(a,b,i+1,j,dp));

//         return dp[i][j] = ans;
//     }

//      int longestPalindromeSubseq(string s) {
//          string m;
//          m = s;
//          reverse(m.begin(),m.end());
//          vector<vector<int>> dp(s.size()+1,vector<int>(m.size()+1,0));
//          return solve(s,m,0,0,dp);
//      }

// };

// class Solution {
// public:
//     int solve(string a, string b,int i,int j){
//         if(i == a.size())
//             return 0;
//         if(j == b.size())
//             return 0;

//         int ans=0;
//         if(a[i] == b[j])
//             ans = 1 + solve(a,b,i+1,j+1);
//         else
//             ans = max(solve(a,b,i,j+1),solve(a,b,i+1,j));

//         return ans;
//     }

//      int longestPalindromeSubseq(string s) {
//          string m;
//          m = s;
//          reverse(m.begin(),m.end());
//          return solve(s,m,0,0);
//      }
// };