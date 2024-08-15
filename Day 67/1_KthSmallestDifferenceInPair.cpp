#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int SlidingWindowCount(vector<int>& nums,int mid){
        int i = 0;
        int j = 1;
        int n = nums.size();
        int PairCnt = 0;
        while(j < n){
            while(nums[j] - nums[i] > mid){
                i += 1;
            }
            PairCnt += (j-i);
            j += 1;
        }
        return PairCnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums[n-1] - nums[0];

        int res = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            int CntPair = SlidingWindowCount(nums,mid);

            if(CntPair < k){
                l = mid + 1;
            }else{
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         vector<int> dst;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 dst.push_back(abs(nums[i] - nums[j]));
//             }
//         }

//         nth_element(dst.begin(), dst.begin() + k - 1, dst.end());
//         return dst[k - 1];
//     }
// };
    
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int mx = *max_element(nums.begin(), nums.end());
//         int n = nums.size();
//         vector<int> Dst(mx + 1, 0);

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int dst = abs(nums[i] - nums[j]);
//                 Dst[dst] += 1;
//             }
//         }

//         for (int i = 0; i <= mx; i++) {
//             k -= Dst[i];
//             if (k <= 0) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

// n^2 log(k)
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         vector<pair<int,int>> v;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 v.push_back({nums[i], nums[j]});
//             }
//         }
//         priority_queue<int, vector<int>, greater<int>> p;
//         for(auto& i : v){
//             p.push(abs(i.first - i.second));
//         }
//         while(--k){
//             p.pop();
//         }
//         return p.top();
//     }
// };