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

// class Solution {
// public:
//     bool validMountainArray(vector<int>& arr) {
//         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//         int n = arr.size();
//         if (n < 3)
//             return false;

//         int i = 1;
//         for (; i < n; i++) {
//             if (arr[i] == arr[i - 1])
//                 return false;
//             else if (arr[i] < arr[i - 1])
//                 break;
//         }

//         if (i == n || i == 1)
//             return false;

//         for (; i < n; i++) {
//             if (arr[i] == arr[i - 1])
//                 return false;
//             else if (arr[i] > arr[i - 1])
//                 return false;
//         }

//         return true;
//     }
// };


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) 
          return false;

        int idx = 0;

        while (idx + 1 < arr.size() && arr[idx] < arr[idx + 1]) {
            idx++;
        }

        if (idx == 0 || idx == arr.size() - 1) {
            return false;
        }

        while (idx + 1 < arr.size() && arr[idx] > arr[idx + 1]) {
            idx++;
        }   
        return idx == arr.size() - 1;
    }
};