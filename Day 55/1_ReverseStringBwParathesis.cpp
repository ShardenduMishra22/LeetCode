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

#define fr(i, len) for(int i=0; i < len; i++)

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


// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<int> openParenthesesIndices;
//         string result;
//         for (char currentChar : s) {
//             if (currentChar == '(') {
//                 openParenthesesIndices.push(result.length());
//             } else if (currentChar == ')') {
//                 int start = openParenthesesIndices.top();
//                 openParenthesesIndices.pop();
//                 reverse(result.begin() + start, result.end());
//             } else {
//                 result += currentChar;
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> para;
        unordered_map<int, int> pair;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                para.push(i);
            }
            if (s[i] == ')') {
                int j = para.top();
                para.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string result;

        for (int i = 0, dirn = 1; i < n; i += dirn) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dirn = -dirn;
            } else {
                result += s[i];
            }
        }

        return result;
    }
};
