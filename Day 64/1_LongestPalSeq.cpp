#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n, 0));

        int maxL = 1;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                t[i][i + 1] = true;
                maxL = 2;
                idx = i;
            }
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = true;
                    if (L > maxL) {
                        maxL = L;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, maxL);
    }
};


// class Solution {
// public:
//     bool IsPal(const string& s, int i, int j, vector<vector<int>>& t) {
//         if (i >= j) {
//             return true;
//         } 
//         if (t[i][j] != -1) {
//             return t[i][j];
//         } 
//         if (s[i] == s[j]) {
//             return t[i][j] = IsPal(s, i + 1, j - 1, t);
//         } 
//         return t[i][j] = false;
//     }

//     string longestPalindrome(const string& s) {
//         int n = s.size();
//         vector<vector<int>> t(n, vector<int>(n, -1));
//         string result = "";
//         int mx_len = 0;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i; j < n; ++j) {
//                 if (IsPal(s, i, j, t) && (j - i + 1) > mx_len) {
//                     mx_len = j - i + 1;
//                     result = s.substr(i, j - i + 1);
//                 }
//             }
//         }
//         return result;
//     }
// };