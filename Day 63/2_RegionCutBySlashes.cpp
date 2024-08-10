#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        int pointsPerSide = gridSize + 1;
        int totalPoints = pointsPerSide * pointsPerSide;

        vector<int> parentArray(totalPoints, -1);

        for (int i = 0; i < pointsPerSide; i++) {
            for (int j = 0; j < pointsPerSide; j++) {
                if (i == 0 || j == 0 || i == pointsPerSide - 1 || j == pointsPerSide - 1) {
                    int point = i * pointsPerSide + j;
                    parentArray[point] = 0;
                }
            }
        }

        parentArray[0] = -1;
        int regionCount = 1;

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (grid[i][j] == '/') {
                    int topRight = i * pointsPerSide + (j + 1);
                    int bottomLeft = (i + 1) * pointsPerSide + j;
                    regionCount += union_sets(parentArray, topRight, bottomLeft);
                } else if (grid[i][j] == '\\') {
                    int topLeft = i * pointsPerSide + j;
                    int bottomRight = (i + 1) * pointsPerSide + (j + 1);
                    regionCount += union_sets(parentArray, topLeft, bottomRight);
                }
            }
        }

        return regionCount;
    }

private:
    int find(vector<int>& parentArray, int node) {
        if (parentArray[node] == -1) return node;
        return parentArray[node] = find(parentArray, parentArray[node]);
    }

    int union_sets(vector<int>& parentArray, int node1, int node2) {
        int parent1 = find(parentArray, node1);
        int parent2 = find(parentArray, node2);

        if (parent1 == parent2) {
            return 1;
        }

        parentArray[parent2] = parent1;
        return 0;
    }
};

 

// class Solution {
// public:
//     void dfs(vector<vector<int>>& mat, int i, int j, int n) {
//         if (i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0) {
//             return;
//         }

//         mat[i][j] = 0;

//         dfs(mat, i-1, j, n);
//         dfs(mat, i+1, j, n);
//         dfs(mat, i, j-1, n);
//         dfs(mat, i, j+1, n);
//     }

//     int NumIsland(vector<vector<int>>& mat, int n) {
//         int cnt = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] == 1) {
//                     cnt++;
//                     dfs(mat, i, j, n);
//                 }
//             }
//         }

//         return cnt;
//     }

//     int regionsBySlashes(vector<string>& grid) {
//         int n = grid.size();
//         vector<vector<int>> mat(n * 3, vector<int>(n * 3, 1));
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '/') {
//                     mat[i*3][j*3+2] = 0;
//                     mat[i*3+1][j*3+1] = 0;
//                     mat[i*3+2][j*3] = 0;
//                 } else if (grid[i][j] == '\\') {
//                     mat[i*3][j*3] = 0;
//                     mat[i*3+1][j*3+1] = 0;
//                     mat[i*3+2][j*3+2] = 0;
//                 }
//             }
//         }
//         return NumIsland(mat, n * 3);
//     }
// };