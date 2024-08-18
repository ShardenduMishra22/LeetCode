#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int max_score = 0;
        int max_left = val[0];
        
        for (int i = 1; i < val.size(); i++) {
            max_score = max(max_score, max_left + val[i] - i);
            max_left = max(max_left, val[i] + i);
        }
        
        return max_score;
    }
};



// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& val) {
//         int len = val.size();
//         vector<int> l;
//         for(int i=0;i<len;i++){
//             l.push_back(val[i] + i);
//         }

//         vector<int> r;
//         for(int i=0;i<len;i++){
//             r.push_back(val[i] - i);
//         }

//         int ans = INT_MIN;
//         for(int i=0;i<len;i++){
//             for(int j=i+1;j<len;j++){
//                 ans = max(ans,l[i] + r[j]);
//             }
//         }
        
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& val) {
//         int len = val.size();
//         vector<int> l;
//         for(int i=0;i<len;i++){
//             l.push_back(val[i] + i);
//         }

//         vector<int> r;
//         for(int i=0;i<len;i++){
//             r.push_back(val[i] - i);
//         }

//         int ans = INT_MIN;
//         for(int i=0;i<len;i++){
//             for(int j=i+1;j<len;j++){
//                 ans = max(ans,l[i] + r[j]);
//             }
//         }
        
//         return ans;
//     }
// };