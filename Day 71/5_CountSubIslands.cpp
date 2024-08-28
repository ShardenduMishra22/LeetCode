#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid2,int i,int j){
        if(i >= m || j >= n || i < 0 || j < 0 || !grid2[i][j]){
            return;
        }
        grid2[i][j] = 0;
        dfs(grid2,i + 1,j);
        dfs(grid2,i - 1,j);
        dfs(grid2,i,j + 1);
        dfs(grid2,i,j - 1);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid1[i][j] && grid2[i][j]){
                    dfs(grid2, i, j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j]){
                    cnt += 1;
                    dfs(grid2, i, j);
                }
            }
        }

        return cnt;
    }
};
