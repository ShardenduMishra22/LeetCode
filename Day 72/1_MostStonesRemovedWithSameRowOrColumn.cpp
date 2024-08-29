#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prnt;
    vector<int> rank;
    int n;

    int find(int i) {
        if (prnt[i] == i) {
            return prnt[i];
        }
        return prnt[i] = find(prnt[i]);
    }

    void Union(int i, int j) {
        int Root_i = find(i);
        int Root_j = find(j);

        if (Root_i != Root_j) {
            if (rank[Root_i] > rank[Root_j]) {
                prnt[Root_j] = Root_i;
            } else if (rank[Root_i] < rank[Root_j]) {
                prnt[Root_i] = Root_j;
            } else {
                prnt[Root_j] = Root_i;
                rank[Root_i] += 1;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        prnt.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            prnt[i] = i;
            rank[i] = 1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i,j);
                }
            }
        }

        int grp = 0;
        for(int i=0;i<n;i++){
            if(prnt[i] == i){
                grp += 1;
            }
        }

        return (n - grp);
    }
};


// class Solution {
// public:
//     void dfs(vector<vector<int>>& stones, int i, vector<bool>& vis) {
//         vis[i] = true;
//         int r = stones[i][0];
//         int c = stones[i][1];

//         for(int j = 0; j < stones.size(); j++) {
//             if(vis[j]) continue;
//             if(stones[j][0] == r || stones[j][1] == c) {
//                 dfs(stones, j, vis);
//             }
//         }
//     }

//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         vector<bool> vis(n, false);

//         int grp = 0;
//         for(int i = 0; i < n; i++) {
//             if(vis[i]) continue;
//             dfs(stones, i, vis);
//             grp += 1;
//         }

//         return (n - grp);
//     }
// };