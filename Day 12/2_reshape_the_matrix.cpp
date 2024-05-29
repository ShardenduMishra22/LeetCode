#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int originalRows = mat.size();
        int originalCols = mat[0].size();
        
        if (originalRows * originalCols != r * c) {
            return mat; // Return the original matrix if reshape is not possible
        }
        
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int rl = 0, cl = 0;
        
        for (int i = 0; i < originalRows; i++) {
            for (int j = 0; j < originalCols; j++) {
                ans[rl][cl] = mat[i][j];
                cl++;
                if (cl == c) {
                    cl = 0;
                    rl++;
                }
            }
        }
        
        return ans;
    }
};
