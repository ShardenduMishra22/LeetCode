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
    int solve(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int index = k - 2; index >= 0; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[index] + dp1[index + 2][n - 1];
                int nottake = 0 + dp1[index + 1][n];
                dp1[index][n] = max(take, nottake);
            }
        }

        for (int index = k - 1; index >= 1; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[index] + dp2[index + 2][n - 1];
                int nottake = 0 + dp2[index + 1][n];
                dp2[index][n] = max(take, nottake);
            }
        }

        int case1 = dp1[0][k / 3];
        int case2 = dp2[1][k / 3];
        return max(case1, case2);
    }


    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);
    }
};



// class Solution {
// public:
//     int solve(int idx,int eidx,vint& sl,int n,vvint& dp){
//         if(n == 0 || idx > eidx){
//             return 0;
//         }
//         if(dp[idx][n] != -1){
//             return dp[idx][n];
//         }
//         int take = sl[idx] + solve(idx + 2,eidx,sl,n-1,dp);
//         int notake = solve(idx + 1,eidx,sl,n,dp);

//         return dp[idx][n] = max(take,notake);
//     }

//     int maxSizeSlices(vector<int>& slices) {
//         int k = slices.size();

//         vvint dp1(k+1,vint(k+1,-1));
//         vvint dp2(k+1,vint(k+1,-1));
//         int c1 = solve(0,k-2,slices,k/3,dp1);
//         int c2 = solve(1,k-1,slices,k/3,dp2);
//         return max(c1,c2);
//     }
// };

// class Solution {
// public:
//     int solve(int idx,int eidx,vint& sl,int n){
//         if(n == 0 || idx > eidx){
//             return 0;
//         }
//         int take = sl[idx] + solve(idx + 2,eidx,sl,n-1);
//         int notake = solve(idx + 1,eidx,sl,n);

//         return max(take,notake);
//     }

//     int maxSizeSlices(vector<int>& slices) {
//         int k = slices.size();
//         int c1 = solve(0,slices,k-2,k/3);
//         int c2 = solve(1,slices,k-1,k/3);
//         return max(c1,c2);
//     }
// };