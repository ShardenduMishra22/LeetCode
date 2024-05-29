#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]%(nums2[j]*k)==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int numberOfPairs(vector<int>& n1, vector<int>& n2, int k) {
//         int n = n1.size();
//         int m = n2.size();
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(n1[i]%(n2[j]*k) == 0){
//                     ans += 1;
//                 }
//             }
//         }
//         return ans;
//     }
// };