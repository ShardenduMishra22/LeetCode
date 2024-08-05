#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& ts, int durn) {
//         set<int> st;
//         for(int i = 0; i < ts.size(); i++) {
//             int num = ts[i];
//             int temp = durn;
//             while(temp--) {
//                 st.insert(num);
//                 num += 1;
//             }
//         }
//         return st.size();
//     }
// };

class Solution{
public:
    int findPoisonedDuration(vector<int>& ts, int durn) {
        int total = 0;
        int end = 0;
        for (int t : ts) {
            if (t >= end) {
                total += durn;
            } else {
                total += t + durn - end;
            }
            end = t + durn;
        }
        return total;
    }
};