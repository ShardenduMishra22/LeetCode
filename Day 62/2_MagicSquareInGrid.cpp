#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        string sequence = "2943816729438167";
        string sequenceReversed = "7618349276183492";

        string border = "";
        vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};

        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + (i % 3)];
            border += to_string(num);
        }

        return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
               (sequence.find(border) != string::npos || sequenceReversed.find(border) != string::npos));
    }
};

// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& mat) {
//         int ans = 0;
//         int m = mat.size();
//         int n = mat[0].size();
//         for (int row = 0; row + 2 < m; row++) {
//             for (int col = 0; col + 2 < n; col++) {
//                 if (solve(mat, row, col)) {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }

// private:
//     bool solve(vector<vector<int>>& mat, int row, int col) {
//         vector<bool> seen(9,false);
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 int num = mat[row + i][col + j];
//                 if (num < 1 || num > 9) return false;
//                 if (seen[num-1]) return false;
//                 seen[num-1] = true;
//             }
//         }

//         int dig1 = mat[row][col] + mat[row + 1][col + 1] + mat[row + 2][col + 2];
//         int dig2 = mat[row + 2][col] + mat[row + 1][col + 1] + mat[row][col + 2];

//         if (dig1 != dig2) return false;

//         int row1 = mat[row][col] + mat[row][col + 1] + mat[row][col + 2];
//         int row2 = mat[row + 1][col] + mat[row + 1][col + 1] + mat[row + 1][col + 2];
//         int row3 = mat[row + 2][col] + mat[row + 2][col + 1] + mat[row + 2][col + 2];

//         if (!(row1 == dig1 && row2 == dig1 && row3 == dig1)) {
//             return false;
//         }

//         int col1 = mat[row][col] + mat[row + 1][col] + mat[row + 2][col];
//         int col2 = mat[row][col + 1] + mat[row + 1][col + 1] + mat[row + 2][col + 1];
//         int col3 = mat[row][col + 2] + mat[row + 1][col + 2] + mat[row + 2][col + 2];

//         if (!(col1 == dig1 && col2 == dig1 && col3 == dig1)) {
//             return false;
//         }

//         return true;
//     }
// };