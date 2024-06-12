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
    private:
    bool check(vector<int>& base, vector<int>& newbox) {
        if (newbox[0] <= base[0] && newbox[1] <= base[1] && newbox[2] <= base[2])
            return true;
        else
            return false;
    }

    int helper(int n, vector<vector<int>>& c) {
        vector<int> currrow(n + 1, 0);
        vector<int> nextrow(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int a = 0,b;
                if (j == -1 || check(c[i], c[j]))
                    a = c[i][2] + nextrow[i + 1];
                
                b = nextrow[j + 1];
                currrow[j + 1] = max(a, b);
            }
            nextrow = currrow;
        }
        return nextrow[0];
    }

    public:
    int maxHeight(vector<vector<int>>& c) {
        for (auto& a : c) {
            sort(a.begin(), a.end());
        }
        sort(c.begin(), c.end());
        return helper(c.size(), c);
    }
};