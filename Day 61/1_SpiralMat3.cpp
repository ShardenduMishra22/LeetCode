// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
//         vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         int steps = 0;
//         int direction = 0;

//         result.push_back({rStart, cStart});

//         while (result.size() < rows * cols) {
//             if (direction == 0 || direction == 2) {
//                 steps++;
//             }
//             for (int count = 0; count < steps; count++) {
//                 rStart += directions[direction][0];
//                 cStart += directions[direction][1];

//                 if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
//                     result.push_back({rStart, cStart});
//                 }
//             }
//             direction = (direction + 1) % 4;
//         }
//         return result;
//     }
// };