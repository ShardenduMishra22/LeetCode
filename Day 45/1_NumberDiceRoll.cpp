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
    const int MOD = 1e9 + 7;

    int solve(int dice, int face, int trg) {
        vector<int> curr(trg + 1, 0);
        vector<int> prev(trg + 1, 0);
        prev[0] = 1; 

        for (int i = 1; i <= dice; i++) {
            for (int j = 0; j <= trg; j++) {
                curr[j] = 0; 
                for (int k = 1; k <= face; k++) {
                    if (j >= k) {
                        curr[j] += prev[j - k];
                        curr[j] %= MOD;
                    }
                }
            }
            prev = curr; 
        }

        return curr[trg];
    }

    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};


// class Solution {
// public:
//     int solve(int dice, int face, int trg) {
//         vector<vector<int>> dp(dice + 1, vector<int>(trg + 1, 0)); 
//         dp[0][0] = 1; 

//         for (int i = 1; i <= dice; i++) {
//             for (int j = 0; j <= trg; j++) {
//                 int ans = 0;
//                 for (int k = 1; k <= face; k++) {
//                     if (j >= k) {
//                         ans += dp[i - 1][j - k];
//                         ans %= MOD;
//                     }
//                 }
//                 dp[i][j] = ans;
//             }
//         }

//         return dp[dice][trg];
//     }

//     int numRollsToTarget(int n, int k, int target) {
//         return solve(n, k, target);
//     }
// };


// dice = No of dice
// class Solution {
// public:
//     int solve(int dice,int face,int trg){
//         if(dice == 0 && trg == 0)
//             return 1;
//         if(dice == 0 || trg == 0)
//             return 0;

//         int ans = 0;
//         for(int i = 1;i <= face;i += 1){
//             ans += solve(dice-1,face,trg-i);
//         }
//         return ans;
//     }

//     int numRollsToTarget(int n, int k, int target) {
//         return solve(n,k,target);
//     }
// };