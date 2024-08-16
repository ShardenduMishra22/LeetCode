#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;

        int m = mat.size();
        int n = mat[0].size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        int mx = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == '1') {
                    int dig = prev[j];
                    int r = prev[j + 1];
                    int d = curr[j];

                    curr[j + 1] = 1 + min(dig, min(r, d));
                    mx = max(mx, curr[j + 1]);
                } else {
                    curr[j + 1] = 0;
                }
            }
            prev = curr;
        }

        return mx * mx;
    }
};