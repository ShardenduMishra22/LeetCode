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

// TLE
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         if(nums.size() < 2) {
//             return false;
//         }
//         for(int i = 0; i < nums.size(); ++i) {
//             int sum = 0;
//             for(int j = i; j < nums.size(); ++j) {
//                 sum += nums[j];
//                 if (j - i + 1 >= 2 && (k == 0 ? sum == 0 : sum % k == 0)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int, int> rem;
        rem[0] = -1; 
        int curr = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            curr += nums[i];
            if (k != 0) {
                curr %= k;
            }
            
            if (rem.find(curr) != rem.end()) {
                if (i - rem[curr] > 1) {
                    return true;
                }
            } else {
                rem[curr] = i;
            }
        }
        
        return false;
    }
};
