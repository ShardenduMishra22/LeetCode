#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int Rst = 0;
        int Cst = 0;
        int Rend = mat.size() - 1;
        int Cend = mat[0].size() - 1;
        vector<int> ans;
        while (Rst <= Rend && Cst <= Cend) {
            for (int i = Cst; i <= Cend; i++) {
                ans.push_back(mat[Rst][i]);
            }
            Rst++;
            for (int i = Rst; i <= Rend; i++) {
                ans.push_back(mat[i][Cend]);
            }
            Cend--;
            if (Rst <= Rend) {
                for (int i = Cend; i >= Cst; i--) {
                    ans.push_back(mat[Rend][i]);
                }
                Rend--;
            }
            if (Cst <= Cend) {
                for (int i = Rend; i >= Rst; i--) {
                    ans.push_back(mat[i][Cst]);
                }
                Cst++;
            }
        }
        return ans;
    }
};
