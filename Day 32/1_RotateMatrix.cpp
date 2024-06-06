#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// class Solution {
// public:
//     void rotate(vector<vector<int>>& mat) {
//         int n = mat.size();

//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 swap(mat[i][j], mat[j][i]);
//             }
//         }

//         for(int i = 0; i < n / 2; i++) {
//             for(int j = 0; j < n; j++) {
//                 swap(mat[i][j], mat[n - 1 - i][j]);
//             }
//         }
//     }
// };
