#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int sumOddLengthSubarrays(vector<int>& A) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            res += ((i + 1) * (n - i) + 1) / 2 * A[i];
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> generateSubarrays(vector<int>& arr) {
//         int n = arr.size();
//         int start = 0, end = 0;
//         vector<vector<int>> subarrays;

//         while (start < n) {
//             vector<int> subarray;
//             for (int i = start; i <= end; i++) {
//                 subarray.push_back(arr[i]);
//             }
//             subarrays.push_back(subarray);

//             end++;

//             if (end == n) {
//                 start++;
//                 end = start;
//             }
//         }
//         return subarrays;
//     }

//     int sumOddLengthSubarrays(vector<int>& arr) {
//         vector<vector<int>> ans = generateSubarrays(arr);
//         int sum = 0;
//         for(int i = 0; i < ans.size(); i++){
//             if(ans[i].size() & 1){ 
//                 for(int j = 0; j < ans[i].size(); j++){
//                     sum += ans[i][j]; 
//                 }
//             }
//         }
//         return sum;
//     }
// };
