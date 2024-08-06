#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     void DFS(int ancestor, unordered_map<int, vector<int>>& adj, int curr, vector<vector<int>>& res) {
//         for(int &ngbr : adj[curr]){
//             if(res[ngbr].empty() || res[ngbr].back() != ancestor){
//                 res[ngbr].push_back(ancestor);
//                 DFS(ancestor, adj, ngbr, res);
//             }
//         }

//     }

//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> res(n);
//         unordered_map<int, vector<int>> adj;

//         for(vector<int>& vec : edges) {
//             int u = vec[0];
//             int v = vec[1];
//             adj[u].push_back(v);
//         }

//         for(int i = 0; i < n; i++) {
//             int ancestor = i;
//             DFS(ancestor, adj, i, res);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     void DFS(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
//         visited[u] = true;
//         for(int &v : adj[u]) {
//             if(visited[v] != true) {
//                 DFS(v, adj, visited);
//             }
//         }
//     }

//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> result;
//         unordered_map<int, vector<int>> adj;

//         for(vector<int>& vec : edges){ 
//             int u = vec[0];
//             int v = vec[1];
//             adj[v].push_back(u);
//         }
//         for(int u = 0; u < n; u++) {
//             vector<int> ancestors;
//             vector<bool> visited(n, false);
//             DFS(u, adj, visited);
//             for(int i = 0; i < n; i++) {
//                 if(i == u) continue;
                
//                 if(visited[i] == true) {
//                     ancestors.push_back(i);
//                 }
//             }
//             result.push_back(ancestors);
//         }      
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(vector<int>& vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v); 
            indegree[v]++;
        }
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topoOrder;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            topoOrder.push_back(curr);

            for(int &v : adj[curr]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        vector<unordered_set<int>> vec(n);

        for(int &node : topoOrder) {
            for(int &v : adj[node]) {
                vec[v].insert(node); 
                vec[v].insert(vec[node].begin(), vec[node].end()); 
            }
        }
        for(int i = 0; i < n; i++) {
            result[i] = vector<int>(vec[i].begin(), vec[i].end());
            sort(result[i].begin(), result[i].end());
        }      
        return result;
    }
};