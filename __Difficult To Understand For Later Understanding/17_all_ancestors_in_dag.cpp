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
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adjacencyList(n);
//         for (int i = 0; i < n; i++) {
//             adjacencyList[i] = {};
//         }

//         vector<int> indegree(n, 0);
//         for (auto& edge : edges) {
//             int from = edge[0];
//             int to = edge[1];
//             adjacencyList[from].push_back(to);
//             indegree[to]++;
//         }

//         queue<int> nodesWithZeroIndegree;
//         for (int i = 0; i < indegree.size(); i++) {
//             if (indegree[i] == 0) {
//                 nodesWithZeroIndegree.push(i);
//             }
//         }

//         vector<int> topologicalOrder;
//         while (!nodesWithZeroIndegree.empty()) {
//             int currentNode = nodesWithZeroIndegree.front();
//             nodesWithZeroIndegree.pop();
//             topologicalOrder.push_back(currentNode);

//             for (int neighbor : adjacencyList[currentNode]) {
//                 indegree[neighbor]--;
//                 if (indegree[neighbor] == 0) {
//                     nodesWithZeroIndegree.push(neighbor);
//                 }
//             }
//         }

//         vector<vector<int>> ancestorsList(n);
//         vector<set<int>> ancestorsSetList(n);

//         for (int node : topologicalOrder) {
//             for (int neighbor : adjacencyList[node]) {
//                 ancestorsSetList[neighbor].insert(node);
//                 ancestorsSetList[neighbor].insert(
//                     ancestorsSetList[node].begin(),
//                     ancestorsSetList[node].end());
//             }
//         }

//         for (int i = 0; i < ancestorsList.size(); i++) {
//             ancestorsList[i].assign(ancestorsSetList[i].begin(),
//                                     ancestorsSetList[i].end());
//             sort(ancestorsList[i].begin(), ancestorsList[i].end());
//         }

//         return ancestorsList;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adjacencyList(n);

//         for (auto& edge : edges) {
//             int from = edge[0];
//             int to = edge[1];
//             adjacencyList[to].push_back(from);
//         }

//         vector<vector<int>> ancestorsList;

//         for (int i = 0; i < n; i++) {
//             vector<int> ancestors;
//             unordered_set<int> visited;
//             findChildren(i, adjacencyList, visited);
//             for (int node = 0; node < n; node++) {
//                 if (node == i) continue;
//                 if (visited.find(node) != visited.end())
//                     ancestors.push_back(node);
//             }
//             ancestorsList.push_back(ancestors);
//         }

//         return ancestorsList;
//     }

// private:
//     void findChildren(int currentNode, vector<vector<int>>& adjacencyList,
//         unordered_set<int>& visitedNodes) {
//         visitedNodes.insert(currentNode);

//         for (int neighbour : adjacencyList[currentNode]) {
//             if (visitedNodes.find(neighbour) == visitedNodes.end()) {
//                 findChildren(neighbour, adjacencyList, visitedNodes);
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), ans(n);

        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            dfs(adj,ans,i,i);
        }
        
        return ans;
    }
    void dfs(vector<vector<int>>& adj, vector<vector<int>>& ans, int& parent, int& child) {
        for (auto& ch: adj[child]) {
            if (ans[ch].size() == 0 || ans[ch].back() != parent) {
                ans[ch].push_back(parent);
                dfs(adj,ans,parent,ch);
            }
            
        }
    }
};