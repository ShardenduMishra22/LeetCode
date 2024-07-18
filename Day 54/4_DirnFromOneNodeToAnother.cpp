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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* LCA(TreeNode* node, int v1, int v2) {
        if (!node) {
            return nullptr;
        }
        if (node->val == v1 || node->val == v2) {
            return node;
        }

        TreeNode* left  = LCA(node->left, v1, v2);
        TreeNode* right = LCA(node->right, v1, v2);

        if (left && right) {
            return node;
        }
        return left ? left : right;
    }

    bool FindPath(TreeNode* node, int trgt, string& path) {
        if (!node) {
            return false;
        }
        if (node->val == trgt) {
            return true;
        }

        path.push_back('L');
        if (FindPath(node->left, trgt, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (FindPath(node->right, trgt, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int start, int dest) {
        TreeNode* lca = LCA(root, start, dest);

        string pathStart = "", pathEnd = "";

        FindPath(lca, start, pathStart);
        FindPath(lca, dest, pathEnd);

        string dirn = string(pathStart.length(), 'U') + pathEnd;

        return dirn;
    }
};
