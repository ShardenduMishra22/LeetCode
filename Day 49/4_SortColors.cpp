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

// Wrong Ans
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         return sort(nums.begin(),nums.end());
//     }
// };

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int i = 0, j = nums.size() - 1;

//         while (i < j) {
//             if (nums[j] != 2 && nums[i] == 2) {
//                 swap(nums[j--], nums[i++]);
//             } else if (nums[j] == 2) {
//                 j--;
//             } else if (nums[i] != 2) {
//                 i++;
//             }
//         }

//         i = 0;
//         while (i < j) {
//             if (nums[j] == 0 && nums[i] == 1) {
//                 swap(nums[j--], nums[i++]);
//             } else if (nums[j] != 0) {
//                 j--;
//             } else if (nums[i] == 0) {
//                 i++;
//             }
//         }
//     }
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        while(m <= r){
            if(nums[m] == 0){
                swap(nums[m],nums[l]);
                l += 1;m += 1;
            }else if(nums[m] == 1){
                m += 1;
            }else if(nums[m] == 2){
                swap(nums[m],nums[r]);
                r -= 1;
            }
        }
    }
};