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
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> result = {-1, -1};

//         // Initialize minimum distance to the maximum possible value
//         int minDistance = INT_MAX;

//         // Pointers to track the previous node, current node, and indices
//         ListNode* previousNode = head;
//         ListNode* currentNode = head->next;
//         int currentIndex = 1;
//         int previousCriticalIndex = 0;
//         int firstCriticalIndex = 0;

//         while (currentNode->next != nullptr) {
//             // Check if the current node is a local maxima or minima
//             if ((currentNode->val < previousNode->val &&
//                  currentNode->val < currentNode->next->val) ||
//                 (currentNode->val > previousNode->val &&
//                  currentNode->val > currentNode->next->val)) {
//                 // If this is the first critical point found
//                 if (previousCriticalIndex == 0) {
//                     previousCriticalIndex = currentIndex;
//                     firstCriticalIndex = currentIndex;
//                 } else {
//                     // Calculate the minimum distance between critical points
//                     minDistance =
//                         min(minDistance, currentIndex - previousCriticalIndex);
//                     previousCriticalIndex = currentIndex;
//                 }
//             }

//             // Move to the next node and update indices
//             currentIndex++;
//             previousNode = currentNode;
//             currentNode = currentNode->next;
//         }

//         // If at least two critical points were found
//         if (minDistance != INT_MAX) {
//             int maxDistance = previousCriticalIndex - firstCriticalIndex;
//             result = {minDistance, maxDistance};
//         }

//         return result;
//     }
// };