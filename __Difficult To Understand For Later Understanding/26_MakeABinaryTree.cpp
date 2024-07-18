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


// class Solution {
// public:
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         unordered_set<int> children, parents;
//         unordered_map<int, vector<pair<int, int>>> parentToChildren;

//         for (auto& d : descriptions) {
//             int parent = d[0], child = d[1], isLeft = d[2];
//             parents.insert(parent);
//             parents.insert(child);
//             children.insert(child);
//             parentToChildren[parent].emplace_back(child, isLeft);
//         }

//         for (auto it = parents.begin(); it != parents.end();) {
//             if (children.find(*it) != children.end()) {
//                 it = parents.erase(it);
//             } else {
//                 ++it;
//             }
//         }
//         TreeNode* root = new TreeNode(*parents.begin());

//         queue<TreeNode*> queue;
//         queue.push(root);

//         while (!queue.empty()) {
//             TreeNode* parent = queue.front();
//             queue.pop();
//             for (auto& childInfo : parentToChildren[parent->val]) {
//                 int childValue = childInfo.first, isLeft = childInfo.second;
//                 TreeNode* child = new TreeNode(childValue);
//                 queue.push(child);
//                 if (isLeft == 1) {
//                     parent->left = child;
//                 } else {
//                     parent->right = child;
//                 }
//             }
//         }

//         return root;
//     }
// };