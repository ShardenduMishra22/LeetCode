#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string s, int idx, unordered_map<string, bool>& m, vector<int>& dp) {
        if (idx == s.size()) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        for (int i = idx; i < s.size(); i++) {
            if (m[s.substr(idx, i + 1 - idx)] && solve(s, i + 1, m, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wrds) {
        unordered_map<string, bool> m;
        for (auto& i : wrds) {
            m[i] = true;
        }
        vector<int> dp(s.size(), -1);
        return solve(s, 0, m, dp);
    }
};

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool solve(string s, int idx, unordered_map<string, bool>& m) {
//         if (idx == s.size()) {
//             return true;
//         }

//         for (int i = idx; i < s.size(); i++) {
//             if (m[s.substr(idx, i + 1 - idx)] && solve(s, i + 1, m)) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     bool wordBreak(string s, vector<string>& wrds) {
//         unordered_map<string, bool> m;
//         for (auto i : wrds) {
//             m[i] = true;
//         }
//         int idx = 0;
//         return solve(s, idx, m);
//     }
// };
