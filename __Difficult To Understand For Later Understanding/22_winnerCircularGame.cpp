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


class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
        }

        int startIndex = 0;

        while (circle.size() > 1) {
            int removalIndex = (startIndex + k - 1) % circle.size();

            circle.erase(circle.begin() + removalIndex);

            startIndex = removalIndex;
        }

        return circle.front();
    }
};

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         int ans = 0;
//         for (int i = 2; i <= n; i++) {
//             ans = (ans + k) % i;
//         }
//         return ans + 1;
//     }
// };

// class Solution {
// public:
//     int findTheWinner(int n, int k) { return winnerHelper(n, k) + 1; }

// private:
//     int winnerHelper(int n, int k) {
//         if (n == 1) return 0;
//         return (winnerHelper(n - 1, k) + k) % n;
//     }
// };

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int> circle;
//         for (int i = 1; i <= n; i++) {
//             circle.push(i);
//         }

//         while (circle.size() > 1) {
//             for (int i = 0; i < k - 1; i++) {
//                 circle.push(circle.front());
//                 circle.pop();
//             }
//             circle.pop();
//         }

//         return circle.front();
//     }
// };