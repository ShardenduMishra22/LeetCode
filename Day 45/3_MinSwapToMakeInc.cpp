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

// class Solution {
// public:
//     int minSwap(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size(), prev1, prev2, ans;
        
//         nums1.insert(nums1.begin(), -1);
//         nums2.insert(nums2.begin(), -1);
        
//         vector<int> next(2, 0), cur(2, 0);
        
//         for(int index = n; index >= 1; index--){
//             for(int swapped = 0; swapped < 2; swapped++){
//                 prev1 = nums1[index-1];
//                 prev2 = nums2[index-1];
//                 ans = INT_MAX;
//                 if(swapped) swap(prev1, prev2);

//                 if(nums1[index] > prev1 && nums2[index] > prev2){
//                     ans = min(ans, next[0]) ;
//                 }
//                 if(nums1[index]>prev2 && nums2[index]>prev1){
//                     ans = min(ans, 1 + next[1]);
//                 }
//                 cur[swapped] = ans;
//             }
//             next = cur;
//         }
//         return next[0];
//     }
// };

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        vector<vector<int> > dp(n+2, vector<int>(2, 0));
        
        for(int index = n; index >= 1; index--){
            for(int swapped = 0; swapped < 2; swapped++){
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];
                int ans = INT_MAX;
                if(swapped) swap(prev1, prev2);

                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = min(ans, dp[index+1][0]) ;
                }
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans = min(ans, 1 + dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
};

// class Solution {
// public:
//     int solve(vector<int>& nums1, vector<int>& nums2 ,  int index ,  int swapped ,  vector<vector<int>> &dp){

//         if(index ==  nums1.size()){
//             return 0 ;
//         }

//         int ans =  INT_MAX ;
//         int prev1 =  nums1[index-1] ;
//         int prev2 =  nums2[index-1 ];

//         if(dp[index][swapped] != -1){
//             return dp[index][swapped] ;
//         }

//         if(swapped){
//             swap(prev1 , prev2) ;

//         }

//         if(nums1[index] > prev1 && nums2[index] >prev2){
//             ans =  solve(nums1 , nums2 , index+1 , 0 , dp);
//         }

//         if(nums1[index] > prev2  && nums2[index] > prev1){
//             ans = min(ans ,  1 + solve(nums1 , nums2 , index+1 , 1,dp)) ;
//         }
//         return dp[index][swapped] = ans ;
//     }

//     int minSwap(vector<int>& nums1, vector<int>& nums2) {

//         nums1.insert(nums1.begin() , -1);
//         nums2.insert(nums2.begin() , -1);
//         int n =  nums1.size() ;
//         bool swapped =  0 ;

//         vector<vector<int>> dp(n , vector<int> (2,-1)) ;
//         return solve(nums1, nums2 , 1 , swapped , dp);        
//     }
// };


// class Solution {
// public:
//     int solve(vector<int>& nums1, vector<int>& nums2, int idx, bool swp) {
//         if (idx >= nums1.size())
//             return 0;

//         int ans = INT_MAX;
//         int p1 = nums1[idx - 1];
//         int p2 = nums2[idx - 1];

//         if (swp)
//             swap(p1, p2);
        
//         if (nums1[idx] > p1 && nums2[idx] > p2) {
//             ans = solve(nums1, nums2, idx + 1, false);
//         }

//         if (nums1[idx] > p2 && nums2[idx] > p1) {
//             ans = min(ans, 1 + solve(nums1, nums2, idx + 1, true));
//         }

//         return ans;
//     }

//     int minSwap(vector<int>& nums1, vector<int>& nums2) {
//         return solve(nums1, nums2, 1, false);
//     }
// };