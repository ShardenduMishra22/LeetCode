#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        vector<pair<int, int>> arr(env.size());
        for (int i = 0; i < env.size(); i++) {
            arr[i] = {env[i][0], env[i][1]};
        }

        sort(arr.begin(), arr.end(), comp);
        
        vector<int> dp;
        for (int i = 0; i < env.size(); i++) {
            int height = arr[i].second;
            int idx = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            
            if (idx == dp.size()) {
                dp.push_back(height);
            } else {
                dp[idx] = height;
            }
        }
        return dp.size();
    }
};

// class Solution {
// public:
//     static bool comp(pair<int,int> &a,pair<int,int>&b){
//         if(a.first==b.first){
//             return a.second>b.second;
//         }
//         return a.first<b.first;
//     }

//     int maxEnvelopes(vector<vector<int>>& env) {
//         vector<pair<int,int>>arr(env.size());
//         for(int i = 0 ; i < env.size() ; i++){
//             arr[i] = {env[i][0],env[i][1]};
//         }

//         sort(arr.begin(),arr.end(),comp);
        
//         vector<int>dp(env.size());
//         int ans = 0;

//         for(int i = 0 ; i < env.size() ; i++){
//             int l = 0,h = ans;
//             while(l<h){
//                 int m = l +(h - l) / 2;
                
//                 if(dp[m] < arr[i].second) 
//                     l = m + 1;
//                 else 
//                     h = m;
//             }
//             dp[l] = arr[i].second;
//             if(l == ans) 
//                 ans++;
//         }
//         return ans;
//     }
// };