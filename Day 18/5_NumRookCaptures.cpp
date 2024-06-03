#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& b) {
        int rookRow = 0, rookCol = 0;
        bool foundRook = false;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (b[i][j] == 'R') {
                    rookRow = i;
                    rookCol = j;
                    foundRook = true;
                    break;
                }
            }
            if (foundRook) break;
        }
        
        int cnt = 0;
        int up = rookRow, down = rookRow;
        int left = rookCol, right = rookCol;

        while (up >= 0) {
            if (b[up][rookCol] == 'p') {
                cnt += 1;
                break;
            }
            if (b[up][rookCol] == 'B') {
                break;
            }
            up -= 1;
        }

        while (down < 8) {
            if (b[down][rookCol] == 'p') {
                cnt += 1;
                break;
            }
            if (b[down][rookCol] == 'B') {
                break;
            }
            down += 1;
        }

        while (left >= 0) {
            if (b[rookRow][left] == 'p') {
                cnt += 1;
                break;
            }
            if (b[rookRow][left] == 'B') {
                break;
            }
            left -= 1;
        }

        while (right < 8) {
            if (b[rookRow][right] == 'p') {
                cnt += 1;
                break;
            }
            if (b[rookRow][right] == 'B') {
                break;
            }
            right += 1;
        }

        return cnt;
    }
};
