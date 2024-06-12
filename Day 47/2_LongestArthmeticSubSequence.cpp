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
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }

        int ans = 0;
        unordered_map<int,int> dp[n+1];

        for(int i=1;i<n;i+=1){
            for(int j=0;j<i;j+=1){
                int diff = nums[i] - nums[j];
                int cnt = 1;
                if(dp[j].count(diff))
                    cnt = dp[j][diff];

                dp[i][diff] = cnt + 1;
                ans = max(ans,dp[i][diff]); 
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int solve(int idx, vector<int>& nums, int diff, unordered_map<int, unordered_map<int, int>>& dp) {
//         if (idx < 0)
//             return 0;
//         if (dp[idx].count(diff) > 0)
//             return dp[idx][diff];

//         int ans = 0;
//         for (int j = idx - 1; j >= 0; j--) {
//             if (nums[idx] - nums[j] == diff) {
//                 ans = max(ans, 1 + solve(j, nums, diff, dp));
//             }
//         }
//         return dp[idx][diff] = ans;
//     }

//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 2)
//             return n;
        
//         unordered_map<int, unordered_map<int, int>> dp;

//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int diff = nums[j] - nums[i];
//                 ans = max(ans, 2 + solve(i, nums, diff, dp));
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int solve(int idx,vector<int>& nums,int diff){
//         if(idx < 0)
//             return 0;

//         int ans = 0;
//         for(int j =idx-1;j>=0;j-=1){
//             if(nums[idx] - nums[j] == diff){
//                 ans = max(ans,1+solve(j,nums,diff));
//             }
//         }
//         return ans;
//     }

//     int longestArithSeqLength(vector<int>& nums) {
//         int n=nums.size();
//         if(n <= 2)
//             return n;
        
//         int ans=0;
//         for(int i=0;i<n;i+=1){
//             for(int j=i+1;j<n;j+=1){
//                 int diff = nums[j] - nums[i];
//                 ans = max(ans,2 + solve(i,nums,diff));
//             }
//         }
//         return ans;
//     }
// };