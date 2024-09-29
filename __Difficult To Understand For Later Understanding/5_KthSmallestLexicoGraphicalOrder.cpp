#include<bits/stdc++.h>
using namespace std;



// TLE
// class Solution {
// public:
//         void solve(int curr, int n, vector<int>& res) {
//         if (curr > n) {
//             return;
//         }
//         res.push_back(curr);
//         for (int i = 0; i <= 9; i++) {
//             int nextNum = curr * 10 + i;
//             if (nextNum > n) {
//                 return;
//             }
//             solve(nextNum, n, res);
//         }
//     }

//     int findKthNumber(int n, int k) {
//         vector<int> res;
//         for (int i = 1; i <= 9; i++) {
//             solve(i, n, res);
//         }

//         return res[k-1];
//     }
// };