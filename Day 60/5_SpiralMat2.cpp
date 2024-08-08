#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int Rst = 0;
        int Cst = 0;
        int Rend = mat.size() - 1;
        int Cend = mat[0].size() - 1;
        int temp = 1;
        while (Rst <= Rend && Cst <= Cend) {
            for (int i = Cst; i <= Cend; i++) {
                mat[Rst][i] = temp;
                temp += 1; 
            }
            Rst++;
            for (int i = Rst; i <= Rend; i++) {
                mat[i][Cend] = temp;
                temp += 1;
            }
            Cend--;
            if (Rst <= Rend) {
                for (int i = Cend; i >= Cst; i--) {
                    mat[Rend][i] = temp;
                    temp += 1;
                }
                Rend--;
            }
            if (Cst <= Cend) {
                for (int i = Rend; i >= Rst; i--) {
                    mat[i][Cst] = temp;
                    temp += 1;
                }
                Cst++;
            }
        }
        return mat;
    }
};