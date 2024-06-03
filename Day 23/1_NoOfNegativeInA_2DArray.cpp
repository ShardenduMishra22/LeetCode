#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int row = 0,col = m - 1;
        int cnt=0; 
        while(row < n && col >= 0){
            if(grid[row][col] >= 0){
                row += 1;
            }else{
                cnt += n-row;
                col -= 1;
            }
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int count=0;
//         for(int i=0; i<grid.size(); ++i){
//             for(int j=grid[0].size()-1; j>=0; --j){
//                 if(grid[i][j] < 0)
//                     count++;
//                 else
//                     break;
//             }
//         }
//         return count;
//     }
// };