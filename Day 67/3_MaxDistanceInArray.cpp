#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = arrays[0][0];
        int mx = arrays[0].back();
        int res = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, abs(arrays[i].back() - mn));
            res = max(res, abs(mx - arrays[i][0]));
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }

        return res;
    }
};

// Brute Force 2nd
// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arr) {
//         int res = INT_MIN;
//         for(int i=0;i<arr.size();i++){
//             for(int j=0;j<arr.size();j++){
//                 if(i == j) continue;
//                 res = max(res,arr[i][arr[i].size()-1]-arr[j][0]);
//             }
//         }
//         return res;
//     }
// };

// Brute Force 1st
// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arr) {
//         int res = INT_MIN;
//         for(int i = 0; i < arr.size(); i++) {
//             for(int j = 0; j < arr[i].size(); j++) {
//                 for(int k = 0; k < arr.size(); k++) {
//                     for(int l = 0; l < arr[k].size(); l++) {
//                         if(i == k) continue;
//                         res = max(res, abs(arr[i][j] - arr[k][l]));
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };


// [[1,5],[3,4]]
// fails on this case

// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arr) {
//         int mx = -1;
//         int mn = INT_MAX;
//         int idx;
//         for(int i=0;i<arr.size();i++){
//             if(mx < arr[i][arr[i].size()-1]){
//                 mx = arr[i][arr[i].size()-1];
//                 idx = i;
//             }
//         }
//         for(int i=0;i<arr.size();i++){
//             if(i == idx) continue;
//             if(mn > arr[i][0]){
//                 mn = arr[i][0];
//             }
//         }
//         return mx-mn;
//     }
// };