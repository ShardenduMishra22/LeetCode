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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void inorder(TreeNode* root , vector<int> & ans){
        if(root == NULL){
            return;
        }
    
        inorder(root -> left , ans);
        ans.push_back(root -> val);
        inorder(root -> right , ans);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root , ans);
        int i = 0;
        int j = ans.size() - 1;
        while(i<j){
            int temp= ans[i] + ans[j];
            if(temp == k)
                return true;
            if(temp<k)
                i++;
            else
                j--;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         unordered_set<int> seen;
//         return findPair(root, k, seen);
//     }
    
//     bool findPair(TreeNode* node, int k, unordered_set<int>& seen) {
//         if (node == nullptr) {
//             return false;
//         }
        
//         if (seen.count(k - node->val)) {
//             return true;
//         }
        
//         seen.insert(node->val);
        
//         return findPair(node->left, k, seen) || findPair(node->right, k, seen);
//     }
// };
