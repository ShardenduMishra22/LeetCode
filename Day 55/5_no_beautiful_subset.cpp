#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//     int CntBeautifulSbSet(vector<int>& n, int diff, int idx, int mask) {
//         if (idx == n.size()) return mask > 0 ? 1 : 0;

//         bool beauty = true;
//         for (int j = 0; j < idx && beauty; j += 1) {
//             beauty = ((1 << j) & mask) == 0 || abs(n[idx] - n[j]) != diff;
//         }

//         int skipped = CntBeautifulSbSet(n, diff, idx + 1, mask);
//         int take;
//         if (beauty) {
//             take = CntBeautifulSbSet(n, diff, idx + 1, mask + (1 << idx));
//         } else {
//             take = 0;
//         }
//         return skipped + take;
//     }

    int solve(vector<int>& n,int k,int idx,unordered_map<int,int>& m){
        if(idx >= n.size()){
            return 1;
        }
        int take = 0;
        if(!m[n[idx]-k] && !m[n[idx]+k]){
            m[n[idx]] += 1;
            take = solve(n,k,idx + 1,m);
            m[n[idx]] -= 1;
        }
        int nottake = solve(n,k,idx+1,m);

        return take + nottake;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        return solve(nums,k,0,m) - 1;
        // return CntBeautifulSbSet(nums, k, 0, 0);
    }
};