#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, string s, unordered_set<string>& st, int& n, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        
        int res = 1 + solve(i+1, s, st, n, dp);

        for (int j = i; j < n; j++) {
            string curr = s.substr(i, j-i+1);
            if (st.count(curr)) {
                res = min(res, solve(j+1, s, st, n, dp));
            }
        }

        return dp[i] = res; 
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        unordered_set<string> st;
        for (int i = 0; i < dict.size(); i++) {
            st.insert(dict[i]);
        }
        vector<int> dp(n, -1);
        return solve(0, s, st, n, dp);
    }
};


// class Solution {
// public:
//     int solve(int i,string s,unordered_set<string>& st,int& n){
//         if(i >= n){
//             return 0;
//         }
//         int res = 1 + solve(i+1,s,st,n);

//         for(int j=i;j<n;j++){
//             string curr = s.substr(i,j-i+1);
//             if(st.count(curr)){
//                 res = min(res,solve(j+1,s,st,n));
//             }
//         }

//         return res;
//     }

//     int minExtraChar(string s, vector<string>& dict) {
//         int n = s.size();
//         unordered_set<string> st;
//         for(int i=0;i<dict.size();i++){
//             st.insert(dict[i]);
//         }
//         return solve(0,s,st,n);
//     }
// };