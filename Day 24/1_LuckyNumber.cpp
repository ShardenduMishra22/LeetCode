#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int maxMin=INT_MIN;
        int minMax=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            int mini=INT_MAX;
            for(int j=0;j<matrix[i].size();j++){
                mini=min(mini,matrix[i][j]);
            }
            maxMin=max(mini,maxMin);
        }
        for(int j=0;j<matrix[0].size();j++){
            int maxi=INT_MIN;
            for(int i=0;i<matrix.size();i++){
                maxi=max(maxi,matrix[i][j]);
            }
            minMax=min(minMax,maxi);
        }
        if(maxMin!=minMax) return {};
        return {maxMin};
    }
};

// Fails If No Answer Exists Just Do It for the transpose of the matrix too
// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& mat) {
//         int b = INT_MAX;
//         for(int i=0;i<mat[0].size();i++){
//             int a = INT_MIN;
//             for(int j=0;j<mat.size();j++){
//                 a = max(a,mat[j][i]);
//             }
//             b = min(b,a);
//         }
//         return {b};
//     }
// };