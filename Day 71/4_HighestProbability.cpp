#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int st, int end) {
        vector<double> mat(n, 0.0);
        mat[st] = 1.0;  

        for(int i = 0; i < n - 1; i++) {
            bool updated = false;
            for(int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double wt = prob[j];

                if (mat[u] * wt > mat[v]) {
                    mat[v] = mat[u] * wt;
                    updated = true;
                }

                if (mat[v] * wt > mat[u]) {
                    mat[u] = mat[v] * wt;
                    updated = true;
                }
            }
            if (!updated) break;
        }      
        return mat[end];      
    }
};