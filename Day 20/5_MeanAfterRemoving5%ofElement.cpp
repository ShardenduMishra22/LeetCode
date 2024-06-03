#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     double trimMean(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         int len = 5 * arr.size() / 100;
//         double sum = 0;
//         int count = 0;
//         for (int i = len; i < arr.size() - len; i++) {
//             sum += arr[i];
//             count++;
//         }
//         return sum / count;
//     }
// };


class Solution {
public:
    double trimMean(vector<int>& arr) {
        deque<int> d;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            d.push_back(arr[i]);
        }
        int len = 5 * arr.size() / 100;
        for(int i=1;i<=len;i++){
            d.pop_front();
            d.pop_back();
        }
        double x = 0,sz = 0;
        while(!d.empty()){
            x += d.front();
            sz += 1;
            d.pop_front();
        }
        return x/sz;
    }
};