#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long cmb(int n, int k) {
        if (k > n - k) {
            k = n - k; 
        }
        long long res = 1;
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for (int i = 0; i <= rowIndex; ++i) {
            ans.push_back(cmb(rowIndex, i));
        }
        return ans;
    }
};

// class Solution {
// public:
//     int fact(int n) {
//         if (n == 0 || n == 1) {
//             return 1;
//         }
//         return n * fact(n - 1);
//     }

//     int cmb(int i, int j) {
//         return fact(i) / (fact(j) * fact(i - j));
//     }

//     vector<int> getRow(int rowIndex) {
//         vector<int> ans;
//         for (int i = 0; i <= rowIndex; ++i) {
//             ans.push_back(cmb(rowIndex, i));
//         }
//         return ans;
//     }
// };