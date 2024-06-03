#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(int a, int b) {
            return a > b;
        }  
    };    

    int largestSumAfterKNegations(vector<int>& n, int k) {
        priority_queue<int, vector<int>, Compare> pq;
        for(int i = 0; i < n.size(); i++){
            pq.push(n[i]);
        }
        for(int i = 0; i < k; i++){
            int a = -1 * pq.top();
            pq.pop();
            pq.push(a);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};

// class Solution {
// public:
//     void solve(vector<int>& nums, int k){
//         if(k == 0){
//             return ;
//         }
//         int idx = -1,mn = INT_MAX;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] < mn){
//                 mn = nums[i];
//                 idx = i;
//             }
//         }
//         nums[idx] = -nums[idx];
//         solve(nums,k-1);
//     }

//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         solve(nums,k);
//         int sum = 0;
//         for(int i=0;i<nums.size();i++){
//             sum += nums[i];
//         }
//         return sum;
//     }
// };