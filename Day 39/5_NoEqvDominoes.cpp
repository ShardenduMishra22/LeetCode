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
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         map<pair<int,int>,int> seen;
//         int result = 0;
//         for(auto& v:dominoes){
//             if(v[0] > v[1]){
//                 swap(v[0], v[1]);
//             }
//             seen[make_pair(v[0],v[1])]++;
//         }
//         for(auto& [key, value] : seen){
//             result += value*(value-1)/2;
//         }
//         // value C 2
//         return result;
//     }
// };


// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& d) {
//         int result = 0;
//         for(int i = 0; i<d.size();i++){
//             for(int j = i+1;j<d.size();j++){
//                 if((d[i][0] == d[j][0] && d[i][1] == d[j][1]) || (d[i][0] == d[j][1] && d[i][1] == d[j][0])){
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };
