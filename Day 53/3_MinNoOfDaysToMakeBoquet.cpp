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

class Solution {
public:
    int minDays(vector<int>& blm, int m, int k) {
        if (1ll * blm.size() < 1ll * m * k) 
            return -1;
        int mn = *min_element(blm.begin(), blm.end());
        int mx = *max_element(blm.begin(), blm.end());

        while (mn < mx) {
            int mid = mn + (mx - mn) / 2;
            int buq = 0, flr = 0;

            for (int i = 0; i < blm.size(); i++) {
                if (blm[i] <= mid) {
                    flr++;
                    if (flr == k) {
                        buq++;
                        flr = 0;
                    }
                } else {
                    flr = 0;
                }
            }

            if (buq >= m) {
                mx = mid;
            } else {
                mn = mid + 1;
            }
        }

        return mn;
    }
};