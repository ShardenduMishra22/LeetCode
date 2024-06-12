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
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob   = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        vector<int> ans;
        
        int diff = (sumBob - sumAlice) / 2;
        
        unordered_set<int> setAliceSizes(aliceSizes.begin(), aliceSizes.end());
        
        for (int bobItem : bobSizes) {
            if (setAliceSizes.count(bobItem - diff) > 0) {
                ans.push_back(bobItem - diff);
                ans.push_back(bobItem);
                return ans;
            }
        }
        
        return ans;
    }
};


// class Solution {
// public:
//     int binarySearch(const vector<int>& b, int x, int sum1, int sum2) {
//         int left = 0;
//         int right = b.size() - 1;
        
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             int v = sum1 + b[mid] - x;
//             int c = sum2 + x - b[mid];
            
//             if (v == c)
//                 return mid;
//             else if (v < c)
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
        
//         return -1;
//     }
    
//     vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
//         sort(b.begin(), b.end());
        
//         int sum1 = accumulate(a.begin(), a.end(), 0);
//         int sum2 = accumulate(b.begin(), b.end(), 0);
        
//         vector<int> ans(2);
        
//         for (int i = 0; i < a.size(); ++i) {
//             int v = binarySearch(b, a[i], sum1, sum2);
//             if (v != -1) {
//                 ans[0] = a[i];
//                 ans[1] = b[v];
//                 break;
//             }
//         }
        
//         return ans;
//     }
// };