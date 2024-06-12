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
    bool solve(vector<int>& nums) {
        int trg = 0;
        int n = nums.size();
        for(int i : nums)
            trg += i;

        if (trg & 1)
            return false;
        trg /= 2; 
        vector<vector<int>> dp(n + 1, vector<int>(trg + 1, 0));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1; 
        }

        for(int idx = n - 1; idx >= 0; idx--) {
            for(int j = 0; j <= trg; j++) {
                int inc = 0;
                if(j - nums[idx] >= 0) {
                    inc = dp[idx + 1][j - nums[idx]];
                }
                int exc = dp[idx + 1][j];
                dp[idx][j] = inc || exc;
            }
        }
        return dp[0][trg];
    }

    bool canPartition(vector<int>& nums) {
        return solve(nums); 
    }
};


class Solution {
public:
    int solve(vector<int>& nums,int trg,int idx,vector<vector<int>>& dp){
        if(idx >= nums.size() || trg < 0)
            return 0;
        if(trg == 0)
            return 1;
        if(dp[idx][trg] != -1)
            return dp[idx][trg];

        int n1 = solve(nums,trg-nums[idx],idx+1,dp);
        int n2 = solve(nums,trg,idx+1,dp);

        return dp[idx][trg] = n1 || n2;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        if(sum&1)
            return 0;
        
        int trg = sum / 2;
        int idx = 0;

        vector<vector<int>> dp(nums.size(),vector<int>(trg+1,-1));
        return solve(nums,trg,idx,dp); 
    }
};

// class Solution {
// public:
//     int solve(vector<int>& nums,int trg,int idx){
//         if(idx >= nums.size() || trg < 0)
//             return 0;
//         if(trg == 0)
//             return 1;
        
//         int n1 = solve(nums,trg-nums[idx],idx+1);
//         int n2 = solve(nums,trg,idx+1);;

//         return n1 || n2;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(auto i : nums)
//             sum += i;
        
//         if(sum&1)
//             return 0;
        
//         int trg = sum / 2;
//         int idx = 0;
        
//         return solve(nums,trg,idx); 
//     }
// };