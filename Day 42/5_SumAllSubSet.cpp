#include <bits/stdc++.h>
using namespace std;

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
typedef vector<vector<bool>> vvint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvint;

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

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }

private:
    int solve(vector<int>& nums, int idx, int curr) {
        if (idx == nums.size()) {
            return curr;
        }
        
        int inc = solve(nums, idx + 1, curr ^ nums[idx]);
        int exc = solve(nums, idx + 1, curr);
        
        return inc + exc;
    }
};


// class Solution {
// public:
//     int subsetXORSum(vector<int>& nums) {
//         int n = nums.size();
//         int totalSum = 0;
//         for (int i = 0; i < (1 << n); i++) {
//             int curr = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i & (1 << j)) {
//                     curr ^= nums[j];
//                 }
//             }
//             totalSum += curr;
//         }
//         return totalSum;
//     }
// };


// void printSubsets(vector<int>& nums) {
//     int n = nums.size();
    
//     // Total number of subsets is 2^n
//     int totalSubsets = 1 << n;

//     // Iterate over all possible subsets
//     for (int mask = 0; mask < totalSubsets; ++mask) {
//         cout << "{ ";
//         for (int i = 0; i < n; ++i) {
//             // Check if the i-th element is included in the current subset
//             if (mask & (1 << i)) {
//                 cout << nums[i] << " ";
//             }
//         }
//         cout << "}\n";
//     }
// }

// int main() {
//     vector<int> nums = {1, 2, 3};
//     printSubsets(nums);
//     return 0;
// }
