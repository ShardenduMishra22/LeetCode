#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& n) {
        int i_first=-1,mx=INT_MIN;
        for(int i=0;i<n.size();i++){
            if(n[i] > mx){
                mx = n[i];
                i_first = i;
            }
        }
        int mx_scnd=INT_MIN;
        for(int i=0;i<n.size();i++){
            if(i == i_first)
                continue;
            mx_scnd = max(mx_scnd,n[i]);
        }
        if(mx_scnd*2 > mx){
            return -1;
        }
        return i_first;
    }
};

// Fails in case of array like [0,0,3,2]
// class Solution {
// public:
//     int dominantIndex(vector<int>& n) {
//         long long mx_first = INT_MIN,mx_scnd = INT_MIN;
//         long long idx_first , idx_second;
//         for(int i=0;i<n.size();i++){
//             if(n[i] > mx_first){
//                 mx_scnd = mx_first;
//                 idx_second = idx_first;
//                 mx_first = n[i];
//                 idx_first = i;
//             }
//         }
//         if(mx_first < 2*mx_scnd) 
//             return -1;
//         return idx_first;

//     }
// };
