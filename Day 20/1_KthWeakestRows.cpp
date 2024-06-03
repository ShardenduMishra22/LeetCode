#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> soldierCount; 
        vector<int> result;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) count++;
            }
            soldierCount.push_back(make_pair(count, i)); 
        }

        sort(soldierCount.begin(), soldierCount.end());

        for (int i = 0; i < k; i++) {
            result.push_back(soldierCount[i].second); 
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         int m = mat.size();
//         int n = mat[0].size();
//         vector<pair<int, int>> power;

//         for (int i = 0; i < m; i++) {
//             int pwr = 0;
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] == 1) {
//                     pwr++;
//                 } else {
//                     break; 
//                 }
//             }
//             power.push_back({pwr, i});
//          }

       
        // sort(power.begin(), power.end(), [](pair<int, int>& a, pair<int, int>& b) {
        //     if (a.first == b.first) {
        //         return a.second < b.second;
        //     }
        //     return a.first < b.first;
        // });

//         vector<int> result;
//         for (int i = 0; i < k; i++) {
//             result.push_back(power[i].second);
//         }

//         return result;
//     }
// };
