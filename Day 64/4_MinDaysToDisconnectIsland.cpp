#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || vis[i][j] || mat[i][j] == 0) {
            return;
        }
        vis[i][j] = true;

        dfs(i + 1, j, mat, vis);
        dfs(i - 1, j, mat, vis);
        dfs(i, j + 1, mat, vis);
        dfs(i, j - 1, mat, vis);
    }

    int CntNoIsland(vector<vector<int>>& mat) {
        int cnt = 0;
        vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(), false));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, mat, vis);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& mat) {
        int NoIsland = CntNoIsland(mat);
        if (NoIsland != 1) {
            return 0;
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = 0;
                    NoIsland = CntNoIsland(mat);
                    if(NoIsland != 1) {
                        return 1;
                    }
                    mat[i][j] = 1;
                }
            }
        }
        return 2;
    }
};