#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _=[] () {
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

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>ans (n,0);
        vector<int>res (n,0);
        for(int i=0;i<trust.size();i+=1){
            ans[trust[i][1] - 1] += 1;
            res[trust[i][0] - 1] += 1;
        }
        for(int i=0;i<n;i++){
            if(ans[i] == n-1 && res[i] == 0){
                return i+1;
            }
        }
        return -1;
    }
};

// fails logic
// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         map<pair<int,int>,bool> m;
//         for(int i=0;i<trust.size();i+=1){
//             if(trust[i][0] > trust[i][1]){
//                 swap(trust[i][0] , trust[i][1]);
//             }
//             if(m[{trust[i][0],trust[i][1]}]){
//                 return -1;
//             }
//             m[{trust[i][0],trust[i][1]}] = true;
//         }

//         unordered_map<int,int> mp;
//         for(int i=0;i<trust.size();i+=1){
//             mp[trust[i][1]] += 1;
//         }
//         int ans = -1;
//         int mx = -1;
//         for(auto i : mp){
//             if(i.second > mx){
//                 mx = i.second;
//                 ans = i.first;
//             }
//         }
//         return ans;
//     }
// };