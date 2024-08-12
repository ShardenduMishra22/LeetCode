#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& mat) {
        if (i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0) {
            return false;
        }        
        if (i == mat.size() - 1 && j == mat[0].size() - 1) {
            return true;
        }
        
        mat[i][j] = 0;
        bool found = dfs(i + 1, j, mat) || dfs(i, j + 1, mat);
        
        return found;
    }

    bool isPossibleToCutPath(vector<vector<int>>& mat) {
        int i = 0, j = 0;
        if (!dfs(i, j, mat)) return true;
        mat[0][0] = 1;
        mat[mat.size() - 1][mat[0].size() - 1] = 1;
        return !dfs(i, j, mat);
    }
};
