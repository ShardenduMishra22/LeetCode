#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        int i=0,j=0;
        vector<vector<int>> OgMat(m, vector<int>(n, 0));
        while(i < m && j < n){
            OgMat[i][j] = min(rowSum[i],colSum[j]);

            rowSum[i] -= OgMat[i][j];
            colSum[j] -= OgMat[i][j];

            if(!rowSum[i]) i++;
            if(!colSum[j]) j++;
        }
        return OgMat;
    }
};