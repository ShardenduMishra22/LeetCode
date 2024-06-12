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
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())
            return 0;
        vint ans;
        ans.push_back(nums[0]);

        for(int i=1;i<nums.size();i+=1){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int idx = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) 
//             return 0;

//         vector<int> dp(n, 1); 
//         int max_len = 1; 

//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             max_len = max(max_len, dp[i]); 
//         }

//         return max_len;
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
//         int n = nums.size();
//         if (curr == n)
//             return 0;

//         if (dp[curr][prev + 1] != -1)
//             return dp[curr][prev + 1];

//         int take = 0;
//         if (prev == -1 || nums[curr] > nums[prev])
//             take = 1 + solve(nums, curr + 1, curr, dp);

//         int notake = solve(nums, curr + 1, prev, dp);
//         dp[curr][prev + 1] = max(take, notake);

//         return dp[curr][prev + 1];
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1)); 
//         int curr = 0, prev = -1;
//         return solve(nums, curr, prev, dp);
//     }
// };


// class Solution {
// public:
//     int solve(vint& nums, int curr, int prev) {
//         int n = nums.size();
//         if (curr == n) {
//             return 0;
//         }
        
//         int take = 0;
//         if (prev == -1 || nums[curr] > nums[prev]) {
//             take = 1 + solve(nums, curr + 1, curr);
//         }

//         int notake = solve(nums, curr + 1, prev);
//         return max(take, notake);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int curr = 0,prev = -1;
//         return solve(nums,curr,prev);
//     }
// };