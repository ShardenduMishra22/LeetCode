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

#define frw(i, len) for(ll i = 0   ; i < len ; i++)
#define frb(i, len) for(ll i = len ; i >= 0  ; i--)

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
    int BinExpo(int a, int b, int M) {
        a %= M; // Take a modulo M to ensure a is within the bounds of M
        int ans = 1; // Initialize the answer to 1
        while (b > 0) { // Loop until b becomes 0
            if (b & 1) { // If b is odd
                ans = (ans * a * 1LL) % M; // Multiply ans by a and take modulo M
            }
            a = (a * a * 1LL) % M; // Square a and take modulo M
            b >>= 1; // Right shift b by 1 (equivalent to dividing b by 2)
        }
        return ans; // Return the result
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) { // If the vector b is empty
            return 1; // Return 1 as any number to the power of 0 is 1
        }

        int bmod = 0; // Initialize bmod to 0
        for (auto i : b) { // Iterate through each digit in the vector b
            bmod = (bmod * 10 + i) % 1140; 
            // 1140 comes from Eulers Totient Function phi(n) = n Summation(1-1/p) 
            // where p is prime factors of n
            // For in these case n = 1337
            // p = 7, 191
            // phi(1337) = 1337 * (1 - 1/7) * (1 - 1/191) = 1140
        }

        bmod = (bmod == 0) ? 1140 : bmod;
        return BinExpo(a, bmod, 1337);
    }
};
