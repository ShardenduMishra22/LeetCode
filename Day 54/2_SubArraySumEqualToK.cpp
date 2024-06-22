#include <bits/stdc++.h>
using namespace std;

#pragma GCC target   ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("Ofast")

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define frb(i, len) for(int i=len-1; i =0; i--)
#define fr(i, len) for(int i=0; i < len; i++)

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

c_int MOD=1e9 + 7;
c_int Mx_row=100;
c_int Mx_col=100;
int size_stack=0;
int InvrsnCnt=0;
int size_arr=0;
int size_ll=0;
int top=-1;


// brute force approach 
// TLE
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int x) {
//         int n = nums.size();
//         int cnt  = 0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 int sum =0;
//                 for(int k=i;k<=j;k++){
//                     sum += nums[k];
//                 }
//                 if(sum == x){
//                     cnt += 1;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

// O(n^2) but still poor approach 
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int x) {
//         int cnt = 0;
//         for(int i=0;i<nums.size();i++){
//             int sum = 0;
//             for(int j=i;j<nums.size();j++){
//                 sum += nums[j];
//                 if(sum == x){
//                     cnt += 1;
//                }
//             }
//         }
//         return cnt;
//     }
// };

// O(n) using hashmap
// [1,1,1,1,1,2,3,4,1,2,3,4]
class Solution {
public:
    int subarraySum(vector<int>& nums, int x) {
        unordered_map<int,int> m;
        int cnt = 0,sum = 0;
        m[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(m.find(sum-x) != m.end()){
                cnt += m[sum-x];
            }

            m[sum] += 1;
        }
        return cnt;
    }
};