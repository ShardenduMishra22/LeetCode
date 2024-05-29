#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> sIdx(n);
        for(int i = 0; i < n; i++)
            sIdx[i] = {score[i], i};
        sort(sIdx.rbegin(), sIdx.rend());
        vector<string> ans(n);
        ans[sIdx[0].second] = "Gold Medal";
        if (n > 1) ans[sIdx[1].second] = "Silver Medal";
        if (n > 2) ans[sIdx[2].second] = "Bronze Medal";
        for(int i = 3; i < n; i++)
            ans[sIdx[i].second] = to_string(i + 1);
        return ans;
    }
};


// class Solution {
// public:
//     vector<string> findRelativeRanks(vector<int>& s) {
//         long long n = 10e6 + 1;
//         vector<long long> arr(n,0);
//         for(int i = 0;i<=n;i++){
//             arr[s[i]] = -1;
//         }
//         vector<string>ans;
//         int posn = 1;
//         for(int i=n;i>=0;i--){
//             if(arr[i] == -1){
//                 if(posn == 1){
//                     ans.push_back("Gold Medal");
//                     posn += 1;
//                 }else if(posn == 2){
//                     ans.push_back("Silver Medal");
//                     posn += 1;
//                 }else if(posn == 3){
//                     ans.push_back("Bronze Medal");
//                     posn += 1;
//                 }else{
//                     string s = to_string(i);
//                     ans.push_back(s);
//                     posn += 1;
//                 }
//             }
//         }
//         return ans;
//     }
// };