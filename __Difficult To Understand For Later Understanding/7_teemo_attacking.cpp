#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        ios::sync_with_stdio(false);

        int ans = 0, n = timeSeries.size();
        int start = timeSeries[0];

        for(int i=1; i<n; ++i){
            int end = min(start+duration, timeSeries[i]);
            ans += end-start;
            start = timeSeries[i];
        }
        return ans+duration;
    }
};

// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& time, int duration) {
//         int previous = -1;
//         int answer = 0;

//         for (int i : time){
        
//             answer += duration;
//             if (previous >= i){
//                 answer = answer -abs(previous - i) -1; 
//             }
//             previous = i + duration -1;
//         }
//         return answer;

//     }
// };

// TLE
// class Solution {Day 13/3_teemo_attacking.cpp
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//         unordered_map<int, bool> m;
//         for(int i = 0; i < timeSeries.size(); i++) {
//             for(int j = timeSeries[i]; j < timeSeries[i] + duration; j++) {
//                 m[j] = true;
//             }
//         }
//         int ans = 0;
//         for(auto i : m) {
//             ans++;
//         }
//         return ans;
//     }
// };
